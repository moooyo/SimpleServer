// Created by lengyu on 2019/3/17.
//

#ifndef SIMPLEHTTPSERVER_LOGGER_H
#define SIMPLEHTTPSERVER_LOGGER_H

#include <Mutex.h>
#include <ConditionLock.h>
#include <memory>
#include <MutexLockGuard.h>
#include "Buffer.h"

namespace SimpleServer {
    namespace detail {
        void __OutputToLogFile(const char *msg);
        class LoggerBuffer{
        public:
            const static size_t BUFFER_SIZE=4096;
            explicit LoggerBuffer(){
                this->__Buffer=new char[BUFFER_SIZE];
            }
            ~LoggerBuffer(){
                delete[] this->__Buffer;
            }
            bool append(const char *msg,size_t size){
                if(this->__BufferSize+size>BUFFER_SIZE)
                {
                    return false;
                }
                memcpy(this->__Buffer+__BufferSize,msg,size);
                __BufferSize+=size;
                return true;
            }
            char *getBuffer(){
                return this->__Buffer;
            }
            size_t getSize(){
                return this->__BufferSize;
            }
        private:
            /*
             *  This Buffer not have '\0' as
             *  the end of line. If you want
             *  to make it as string, you should
             *  add it.
             */
            char *__Buffer;
            size_t __BufferSize{};
        };
        using BufferPtr=std::unique_ptr<LoggerBuffer>;
        using BufferVector=std::vector<BufferPtr>;
        class LoggerThread {
        public:
            const static int FLUSH_INTERVAL=5;
            const static int EMPTY_BUFFER_SIZE=5;
            const static int FULL_BUFFER_SIZE=5;
            LoggerThread():isRunning(true){
            }
            void Start();
            bool getStatus(){
                return isRunning;
            }void stop(){
                this->isRunning=false;
            }
        private:
            bool isRunning;
            std::vector<BufferPtr>buffer;
        };
    }
}


#endif //SIMPLEHTTPSERVER_LOGGER_H
