cmake_minimum_required(VERSION 3.13)
project(SimpleHTTPServer)

set(CMAKE_CXX_STANDARD 14)

include_directories(SimpleHTTPServer/base)
include_directories(SimpleHTTPServer/tool)
link_libraries(pthread)
add_executable(SimpleHTTPServer
        SimpleHTTPServer/base/ListenServer.cpp
        SimpleHTTPServer/base/ListenServer.h
        SimpleHTTPServer/base/main.cpp
        SimpleHTTPServer/tool/epollHelp.cpp
        SimpleHTTPServer/tool/epollHelp.h
        SimpleHTTPServer/tool/errHelp.cpp
        SimpleHTTPServer/tool/errHelp.h
        SimpleHTTPServer/tool/HTTP/httpRequest.h
        SimpleHTTPServer/tool/io.cpp
        SimpleHTTPServer/tool/io.h
        SimpleHTTPServer/tool/nethelp.cpp
        SimpleHTTPServer/tool/nethelp.h
        readme.md SimpleHTTPServer/tool/HTTP/httpContext.cpp SimpleHTTPServer/tool/HTTP/httpContext.h SimpleHTTPServer/tool/Buffer.cpp SimpleHTTPServer/tool/Buffer.h SimpleHTTPServer/tool/HTTP/httpResponse.h SimpleHTTPServer/base/Mutex.h SimpleHTTPServer/base/MutexLockGuard.h SimpleHTTPServer/base/WorkerThread.h SimpleHTTPServer/base/EventLoop.h SimpleHTTPServer/base/Task.h SimpleHTTPServer/base/HTTPTask.h SimpleHTTPServer/base/ConditionLock.h SimpleHTTPServer/base/HTTPTask.cpp SimpleHTTPServer/tool/Cache.h SimpleHTTPServer/base/RWLock.h SimpleHTTPServer/tool/Cache.cpp SimpleHTTPServer/tool/Logger.cpp SimpleHTTPServer/tool/Logger.h)
