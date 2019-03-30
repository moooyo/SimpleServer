//
// Created by lengyu on 2019/3/21.
//
#include <yaml-cpp/yaml.h>
#include <iostream>
#include "GlobalConfig.h"

using namespace SimpleServer;
using namespace Logger;
using namespace Config;
SimpleServer::Config::detail::__GlobalConfig SimpleServer::GlobalConfig;
template<typename T>
bool __ParseYAMLField(YAML::Node config, std::string field, T &result) {
    if (config[field]) {
        result = config[field].as<T>();
        return true;
    } else {
        std::cout << "Parse " << field << " failed"<<std::endl;
        return false;
    }
}

void SimpleServer::Config::parseConfig() {
    YAML::Node config = YAML::LoadFile("/home/lengyu/CLionProjects/SimpleHTTPServer/Config.yaml");
    if (config["Server"] && config["Server"].Type() == YAML::NodeType::Sequence) {
        std::cout << "Parse server config start"<<std::endl;
        std::string strTemp;
        size_t sizeTemp;
        for (auto i:config["Server"]) {
            detail::ServerConfig serverConfig;
            if (__ParseYAMLField<std::string>(i, "domain", strTemp)) {
                serverConfig.domain = strTemp;
            }
            if (__ParseYAMLField<std::string>(i, "root", strTemp)) {
                serverConfig.root = strTemp;
            }
            if (__ParseYAMLField<std::string>(i, "index", strTemp)) {
                serverConfig.index = strTemp;
            }
            if (__ParseYAMLField<size_t>(i, "listen", sizeTemp)) {
                serverConfig.listenPort = sizeTemp;
            }
            GlobalConfig.__server.push_back(serverConfig);
        }
    } else {
        std::cout << "Parse server config error"<<std::endl;
    }
    if (config["Cache"]) {
        std::cout << "Parse cache config start"<<std::endl;
        size_t sizeTemp;
        bool boolTemp;
        if (__ParseYAMLField<bool>(config["Cache"], "status", boolTemp)) {
            GlobalConfig.__cache.status = boolTemp;
        }
        if (__ParseYAMLField<size_t>(config["Cache"], "cacheSize", sizeTemp)) {
            GlobalConfig.__cache.cacheSize = sizeTemp;
        }
        if (__ParseYAMLField<size_t>(config["Cache"], "cacheNodeSize", sizeTemp)) {
            GlobalConfig.__cache.cacheNodeSize = sizeTemp;
        }
        if (__ParseYAMLField<size_t>(config["Cache"], "expired", sizeTemp)) {
            GlobalConfig.__cache.expired = sizeTemp;
        }
    } else {
        std::cout << "Parse cache config error"<<std::endl;
    }
    if (config["Log"]) {
        std::cout << "Parse log config start"<<std::endl;
        size_t sizeTemp;
        std::string strTemp;
        bool boolTemp;
        if (__ParseYAMLField<bool>(config["Log"], "status", boolTemp)) {
            GlobalConfig.__log.status = boolTemp;
        }
        /*
        if(__ParseYAMLField<std::string>(config,"level",strTemp)){
            GlobalConfig.__log.level=SimpleServer::Logger::Str2Level(strTemp);
        }*/
        if (__ParseYAMLField<size_t>(config["Log"], "logBufferSize", sizeTemp)) {
            GlobalConfig.__log.loggerBufferSize = sizeTemp;
        }
        if (__ParseYAMLField<size_t>(config["Log"], "fullVectorSize", sizeTemp)) {
            GlobalConfig.__log.fullVectorSize = sizeTemp;
        }
        if (__ParseYAMLField<size_t>(config["Log"], "emptyVectorSize", sizeTemp)) {
            GlobalConfig.__log.emptyVectorSize = sizeTemp;
        }
        if (__ParseYAMLField<std::string>(config["Log"], "logFilePath", strTemp)) {
            GlobalConfig.__log.logFilePath = strTemp;
        }
    } else {
        std::cout << "Parse log config error"<<std::endl;
    }
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::__GlobalConfig &globalConfig) {
    for (auto i:globalConfig.__server) {
        out << i << "\n";
    }
    out << globalConfig.__log << "\n";
    out << globalConfig.__cache;
    return out;
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::ServerConfig &serverConfig) {
    out << "domain:" << serverConfig.domain << " port:" << serverConfig.listenPort << " root:" << serverConfig.root
        << " index:" << serverConfig.index;
    return out;
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::LogConfig &logConfig) {
    out << "status:" << logConfig.status << " filePath:" << logConfig.logFilePath << " emptyVectorSize:"
        << logConfig.emptyVectorSize
        << " fullVectorSize:" << logConfig.fullVectorSize << " BufferSize" << logConfig.loggerBufferSize;
    return out;
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::CacheConfig &cacheConfig) {
    out << "status:" << cacheConfig.status << " expired:" << cacheConfig.expired << " cacheNodeSize:"
        << cacheConfig.cacheNodeSize
        << " cacheSize:" << cacheConfig.cacheSize;
    return out;
}
