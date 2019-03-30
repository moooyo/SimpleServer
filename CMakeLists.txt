cmake_minimum_required(VERSION 3.13)
project(SimpleHTTPServer)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-D __DEBUG__)
add_compile_options(-Og)
add_compile_options(-rdynamic)
add_compile_options(-g)


include_directories(SimpleHTTPServer/base)
include_directories(SimpleHTTPServer/tool)
link_libraries(pthread)
link_libraries(libyaml-cpp.a)
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
        readme.md SimpleHTTPServer/tool/HTTP/httpContext.cpp SimpleHTTPServer/tool/HTTP/httpContext.h SimpleHTTPServer/tool/Buffer.cpp SimpleHTTPServer/tool/Buffer.h SimpleHTTPServer/tool/HTTP/httpResponse.h SimpleHTTPServer/base/Mutex.h SimpleHTTPServer/base/MutexLockGuard.h SimpleHTTPServer/base/WorkerThread.h SimpleHTTPServer/base/EventLoop.h SimpleHTTPServer/base/Task.h SimpleHTTPServer/base/HTTPTask.h SimpleHTTPServer/base/ConditionLock.h SimpleHTTPServer/base/HTTPTask.cpp SimpleHTTPServer/tool/Cache.h SimpleHTTPServer/base/RWLock.h SimpleHTTPServer/tool/Cache.cpp SimpleHTTPServer/tool/Logging.cpp SimpleHTTPServer/tool/Logging.h SimpleHTTPServer/tool/Logger.h SimpleHTTPServer/tool/LogStream.h SimpleHTTPServer/base/CurrentThread.h SimpleHTTPServer/base/GlobalConfig.cpp SimpleHTTPServer/base/GlobalConfig.h SimpleHTTPServer/base/CurrentThread.cpp SimpleHTTPServer/tool/Logger.cpp SimpleHTTPServer/tool/LogStream.cpp)
