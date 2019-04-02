//
// Created by lengyu on 2019/3/3.
//

#include "ListenServer.h"
#include "errHelp.h"
#include "HTTP/httpRequest.h"
#include "epollHelp.h"
#include "Logging.h"
#include <cstdio>
#include <sys/epoll.h>
#include <zconf.h>
#include <netinet/in.h>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <nethelp.h>
#include <Logger.h>

using namespace SimpleServer;
std::unordered_map<ServerKey, SimpleServer::Config::detail::ServerConfig, ServerKeyHash> ListenServer::serverMap;
ListenServer::ListenServer(int maxsize, ConditionLock *lock, EventLoop<HTTPTask> *loop) :
        MAX_EVENTS(maxsize), loop(loop) {
    this->epollfd = epoll_create(this->MAX_EVENTS);
    this->lock = lock;
    if (this->epollfd < 0) {
        tool::panic("err init epoll!");
    }
    std::unordered_set<int> listenPort;
    for (auto i: SimpleServer::GlobalConfig.Server()) {
        listenPort.insert(i.ListenPort());
        ServerKey key(i.Domain(), i.ListenPort());
        ListenServer::ServerConfig()[key]=i;
    }
    for (auto i: listenPort) {
        int fd = SimpleServer::tool::OpenIpv4Listen(i);
        this->listenfd.push_back(fd);
        this->portMap[fd]=i;
    }
}

void ListenServer::StartListening() {
    __threadName = __ThreadNameStorage[1];
    __threadStringSize = strlen(__threadName);
    __FormatString();
    LOG_INFO<<"Start listenning";
    struct ::epoll_event event_list[this->MAX_EVENTS];
    for (auto i: this->listenfd) {
        LOG_INFO<<"Epoll_add "<<i;
        tool::Epoll_add(this->epollfd, i, EPOLLIN | EPOLLET);
    }
    int timeout = -1;
    for (;;) {
        int ret = tool::Epoll_wait(this->epollfd, event_list, MAX_EVENTS, timeout);
        LOG_INFO<<"epoll ret:"<<ret;
        if (ret == 0) {
            continue;
        }
        for (int i = 0; i < ret; ++i) {
            if (event_list[i].events & EPOLLERR || event_list[i].events & EPOLLHUP ||
                !(event_list[i].events & EPOLLIN)) {
                close(event_list[i].data.fd);
                LOG_ERROR << "Epoll wait error";
                continue;
            } else {
                LOG_INFO<<"Accept "<<event_list[i].data.fd;
                this->Accept(event_list[i].data.fd);
            }
        }
    }
}

void __closeSocket(int* ptr){
    LOG_WARING<<"close socketfd "<<*ptr;
    close(*ptr);
}


void ListenServer::Accept(int listenfd) {
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    memset(&sin, 0, len);
    int connfd;
    connfd = tool::Accept(listenfd, (tool::SA *) &sin, &len);
    std::shared_ptr<int> sharedPtr(new int(connfd),__closeSocket);
    HTTPTask task(sharedPtr, sin, this->portMap[listenfd]);
    this->loop->push(task);
    this->lock->notify();
}
