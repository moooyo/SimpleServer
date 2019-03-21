//
// Created by lengyu on 2019/3/3.
//

#ifndef UNTITLED3_EPOLLHELP_H
#define UNTITLED3_EPOLLHELP_H

#include <cstdint>
#include <sys/epoll.h>

namespace SimpleServer {
    namespace tool {
        int Epoll_ctl(int epollfd, int op, int fd, struct epoll_event *event);

        int Epoll_wait(int epollfd, struct epoll_event *list, int max_events, int timeout);

        int Epoll_add(int epollfd, int fd, uint32_t events);

        int Epoll_delete(int epollfd, int fd, uint32_t events);

        int Epoll_mod(int epollfd, int fd, uint32_t events);
    }
}
#endif //UNTITLED3_EPOLLHELP_H
