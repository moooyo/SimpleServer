//
// Created by lengyu on 2019/3/3.
//

#include "ListenServer.h"
#include "errHelp.h"
#include "nethelp.h"
#include "HTTP/httpRequest.h"
#include "epollHelp.h"
#include "Logging.h"
#include <cstdio>
#include <sys/epoll.h>
#include <zconf.h>
#include <netinet/in.h>
#include <cstring>

using namespace SimpleServer;

ListenServer::ListenServer(int sockfd, int maxsize, ConditionLock *lock, EventLoop<HTTPTask> *loop) :
        listenfd(sockfd), MAX_EVENTS(maxsize), loop(loop) {
    this->epollfd = epoll_create(this->MAX_EVENTS);
    this->lock = lock;
    if (this->epollfd < 0) {
        tool::panic("err init epoll!");
    }
    struct timeval tv;
    tv.tv_usec = 0;
    tv.tv_sec = 0;//3 second for timeout
    setsockopt(this->listenfd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
}

void ListenServer::StartListenning() {
    struct ::epoll_event event_list[this->MAX_EVENTS];
    tool::Epoll_add(this->epollfd, this->listenfd, EPOLLIN | EPOLLET);
    int timeout = -1;
    for (;;) {
        int ret = tool::Epoll_wait(this->epollfd, event_list, MAX_EVENTS, timeout);
        if (ret == 0) {
            continue;
        }
        for (int i = 0; i < ret; ++i) {
            if (event_list[i].events & EPOLLERR || event_list[i].events & EPOLLHUP ||
                !(event_list[i].events & EPOLLIN)) {
                close(event_list[i].data.fd);
                std::printf("error!\n");
                continue;
            } else if (event_list[i].data.fd == this->listenfd) {
                std::printf("accept!\n");
                this->Accept();
            } else {
                std::printf("not match\n");
            }
        }
    }

}

void ListenServer::Accept() {
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    memset(&sin, 0, len);
    int connfd;
    while ((connfd = tool::Accept(this->listenfd, (tool::SA *) &sin, &len)) && connfd > 0) {
        HTTPTask task(connfd, sin);
        this->loop->push(task);
        this->lock->notify();
    }
}
