//
// Created by lengyu on 2019/3/2.
//
#include <Cache.h>
#include "nethelp.h"
#include "Logger.h"
#include "Logging.h"
#include "ListenServer.h"
#include "CurrentThread.h"
#include "WorkerThread.h"
#include "syscall.h"
#include "GlobalConfig.h"

namespace SimpleServer {
    const int LISTEN_PORT = 8005;
    const int MAX_WORKER_SIZE = 7;

    void *WorkerFunction(void *args) {
        __threadName = __ThreadNameStorage[0];
        __threadStringSize = strlen(__threadName);

        LOG_INFO << "Start Worker Thread";
        auto *workerThread = (WorkerThread *) args;
        workerThread->start();
        return nullptr;
    }

    void *LoggerFunction(void *args) {
        __threadName = __ThreadNameStorage[2];
        __threadStringSize = strlen(__threadName);

        LOG_INFO << "Start Log Thread";
        Logger::LoggerThread thread;
        thread.Start();
        return nullptr;
    }

    int main() {
        __threadName = __ThreadNameStorage[1];
        __threadStringSize = strlen(__threadName);

        LOG_INFO << "Start Server";
        EventLoop<HTTPTask> loop;
        Mutex __lock;
        ConditionLock conditionLock(__lock);
        int listenfd = tool::OpenIpv4Listen(LISTEN_PORT);
        ListenServer server(listenfd, 256, &conditionLock, &loop);
        WorkerThread workers[MAX_WORKER_SIZE];
        pthread_t tid;
        pthread_create(&tid, nullptr, LoggerFunction, nullptr);
        for (size_t i = 0; i < MAX_WORKER_SIZE; ++i) {
            WorkerThread work(i, &conditionLock, &loop);
            workers[i] = std::move(work);
            pthread_create(&tid, nullptr, WorkerFunction, (void *) (&workers[i]));
        }
        server.StartListenning();
        return 0;
    }
}

int main() {
    SimpleServer::Config::parseConfig();
    return SimpleServer::main();
}
