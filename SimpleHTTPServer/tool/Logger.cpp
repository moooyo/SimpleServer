//
// Created by lengyu on 2019/3/17.
//

#include "Logger.h"
#include <Mutex.h>
#include <ConditionLock.h>
#include <memory>
#include <fcntl.h>
#include "Buffer.h"

//this mutex lock is due to protect next four member
using namespace SimpleServer;
using namespace Logger;
void LoggerThread::Start() {
    this->isRunning=true;
    const static char *filename="/home/lengyu/Document/test.log";
    while(isRunning){
        {
            MutexLockGuard lockGuard(__mutex);
            if(__FulledBuffer.empty())
            {
                __condition.waitForSeconds(FLUSH_INTERVAL);
            }
            auto diff=__EmptyBuffer.size()- SimpleServer::Logger::LoggerThread::EMPTY_BUFFER_SIZE;
            if(diff>0)
            {
                for(int i=0;i<diff;++i)
                {
                    __EmptyBuffer.push_back(std::make_unique<LoggerBuffer>());
                }
            }
            for(auto &i:__FulledBuffer){
                this->buffer.push_back(i);
            }
            __FulledBuffer.clear();
        }
        int filefd=open(filename,O_WRONLY|O_APPEND);
        for(auto &i:buffer){
            std::printf("write log file!");
            write(filefd,i->getBuffer(),i->getSize());
        }
        close(filefd);
    }
}
