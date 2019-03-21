//
// Created by lengyu on 2019/3/3.
//
#include <unistd.h>
#include <zconf.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <cstring>
#include "nethelp.h"
#include "errHelp.h"
#include <cstdio>
#include <cerrno>

namespace SimpleServer {
    namespace tool {
        int Listen(int sockfd, int backlog) {
            if (listen(sockfd, backlog) != 0) {
                panic("Listen error!");
                return -1;
            }
            return 0;
        }

        int Bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen) {
            if (bind(sockfd, myaddr, addrlen) != 0) {
                panic("Bind error!");
                return -1;
            }
            return 0;
        }

        int openIpv4Listen(unsigned int port) {
            int socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            struct sockaddr_in servaddr;
            memset(&servaddr, 0, sizeof(servaddr));
            servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
            servaddr.sin_family = AF_INET;
            servaddr.sin_port = htons(port);
            Bind(socketfd, (SA *) &servaddr, sizeof(servaddr));
            Listen(socketfd, LISTENQ);
            return socketfd;
        }

        int openIpv6Listen(unsigned int port) {
            int socketfd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
            struct sockaddr_in6 servaddr;
            memset(&servaddr, 0, sizeof(servaddr));
            servaddr.sin6_addr = in6addr_any;
            servaddr.sin6_family = AF_INET6;
            servaddr.sin6_port = htons(port);
            Bind(socketfd, (SA *) &servaddr, sizeof(servaddr));
            Listen(socketfd, LISTENQ);
            return socketfd;
        }

        int OpenIpv6Listen(unsigned int port) {
            int ret = openIpv6Listen(port);
            if (ret < 0) {
                panic("open ipv6 listener err");
            }
            return ret;
        }

        int OpenIpv4Listen(unsigned int port) {
            int ret = openIpv4Listen(port);
            if (ret < 0) {
                panic("open ipv4 listener err");
            }
            return ret;
        }

        int Accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen) {
            int ret = accept(sockfd, cliaddr, addrlen);
            if (ret < 0) {
                panic("Accept error!");
            }
            return ret;
        }
    }
}
