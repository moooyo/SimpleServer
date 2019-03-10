//
// Created by lengyu on 2019/3/3.
//

#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include "errHelp.h"
namespace SimpleServer{
    namespace tool {
        void panic(const char *msg) {
            std::printf("panic:errno(%d) with msg(%s)\n", errno, msg);
            std::exit(-1);
        }
    }
}