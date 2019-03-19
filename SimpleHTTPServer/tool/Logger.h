//
// Created by lengyu on 2019/3/17.
//

#ifndef SIMPLEHTTPSERVER_LOGGING_H
#define SIMPLEHTTPSERVER_LOGGING_H

#include "LogStream.h"
#include "ctype.h"
#include "CurrentThread.h"
#include <sys/time.h>
#include <ctime>
#include "syscall.h"
namespace SimpleServer {
    namespace Logger{
        enum  LOG_LEVEL{
             INFO=0,
             WARING=1,
             ERROR=2,
             FATAL=3,
             TRACE=4,
             DEBUG=5,
             FORBIDDEN=6,
        };
        const static char *LOG_STRING[]={
                "INFO",
                "WARING",
                "ERROR",
                "FATAL",
                "TRACE",
                "DEBUG"
        };

        class __Logger {
        public:

            __Logger(const char *__file, const int __line,LOG_LEVEL __level,const char *__func= nullptr):
                    filename(__file),line(__line),function(__func),level(__level){}
            __Logger()= delete;
            SimpleServer::detail::LogStream stream(){
                //cached tid
                __Cached();

                char buffer[headerSize];
                const char* pos=strrchr(filename,'/');
                const static size_t timeTempSize=64;
                char timeTemp[timeTempSize];
                struct timeval  localTime;
                if(gettimeofday(&localTime, nullptr)==0)
                {
                    struct tm timeSotrage;
                    localtime_r(&localTime.tv_sec,&timeSotrage);
                    std::strftime(timeTemp,timeTempSize,"%Z %Y-%m-%d %H:%M:%S",&timeSotrage);
                    sprintf(timeTemp,"%s.%li",timeTemp,localTime.tv_usec);
                }else{
                    sprintf(timeTemp,"%s.%d","Error",errno);
                }
                if(level>=LOG_LEVEL::TRACE) {
                    sprintf(buffer, "[%s] %s %s %s:%d(%s) ", LOG_STRING[level], __threadString, timeTemp, pos+1, line, function);
                }else{
                    sprintf(buffer, "[%s] %s %s %s:%d ", LOG_STRING[level], __threadString,timeTemp, pos+1, line);
                }
                return SimpleServer::detail::LogStream(buffer,strlen(buffer));
            }
        private:
            /*
             *  Attention!
             *  if header size large than
             *  128. It will panic!
             */
            const static size_t headerSize=128;
            LOG_LEVEL level;
            const char *filename;
            const int  line;
            const char *function;
        };
    }
}
#define SERVER_LOG_LEVEL SimpleServer::Logger::LOG_LEVEL::INFO
#define LOG_INFO if(SERVER_LOG_LEVEL>=SimpleServer::Logger::LOG_LEVEL::INFO)\
    SimpleServer::Logger::__Logger(__FILE__, __LINE__, SimpleServer::Logger::LOG_LEVEL::INFO).stream()
#define LOG_WARING if(SERVER_LOG_LEVEL>=SimpleServer::Logger::LOG_LEVEL::WARING)\
    SimpleServer::Logger::__Logger(__FILE__, __LINE__, SimpleServer::Logger::LOG_LEVEL::WARING).stream()
#define LOG_ERROR if(SERVER_LOG_LEVEL>=SimpleServer::Logger::LOG_LEVEL::ERROR)\
    SimpleServer::Logger::__Logger(__FILE__, __LINE__, SimpleServer::Logger::LOG_LEVEL::ERROR).stream()
#define LOG_FATAL if(SERVER_LOG_LEVEL>=SimpleServer::logger::LOG_LEVEL::FATAL)\
    SimpleServer::Logger::__Logger(__FILE__, __LINE__, SimpleServer::Logger::LOG_LEVEL::FATAL)
#define LOG_TRACE SimpleServer::Logger::__Logger(__FILE__, __LINE__, SimpleServer::Logger::LOG_LEVEL::TRACE, __FUNCTION__).stream()
#define LOG_DEBUG SimpleServer::Logger::__Logger(__FILE__, __LINE__, SimpleServer::Logger::LOG_LEVEL::TRACE, __FUNCTION__).stream()

#endif //SIMPLEHTTPSERVER_LOGGING_H
