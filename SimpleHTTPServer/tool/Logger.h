//
// Created by lengyu on 2019/3/17.
//

#ifndef SIMPLEHTTPSERVER_LOGGING_H
#define SIMPLEHTTPSERVER_LOGGING_H

#include "LogStream.h"
#include "ctype.h"
namespace SimpleServer {
    namespace Logger{
        enum  LOG_LEVEL{
             INFO=0,
             WARING=1,
             ERROR=2,
             FATAL=3,
             TRACE=4,
             DEBUG=5,
        };
        const static char *LOG_STRING[]={
                "INFO",
                "WARING",
                "ERROR",
                "FATAL",
                "TRACE",
                "DEBUG"
        };

        class Logger {
        public:
            Logger(char *__file, char *__line,LOG_LEVEL __level,char *__func= nullptr):
                    filename(__file),line(__line),function(__func),level(__level){}
            Logger()= delete;
            SimpleServer::detail::LogStream stream(){
                char buffer[headerSize];
                if(level>=LOG_LEVEL::TRACE) {
                    sprintf(buffer, "[%s]%s-%s(%s):", LOG_STRING[level], filename, line, function);
                }else{
                    sprintf(buffer, "[%s]%s-%s:", LOG_STRING[level], filename, line);
                }
                return SimpleServer::detail::LogStream(buffer,strlen(buffer));
            }
        private:
            /*
             *  Attention!
             *  if header size large than
             *  64. It will panic!
             */
            const static size_t headerSize=64;
            LOG_LEVEL level;
            char *filename;
            char *line;
            char *function;

        };
    }
}


#endif //SIMPLEHTTPSERVER_LOGGING_H
