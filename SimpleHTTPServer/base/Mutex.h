//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_MUTEX_H
#define SIMPLEHTTPSERVER_MUTEX_H


#include <zconf.h>
#include <pthread.h>
namespace SimpleServer {
    class Mutex {
    public:
        Mutex() :__holder(0)
        {
            pthread_mutex_init(&this->__mutex,NULL);
        }
        ~Mutex(){
            pthread_mutex_destroy(&this->__mutex);
        }
        bool isLockedByThisThread()
        {
            return true;
        }
        void lock()
        {
            pthread_mutex_lock(&this->__mutex);
        }
        void unlock()
        {
            pthread_mutex_unlock(&this->__mutex);
        }
    private:
        pthread_mutex_t __mutex;
        pid_t __holder;
    };
}

#endif //SIMPLEHTTPSERVER_MUTEX_H
