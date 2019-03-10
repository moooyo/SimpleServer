//
// Created by lengyu on 2019/3/2.
//
#include "../tool/nethelp.h"
#include "ListenServer.h"
#include "WorkerThread.h"

namespace SimpleServer{
    const int LISTEN_PORT=8005;
    const int MAX_WORKER_SIZE=4;
    void* WorkerFunction(void *args)
    {
        WorkerThread *workerThread=(WorkerThread *)args;
        workerThread->start();
        return 0;
    }
    int main()
    {
        EventLoop<HTTPTask> loop;
        ConditionLock conditionLock;
        int listenfd=tool::OpenIpv4Listen(LISTEN_PORT);
        ListenServer server(listenfd,256,&conditionLock,&loop);
        WorkerThread workers[MAX_WORKER_SIZE];
        for(int i=0;i<MAX_WORKER_SIZE;++i)
        {
            pthread_t tid;
            WorkerThread work(i,&conditionLock,&loop);
            workers[i]=std::move(work);
            pthread_create(&tid,NULL,WorkerFunction,(void *)(&workers[i]));
        }
        server.StartListenning();
        return 0;
    }
}
int main()
{
    return SimpleServer::main();
}
