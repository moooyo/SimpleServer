//
// Created by lengyu on 2019/3/18.
//

#ifndef SIMPLEHTTPSERVER_LOGSTREAM_H
#define SIMPLEHTTPSERVER_LOGSTREAM_H

#include <cstring>
#include <iostream>
#include "Logging.h"
namespace SimpleServer {
    namespace detail {
    class LogStream{
        public:
            explicit LogStream(const char *header, size_t headerSize):__bufferSize(__bufferSize){
                memcpy(__buffer,header,headerSize);
            }
            LogStream()= delete;
            void append(const char *msg){
                size_t len=strlen(msg);
                if(this->__bufferSize+len>BUFFER_SIZE)
                {
                    return;
                }
                memcpy(__buffer+__bufferSize,msg,len);
                this->__bufferSize+=len;
            }
            LogStream& operator<<(const char *msg){
                this->append(msg);
                return *this;
            }
            ~LogStream(){
                __AppendToLogFile(__buffer,__bufferSize);
            }
        private:
            const static size_t BUFFER_SIZE=4096;
            /*
             *  Attention!
             *  This buffer don't have
             *  '\0' in the end.
             */
            char __buffer[BUFFER_SIZE];
            size_t __bufferSize;
        };
    }
}


#endif //SIMPLEHTTPSERVER_LOGSTREAM_H
