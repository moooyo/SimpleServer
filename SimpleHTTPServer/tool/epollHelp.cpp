//
// Created by lengyu on 2019/3/3.
//

#include "epollHelp.h"
#include <sys/epoll.h>
#include "errHelp.h"
namespace SimpleServer{
    namespace tool{
        int Epoll_ctl(int epollfd, int op, int fd, struct epoll_event *event) {
            int ret;
            if ((ret = epoll_ctl(epollfd, op, fd, event)) < 0) {
                panic("epoll_ctl error");
            }
            return ret;
        }

        int Epoll_wait(int epollfd, struct epoll_event *list, int max_events, int timeout) {
            int ret = epoll_wait(epollfd, list, max_events, timeout);
            if (ret < 0) {
                panic("epoll wait error!");
            }
            return ret;
        }

        int Epoll_add(int epollfd, int fd, uint32_t events) {
            struct epoll_event event;
            event.events = events;
            event.data.fd = fd;
            return Epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
        }

        int Epoll_delete(int epollfd, int fd, uint32_t events) {
            struct epoll_event event;
            event.events = events;
            event.data.fd = fd;
            return Epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &event);
        }

        int Epoll_mod(int epollfd, int fd, uint32_t events) {
            struct epoll_event event;
            event.events = events;
            event.data.fd = fd;
            return Epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
        }
    }
}