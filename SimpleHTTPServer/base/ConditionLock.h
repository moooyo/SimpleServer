//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_CONDITIONLOCK_H
#define SIMPLEHTTPSERVER_CONDITIONLOCK_H


#include <zconf.h>
#include <pthread.h>

class ConditionLock {
public:
    explicit ConditionLock (){
        pthread_mutex_init(&__mutex,NULL);
        pthread_cond_init(&__condition,NULL);
    }
    void wait(){
        pthread_cond_wait(&__condition,&__mutex);
    }
    void notify(){
        pthread_cond_signal(&__condition);
    }
    void notifyAll(){
        pthread_cond_broadcast(&__condition);
    }
    ~ConditionLock(){
        pthread_mutex_destroy(&__mutex);
        pthread_cond_destroy(&__condition);
    }
private:
    pthread_mutex_t __mutex;
    pthread_cond_t __condition;
};


#endif //SIMPLEHTTPSERVER_CONDITIONLOCK_H
