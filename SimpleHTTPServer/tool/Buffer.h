//
// Created by lengyu on 2019/3/4.
//

#ifndef SIMPLEHTTPSERVER_BUFFER_H
#define SIMPLEHTTPSERVER_BUFFER_H

#include <cstddef>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

namespace SimpleServer {
    namespace tool {
        class Buffer {
        public:
            static const char CRLF[];
            const static size_t initialSize=1024;
            explicit Buffer(size_t initSize=initialSize):readerIndex(0){
                buffer.reserve(initSize);
            }
            const char* peek(){
                return this->begin()+readerIndex;
            }
            size_t readableBytes(){
                return this->buffer.size()-readerIndex;
            }
            const char* findCRLF(){
                const char* crlf=std::search(peek(),end(),CRLF,CRLF+2);
                return crlf==end()?NULL:crlf;
            }
            const char* findEOL(){
                const void* eol=std::memchr(peek(),'\n',readableBytes());
                return eol==NULL?NULL:static_cast<const char *>(eol);
            }
            void read(size_t size){
                this->readerIndex+=size;
            }
            const char* end(){
                return &*buffer.end();
            }
            void write(char buf[],ssize_t n)
            {
                for(int i=0;i<n;++i)
                {
                    buffer.push_back(buf[i]);
                }
            }
            void printBuffer()
            {
                //only used in debug
                for(const char &c : this->buffer)
                {
                    std::printf("%c",c);
                }
            }

        private:
            char *begin(){
                return &*buffer.begin();
            }
            std::vector<char> buffer;
            size_t readerIndex;
        };

    }
}


#endif //SIMPLEHTTPSERVER_BUFFER_H
