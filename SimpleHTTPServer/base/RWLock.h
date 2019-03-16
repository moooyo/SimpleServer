//
// Created by lengyu on 2019/3/15.
//

#ifndef SIMPLEHTTPSERVER_RWMUTEX_H
#define SIMPLEHTTPSERVER_RWMUTEX_H

#include <zconf.h>
#include <pthread.h>

class RWLock{
public:
    RWLock(){
        pthread_rwlock_init(&this->rwlock,NULL);
    }
    void ReadLock(){
        pthread_rwlock_rdlock(&this->rwlock);
    }
    void WriteLock(){
        pthread_rwlock_wrlock(&this->rwlock);
    }
    void Unlock(){
        pthread_rwlock_unlock(&this->rwlock);
    }
    ~RWLock(){
        pthread_rwlock_destroy(&this->rwlock);
    }
private:
    pthread_rwlock_t rwlock;

};
class ReadLockGuard{
public:
    ReadLockGuard() = delete;
    explicit  ReadLockGuard(RWLock &lock):__lock(lock){
        __lock.ReadLock();
    }
    ~ReadLockGuard(){
        __lock.Unlock();
    }
private:
    RWLock __lock;
};
class WriteLockGuard{
public:
    WriteLockGuard()= delete;
    explicit WriteLockGuard(RWLock &lock):__lock(lock){
        __lock.WriteLock();
    }
    ~WriteLockGuard(){
        __lock.Unlock();
    }
private:
    RWLock __lock;
};


#endif //SIMPLEHTTPSERVER_RWMUTEX_H
