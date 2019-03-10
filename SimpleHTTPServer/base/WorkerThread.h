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
        WorkerThread()= default;
        explicit WorkerThread(int i,ConditionLock *lock,EventLoop<HTTPTask> *loop,std::string name="worker"):id(i),name(name),lock(lock),loop(loop){
        };
        void start(){
            isRunning=true;
            while(isRunning){
                lock->wait();
                HTTPTask task;
                if(!loop->TryPop(task))
                {
                    continue;
                }
                task.Run();
            }
        }
        void stop(){
            isRunning=false;
        }

    private:
        size_t id;
        std::string name;
        ConditionLock *lock;
        bool isRunning;
        EventLoop<HTTPTask> *loop;
    };
}

#endif //SIMPLEHTTPSERVER_WORKERTHREAD_H
