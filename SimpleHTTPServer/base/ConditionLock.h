//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_CONDITIONLOCK_H
#define SIMPLEHTTPSERVER_CONDITIONLOCK_H


#include <zconf.h>
#include <pthread.h>
#include <memory>
namespace SimpleServer {
    class ConditionLock {
    public:
        explicit ConditionLock(Mutex &mutex) : __mutex(mutex) {
            pthread_cond_init(&__condition, nullptr);
        }
        void wait() {
            pthread_cond_wait(&__condition, &__mutex.getLock());
        }

        /*
         *  return true when timeout
         */
        bool waitForSeconds(int seconds) {
            struct timespec abstime;
            clock_gettime(CLOCK_REALTIME, &abstime);
            const int64_t KNanoSecondsPerSecond = 1000000000;
            int64_t nanoseconds = static_cast<int64_t >(seconds * KNanoSecondsPerSecond);
            abstime.tv_sec += static_cast<time_t >((abstime.tv_nsec + nanoseconds) / KNanoSecondsPerSecond);
            abstime.tv_nsec = static_cast<long >((abstime.tv_nsec + nanoseconds) % KNanoSecondsPerSecond);
            return ETIMEDOUT == pthread_cond_timedwait(&this->__condition, &this->__mutex.getLock(), &abstime);
        }

        void notify() {
            pthread_cond_signal(&__condition);
        }

        void notifyAll() {
            pthread_cond_broadcast(&__condition);
        }

        ~ConditionLock() {
            pthread_cond_destroy(&__condition);
        }

    private:
        Mutex __mutex;
        pthread_cond_t __condition;
    };
}


#endif //SIMPLEHTTPSERVER_CONDITIONLOCK_H
