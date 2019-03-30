//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_TASK_H
#define SIMPLEHTTPSERVER_TASK_H

#include <HTTP/httpRequest.h>

namespace SimpleServer {
    class Task {
    public:
        ~Task() {

        };
        virtual void Run() = 0;
    };
}


#endif //SIMPLEHTTPSERVER_TASK_H
