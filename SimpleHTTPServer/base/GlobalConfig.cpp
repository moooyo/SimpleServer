//
// Created by lengyu on 2019/3/21.
//
#include <yaml-cpp/yaml.h>
#include <iostream>
#include "GlobalConfig.h"
#include "Logger.h"
SimpleServer::Config::detail::__GlobalConfig GlobalConfig;
template <typename T>
bool __ParseYAMLField(YAML::Node &config,std::string field,T &result){
    if(config[field]&&config[field])
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
            if(__ParseYAMLField<std::string>(config,"domain",strTemp))
            {
                serverConfig.domain=strTemp;
            }
            if(__ParseYAMLField<std::string>(config,"root",strTemp))
            {
                serverConfig.root=strTemp;
            }
            if(__ParseYAMLField<std::string>(config,"index",strTemp))
            {
                serverConfig.index=strTemp;
            }
            if(__ParseYAMLField<size_t>(config,"listen",sizeTemp))
            {
                serverConfig.listenPort=sizeTemp;
            }
            GlobalConfig.__server.push_back(serverConfig);
        }
    }else{
        LOG_ERROR<<"Parse server config error";
    }
    if(config["Cache"]){
        LOG_INFO<<"Parse cache config start";
        size_t sizeTemp;
        bool boolTemp;
        if(__ParseYAMLField<bool>(config,"status",boolTemp)){
            GlobalConfig.__cache.status=boolTemp;
        }
        if(__ParseYAMLField<size_t >(config,"cacheSize",sizeTemp)){
            GlobalConfig.__cache.cacheSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config,"cacheNodeSize",sizeTemp)){
            GlobalConfig.__cache.cacheNodeSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config,"expired",sizeTemp)){
            GlobalConfig.__cache.expired=sizeTemp;
        }
    }else{
        LOG_ERROR<<"Parse cache config error";
    }
    if(config["Log"])
    {
        LOG_INFO<<"Parse log config start";
        size_t sizeTemp;
        std::string strTemp;
        bool boolTemp;
        if(__ParseYAMLField<bool >(config,"status",boolTemp)){
            GlobalConfig.__log.status=boolTemp;
        }
        /*
        if(__ParseYAMLField<std::string>(config,"level",strTemp)){
            GlobalConfig.__log.level=SimpleServer::Logger::Str2Level(strTemp);
        }*/
        if(__ParseYAMLField<size_t >(config,"logBufferSize",sizeTemp)){
            GlobalConfig.__log.loggerBufferSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config,"fullVectorSize",sizeTemp)){
            GlobalConfig.__log.fullVectorSize=sizeTemp;
        }
        if(__ParseYAMLField<size_t >(config,"emptyVectorSize",sizeTemp)){
            GlobalConfig.__log.emptyVectorSize=sizeTemp;
        }
        if(__ParseYAMLField<std::string>(config,"logFilePath",strTemp)){
            GlobalConfig.__log.logFilePath=strTemp;
        }
    }else{
        LOG_ERROR<<"Parse log config error";
    }

}