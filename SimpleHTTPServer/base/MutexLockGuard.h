//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_MUTEXGUARDLOCK_H
#define SIMPLEHTTPSERVER_MUTEXGUARDLOCK_H

#include "Mutex.h"
namespace SimpleServer {
    class MutexLockGuard {
    public:
        explicit MutexLockGuard(Mutex &mutex): __mutex(mutex){
            __mutex.lock();
        }
        MutexLockGuard()= delete;

        ~MutexLockGuard(){
            __mutex.unlock();
        }

    private:
        Mutex __mutex;
    };
}
#define MutexLockGuard(x) error "Missing guard object name"
#endif //SIMPLEHTTPSERVER_MUTEXGUARDLOCK_H
