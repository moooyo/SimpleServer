//
// Created by lengyu on 2019/3/15.
//

#ifndef SIMPLEHTTPSERVER_CACHE_H
#define SIMPLEHTTPSERVER_CACHE_H

#include "Buffer.h"
#include <string>
#include <HTTP/httpRequest.h>
#include <RWLock.h>
#include <list>
#include <memory>

namespace SimpleServer {
    namespace tool {
        const static std::string  LOCALHOST="localhost";
        const static int MAX_BUFFER_SIZE=10240;
        const static int MAX_CACHE_SIZE=128;
        struct CacheKeyHash;
        class CacheKey{
        public:
            CacheKey(const net::httpRequest &request):uri(request.getUri()),query(request.getQuery()),
                host(request.getHeaders().count("host")==0?LOCALHOST:request.getHeaders().find("host")->second){}
                friend CacheKeyHash;
            bool operator==(const CacheKey &that) const{
                return this->uri==that.uri&&this->host==that.host&&this->query==that.query;
            }
        private:
            std::string uri;
            std::string host;
            std::string query;
        };
        struct CacheKeyHash{
            size_t operator()(const CacheKey &key)const {
                static auto h=std::hash<std::string>{};
                size_t s1=h(key.uri);
                size_t s2=h(key.host);
                size_t s3=h(key.query);
                return s1^(s2<<1)^(s3<<2);
            }
        };

        class CacheNode {
        public:
            const static time_t expiredTime=30;//every cache will active no more than 30s
            CacheNode(const char *buf,size_t sz):size(sz),expired(time(nullptr)+expiredTime),buffer(new char[sz+1])
            {
                memcpy(this->buffer,buf,sz);
                buffer[sz]='\0';
            }
            char *getBuffer() const {
                return this->buffer;
            }
            RWLock &getLock() {
                return this->__lock;
            }
            ~CacheNode(){
                free(this->buffer);
            }
        private:
            char *buffer;
            size_t size;
            time_t expired;
            ::RWLock __lock;
        };

        class CacheManager{
        public:
            bool insert(const char *buf,const size_t size,const CacheKey &key){
                if(size>MAX_BUFFER_SIZE)
                {
                   return false;
                }
                std::shared_ptr<CacheNode> node=std::make_shared<CacheNode>(buf,size);
                if(CacheList.size()>MAX_CACHE_SIZE)
                {
                    {
                        auto iterator=CacheList.rbegin();
                        WriteLockGuard lock((*iterator)->getLock());
                        CacheList.erase(iterator.base());
                    }
                }
                WriteLockGuard lockGuard(node->getLock());
                CacheList.push_front(node);
                CacheMap[key]=node;
                return true;
            }
            bool delNode(const CacheKey &key){
                if(CacheMap.count(key)==0)
                {
                    return false;
                }
                auto iter=CacheMap.find(key);
                WriteLockGuard lockGuard(iter->second->getLock());
                CacheMap.erase(iter);
                return true;
            }
            std::shared_ptr<CacheNode> getCache(const CacheKey &key){
                if(CacheMap.count(key)==0)
                {
                    return nullptr;
                }
                return CacheMap[key];
            }
        private:
            std::list<std::shared_ptr<CacheNode>> CacheList;
            std::unordered_map<CacheKey,std::shared_ptr<CacheNode>,CacheKeyHash> CacheMap;
        };


        static pthread_once_t __SignletonCacheOnce=PTHREAD_ONCE_INIT;
        void __SignletonCacheInit__();
        class SingletonCache{
        private:
            static RWLock __lock;
            static CacheManager *Cache;
        public:
            friend void __SignletonCacheInit__();
            static auto getInstance() -> decltype(SingletonCache::Cache)
            {
                pthread_once(&__SignletonCacheOnce,__SignletonCacheInit__);
                return SingletonCache::Cache;
            }
        };
    }
}


#endif //SIMPLEHTTPSERVER_CACHE_H
