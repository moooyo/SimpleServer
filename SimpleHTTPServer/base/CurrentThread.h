//
// Created by lengyu on 2019/3/20.
//

#ifndef SIMPLEHTTPSERVER_CURRENTTHREAD_H
#define SIMPLEHTTPSERVER_CURRENTTHREAD_H

#include <cstddef>
#include <syscall.h>
namespace SimpleServer{
#define gettid() syscall(SYS_gettid)
    __thread long   __cachedTid = 0;
    __thread size_t __threadStringSize=7;
    __thread char __threadString[32];
    __thread const char *__threadName = "Unknown";
    const static char *__ThreadNameStorage[]={
            "Worker",
            "Listener",
            "Logger",
    };
    void __Cached(){
        if(__cachedTid==0){
            __cachedTid=gettid();
            sprintf(__threadString,"%li %s",__cachedTid,__threadName);
            __threadStringSize=strlen(__threadString);
        }
    }
}

#endif //SIMPLEHTTPSERVER_CURRENTTHREAD_H
