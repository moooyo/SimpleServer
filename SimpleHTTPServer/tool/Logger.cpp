//
// Created by lengyu on 2019/3/27.
//
#include "Logger.h"
#include <iostream>
#ifdef __DEBUG__
#include <execinfo.h>
#include <csignal>

#endif
using namespace SimpleServer;
using namespace Logger;
#ifdef __DEBUG__
void Logger::dump(){
    int nptrs;
    const static int BACKTRACE_SIZE = 16;
    void *buffer[BACKTRACE_SIZE];
    nptrs=backtrace(buffer,BACKTRACE_SIZE);
    std::printf("backtrace() returned %d addresses\n", nptrs);
    char **strings=backtrace_symbols(buffer,nptrs);
    for(int i=0; i<nptrs; ++i){
        printf("  [%02d] %s\n", i, strings[i]);
    }
    free(strings);
}
void Logger::signal_handler(int signo){
    std::printf("\n*********catch signal %d ***********\n",signo);
    LOG_ERROR<<"Core Dump";
    std::printf("Dump Start\n");
    Logger::dump();
    std::printf("Dump end\n");
    signal(signo,SIG_DFL);
    raise(signo);
}
#endif