//
// Created by lengyu on 2019/3/16.
//
#include "Cache.h"

using namespace SimpleServer;
using namespace tool;
CacheManager *SingletonCache::Cache = nullptr;

void tool::__SignletonCacheInit__() {
    if (SingletonCache::Cache == nullptr) {
        SingletonCache::Cache = new CacheManager();
    }
}
