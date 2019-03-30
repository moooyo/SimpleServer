//
// Created by lengyu on 2019/3/21.
//
#include "CurrentThread.h"
#include <cstddef>
#include <sys/syscall.h>
#include <cstdio>
#include <cstring>
#include <unistd.h>

namespace SimpleServer {
#define gettid() syscall(SYS_gettid)
    __thread long __cachedTid = 0;
    __thread size_t __threadStringSize = 7;
    __thread char __threadString[32];
    __thread const char *__threadName = "Unknown";

    void __Cached() {
        if (__cachedTid == 0) {
            __cachedTid = gettid();
            sprintf(__threadString, "%li %s", __cachedTid, __threadName);
            __threadStringSize = strlen(__threadString);
        }
    }

    void __FormatString() {
        sprintf(__threadString,"%li %s",__cachedTid,__threadName);
    }
}
