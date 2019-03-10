//
// Created by lengyu on 2019/3/8.
//

#ifndef SIMPLEHTTPSERVER_HTTPTASK_H
#define SIMPLEHTTPSERVER_HTTPTASK_H

#include <nethelp.h>
#include <netinet/in.h>
#include <zconf.h>
#include "Task.h"
#include "../tool/HTTP/httpContext.h"
namespace SimpleServer {
    class HTTPTask: virtual public Task{
    public:
        ~HTTPTask() {
            //close(this->sockfd);
        };
        int getSockfd(){
            return this->sockfd;
        }
        HTTPTask()= default;
        explicit  HTTPTask(int fd,sockaddr_in &sockaddr):sockfd(fd),sockaddr(sockaddr){}

        void Run() override;
    private:
        int sockfd;
        sockaddr_in sockaddr;
        void todoDynamic(const net::httpContext &context,std::string &content_type);
        void todoStatic(const net::httpContext &context,std::string &content_type);
    };
}

#endif //SIMPLEHTTPSERVER_HTTPTASK_H
