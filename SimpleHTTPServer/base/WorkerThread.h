#include <utility>

//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_WORKERTHREAD_H
#define SIMPLEHTTPSERVER_WORKERTHREAD_H


#include <cstddef>
#include <string>
#include "ConditionLock.h"
#include "EventLoop.h"
#include "HTTPTask.h"

namespace SimpleServer {
    class WorkerThread {
    public:
        WorkerThread() = default;

        explicit WorkerThread(size_t i, ConditionLock *lock, EventLoop <HTTPTask> *loop)
                : id(i), lock(lock), loop(loop) {
        };

        void start() {
            isRunning = true;
            while (isRunning) {
                lock->wait();
                HTTPTask task;
                if (!loop->TryPop(task)) {
                    continue;
                }
                task.Run();
            }
        }
        void resetNull(){
            lock= nullptr;
            loop= nullptr;
        }

        void stop() {
            isRunning = false;
        }
        virtual ~WorkerThread() = default;

    private:
        size_t id;
        ConditionLock *lock;
        bool isRunning;
        EventLoop <HTTPTask> *loop;
    };
}

#endif //SIMPLEHTTPSERVER_WORKERTHREAD_H
