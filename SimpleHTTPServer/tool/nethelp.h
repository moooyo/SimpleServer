//
// Created by lengyu on 2019/3/3.
//
#ifndef UNTITLED3_NETHELP_H
#define UNTITLED3_NETHELP_H

#include <sys/socket.h>

namespace SimpleServer {
    namespace tool {
        using SA=sockaddr;
        const int LISTENQ = 4096;

        int Bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);

        int Listen(int sockfd, int backlog);

        int OpenIpv6Listen(unsigned int port);

        int OpenIpv4Listen(unsigned int port);

        int Accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
    }
}


#endif //UNTITLED3_NETHELP_H
