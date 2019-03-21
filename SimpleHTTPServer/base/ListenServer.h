//
// Created by lengyu on 2019/3/3.
//

#ifndef UNTITLED3_LISTENSERVER_H
#define UNTITLED3_LISTENSERVER_H

#include "EventLoop.h"
#include "HTTPTask.h"
#include "ConditionLock.h"

namespace SimpleServer {
    class ListenServer {
    private:
        int listenfd;
        int epollfd;
        EventLoop<HTTPTask> *loop;
        ConditionLock *lock;
    public:
        const int MAX_EVENTS;

        ~ListenServer() {
            close(this->listenfd);
            close(this->epollfd);
        }

        ListenServer(int sockfd, int maxsize, ConditionLock *lock, EventLoop<HTTPTask> *loop);

        void StartListenning();

        void Accept();
    };
}
#endif //UNTITLED3_LISTENSERVER_H
