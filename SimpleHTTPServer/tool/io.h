//
// Created by lengyu on 2019/3/1.
//

#ifndef UNTITLED3_IO_H
#define UNTITLED3_IO_H

#include <cstdio>

namespace SimpleServer {
    namespace tool {
        using ssize_t=long;
        const ssize_t MAXLINE = 4096;

        ssize_t readn(int fd, void *vptr, size_t n);

        ssize_t writen(int fd, const void *vptr, size_t n);

        ssize_t readline(int fd, void *vptr, size_t maxlen);
    }
}


#endif //UNTITLED3_IO_H
