//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_EVENTLOOP_H
#define SIMPLEHTTPSERVER_EVENTLOOP_H

#include "Task.h"
#include "Mutex.h"
#include "MutexLockGuard.h"
#include <queue>
namespace SimpleServer {
    template <class T>
    class EventLoop {
    public:
        EventLoop(){}
        void push(T &task){
            MutexLockGuard lock(__mutex);
            queue.push(task);
        }
        bool TryPop(T &destination)
        {
            MutexLockGuard lock(__mutex);
            if(queue.empty())
            {
                return false;
            }
            destination=std::move(queue.front());
            queue.pop();
            return true;
        }
    private:
        std::queue<T> queue;
        Mutex __mutex;
    };
}

#endif //SIMPLEHTTPSERVER_EVENTLOOP_H
