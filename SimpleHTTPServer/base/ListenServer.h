//
// Created by lengyu on 2019/3/3.
//

#ifndef UNTITLED3_LISTENSERVER_H
#define UNTITLED3_LISTENSERVER_H

#include "EventLoop.h"
#include "HTTPTask.h"
#include "ConditionLock.h"
#include <unordered_set>

namespace SimpleServer {
    class ServerKey {
    public:
        ServerKey(const std::string &domain, size_t port) : domain(domain), port(port) {
        }
        bool operator==(const ServerKey &that)const{
            return this->port==that.port&&this->domain==that.domain;
        }
        ServerKey() = delete;

        std::string domain;
        std::size_t port;
    };

    struct ServerKeyHash {
        size_t operator()(const ServerKey &key) const {
            const static auto str_hash = std::hash<std::string>();
            const static auto sizet_hash = std::hash<std::size_t>();
            return (str_hash(key.domain) << 1) ^ (sizet_hash(key.port));
        }
    };

    class ListenServer {
    private:
        std::vector<int> listenfd;
        int epollfd;
        EventLoop<HTTPTask> *loop;
        ConditionLock *lock;
        static std::unordered_map<ServerKey, SimpleServer::Config::detail::ServerConfig, ServerKeyHash> serverMap;
        std::unordered_map<int ,int >portMap;
    public:
        const int MAX_EVENTS;

        ~ListenServer() {
            for (auto i:listenfd) {
                close(i);
            }
            close(this->epollfd);
        }
        static auto ServerConfig()-> decltype((serverMap)){
            return serverMap;
        }
        ListenServer(int maxsize, ConditionLock *lock, EventLoop<HTTPTask> *loop);

        void StartListening();

        void Accept(int listenfd);
    };
}
#endif //UNTITLED3_LISTENSERVER_H
