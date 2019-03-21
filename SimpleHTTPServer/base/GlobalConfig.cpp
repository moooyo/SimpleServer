//
// Created by lengyu on 2019/3/21.
//
#include <yaml-cpp/yaml.h>
#include <iostream>
#include "GlobalConfig.h"
#include "Logger.h"
#include "LogStream.h"
SimpleServer::Config::detail::__GlobalConfig GlobalConfig;
using namespace SimpleServer;
using namespace Logger;
using namespace Config;
template <typename T>
bool __ParseYAMLField(YAML::Node config,std::string field,T &result){
    if(config[field])
    {
        result=config[field].as<T>();
        return true;
    }else
    {
        LOG_ERROR<<"Parse "<<field<<" failed";
        return false;
    }
}
void SimpleServer::Config::parseConfig(){
    YAML::Node config=YAML::LoadFile("/home/lengyu/CLionProjects/SimpleHTTPServer/Config.yaml");
    if(config["Server"]&&config["Server"].Type()==YAML::NodeType::Sequence)
    {
        LOG_INFO<<"Parse server config start";
        std::string strTemp;
        size_t sizeTemp;
        for(auto i:config["Server"]){
            detail::ServerConfig serverConfig;
            if(__ParseYAMLField<std::string>(i,"domain",strTemp))
            {
                serverConfig.domain=strTemp;
            }
            if(__ParseYAMLField<std::string>(i,"root",strTemp))
            {
                serverConfig.root=strTemp;
            }
            if(__ParseYAMLField<std::string>(i,"index",strTemp))
            {
                serverConfig.index=strTemp;
            }
            if(__ParseYAMLField<size_t>(i,"listen",sizeTemp))
            {
                serverConfig.listenPort=sizeTemp;
            }
            GlobalConfig.__server.push_back(serverConfig);
            LOG_INFO<<"Server:"<<serverConfig;
        }
    }else{
        LOG_ERROR<<"Parse server config error";
    }
    if(config["Cache"]){
        LOG_INFO<<"Parse cache config start";
        size_t sizeTemp;
        bool boolTemp;
        if(__ParseYAMLField<bool>(config["Cache"],"status",boolTemp)){
            GlobalConfig.__cache.status=boolTemp;
        }
        if(__ParseYAMLField<size_t >(config["Cache"],"cacheSize",sizeTemp)){
            GlobalConfig.__cache.cacheSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config["Cache"],"cacheNodeSize",sizeTemp)){
            GlobalConfig.__cache.cacheNodeSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config["Cache"],"expired",sizeTemp)){
            GlobalConfig.__cache.expired=sizeTemp;
        }
        LOG_INFO<<"Cache:"<<GlobalConfig.__cache;
    }else{
        LOG_ERROR<<"Parse cache config error";
    }
    if(config["Log"])
    {
        LOG_INFO<<"Parse log config start";
        size_t sizeTemp;
        std::string strTemp;
        bool boolTemp;
        if(__ParseYAMLField<bool >(config["Log"],"status",boolTemp)){
            GlobalConfig.__log.status=boolTemp;
        }
        /*
        if(__ParseYAMLField<std::string>(config,"level",strTemp)){
            GlobalConfig.__log.level=SimpleServer::Logger::Str2Level(strTemp);
        }*/
        if(__ParseYAMLField<size_t >(config["Log"],"logBufferSize",sizeTemp)){
            GlobalConfig.__log.loggerBufferSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config["Log"],"fullVectorSize",sizeTemp)){
            GlobalConfig.__log.fullVectorSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config["Log"],"emptyVectorSize",sizeTemp)){
            GlobalConfig.__log.emptyVectorSize=sizeTemp;
        }
        if(__ParseYAMLField<std::string>(config["Log"],"logFilePath",strTemp)){
            GlobalConfig.__log.logFilePath=strTemp;
        }
        LOG_INFO<<"Log:"<<GlobalConfig.__log;
    }else{
        LOG_ERROR<<"Parse log config error";
    }
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::__GlobalConfig &globalConfig) {
    for(auto i:globalConfig.__server){
        out<<i<<"\n";
    }
    out<<globalConfig.__log<<"\n";
    out<<globalConfig.__cache;
    return out;
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::ServerConfig &serverConfig) {
    out<<"domain:"<<serverConfig.domain<<" port:"<<serverConfig.listenPort<<" root:"<<serverConfig.root<<" index:"<<serverConfig.index;
    return out;
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::LogConfig &logConfig) {
    out<<"status:"<<logConfig.status<<" filePath:"<<logConfig.logFilePath<<" emptyVectorSize:"<<logConfig.emptyVectorSize
    <<" fullVectorSize:"<<logConfig.fullVectorSize<<" BufferSize"<<logConfig.loggerBufferSize;
    return out;
}

SimpleServer::detail::LogStream &
Config::detail::operator<<(SimpleServer::detail::LogStream &out, detail::CacheConfig &cacheConfig) {
    out<<"status:"<<cacheConfig.status<<" expired:"<<cacheConfig.expired<<" cacheNodeSize:"<<cacheConfig.cacheNodeSize
    <<" cacheSize:"<<cacheConfig.cacheSize;
    return out;
}
