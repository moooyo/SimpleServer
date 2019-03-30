//
// Created by lengyu on 2019/3/20.
//

#ifndef SIMPLEHTTPSERVER_CURRENTTHREAD_H
#define SIMPLEHTTPSERVER_CURRENTTHREAD_H

#include <cstddef>

namespace SimpleServer {
#define gettid() syscall(SYS_gettid)

    extern __thread long __cachedTid;
    extern __thread size_t __threadStringSize;
    extern __thread char __threadString[32];
    extern __thread const char *__threadName;
    const static char *__ThreadNameStorage[] = {
            "Worker",
            "Listener",
            "Logger",
    };

    void __Cached();
    void __FormatString();
}

#endif //SIMPLEHTTPSERVER_CURRENTTHREAD_H
