//
// Created by lengyu on 2019/3/17.
//

#include "Logger.h"
#include <Mutex.h>
#include <ConditionLock.h>
#include <memory>
#include <fcntl.h>
#include <iostream>
#include "Buffer.h"

//this mutex lock is due to protect next four member
using namespace SimpleServer;
using namespace detail;
Mutex __mutex;
ConditionLock __condition(__mutex);
BufferPtr __CurrentBuffer=std::make_unique<LoggerBuffer>();
BufferVector  __EmptyBuffer;
BufferVector  __FulledBuffer;
void LoggerThread::Start() {
    this->isRunning=true;
    const static char *filename="/home/lengyu/test.log";
    while(isRunning){
        {
            MutexLockGuard lockGuard(__mutex);
            if(__FulledBuffer.empty())
            {
                while(__condition.waitForSeconds(FLUSH_INTERVAL))
                {
                    if(__CurrentBuffer->getSize()>0) {
                        auto NewCurrentBuffer = std::make_unique<LoggerBuffer>();
                        __CurrentBuffer.swap(NewCurrentBuffer);
                        __FulledBuffer.push_back(std::move(NewCurrentBuffer));
                        NewCurrentBuffer.reset(nullptr);
                    }
                }
            }
            int diff= static_cast<int >(__EmptyBuffer.size())- SimpleServer::detail::LoggerThread::EMPTY_BUFFER_SIZE;
            if(diff>0)
            {
                std::cout<<diff<<std::endl;
                int end=diff<5?diff:5;
                for(int i=0;i<end;++i)
                {
                    __EmptyBuffer.push_back(std::make_unique<LoggerBuffer>());
                }
            }
            this->buffer.swap(__FulledBuffer);
        }
        int filefd=open(filename,O_WRONLY|O_APPEND|O_CREAT,S_IWUSR|S_IRUSR);
        for(auto &i:buffer){
            write(filefd,i->getBuffer(),i->getSize());
        }
        buffer.clear();
        close(filefd);
    }
}
/*
 * This Function can be used only
 * in server. User shouldn't use
 * it
 */
void __AppendToLogFile(const char *msgline, size_t len) {
    MutexLockGuard lock(__mutex);
    if(!__CurrentBuffer->append(msgline, len))
    {
        __FulledBuffer.push_back(std::move(__CurrentBuffer));
        __CurrentBuffer.reset(nullptr);
        if(__EmptyBuffer.empty())
        {
            auto NewCurrentBuffer=std::make_unique<LoggerBuffer>();
            __CurrentBuffer.swap(NewCurrentBuffer);
        }else{
            auto NewCurrentBuffer=std::move(__EmptyBuffer.back());
            //make moved object can be desctructed
            __EmptyBuffer.back().reset(nullptr);
            __EmptyBuffer.pop_back();
            __CurrentBuffer.swap(NewCurrentBuffer);
            __FulledBuffer.push_back(std::move(NewCurrentBuffer));
        }
        __CurrentBuffer->append(msgline,len);
        if(__FulledBuffer.size()>LoggerThread::FULL_BUFFER_SIZE)
        {
            __condition.notify();
        }
    }
}

void __OutputToLogFile(const char *msg) {
    size_t len=strlen(msg);
    __AppendToLogFile(msg,len);
}
