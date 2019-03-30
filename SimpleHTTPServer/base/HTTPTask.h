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
#include <GlobalConfig.h>

namespace SimpleServer {
    class HTTPTask : virtual public Task {
    public:
        ~HTTPTask() {
        };

        int getSockfd() {
            return this->sockfd;
        }

        HTTPTask() = default;

        explicit HTTPTask(int fd, sockaddr_in &sockaddr, int port) : sockfd(fd),
                                                                     sockaddr(sockaddr), port(port) {
        }

        void setConfig(SimpleServer::Config::detail::ServerConfig &config) {
            this->serverConfig = config;
        }

        void Run() override;

    private:
        int sockfd;
        int port;
        sockaddr_in sockaddr;
        Config::detail::ServerConfig serverConfig;

        void todoDynamic(const std::string &SERVER_ROOT, const net::httpContext &context, std::string &content_type);

        void todoStatic(const std::string &SERVER_ROOT, const net::httpContext &context, std::string &content_type);
    };
}

#endif //SIMPLEHTTPSERVER_HTTPTASK_H
