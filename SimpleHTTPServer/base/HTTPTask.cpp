//
// Created by lengyu on 2019/3/8.
//

#include <io.h>
#include <Buffer.h>
#include <HTTP/httpContext.h>
#include <HTTP/httpResponse.h>
#include <errHelp.h>
#include "HTTPTask.h"
using namespace SimpleServer;
const static std::string SERVER_ROOT="/home/lengyu/html";
std::tuple<int,std::string> ParseURI(const std::string &uri);
void HTTPTask::Run() {
    const int BUFFER_SIZE=4096;
    tool::Buffer readBuffer;
    readBuffer.printBuffer();
    char buffer[BUFFER_SIZE];
    ssize_t read_size=0;
    net::httpContext context;
    while((read_size=read(this->sockfd, buffer,BUFFER_SIZE))&&read_size>0)
    {
        readBuffer.write(buffer,read_size);
        context.parseRequest(readBuffer);
        if(context.parseFinished())
        {
            break;
        }
    }
    auto ret=ParseURI(context.getRequest().getUri());
    std::string type=std::get<1>(ret);
    int postfix_attr=std::get<0>(ret);
    switch (postfix_attr){
        case 0:
            todoStatic(context,type);
            break;
        case 1:
            todoDynamic(context,type);
            break;
        default:
            tool::panic("match postfix error!");
            break;
    }
    close(this->sockfd);
    std::printf("closed!\n");
}

void HTTPTask::todoDynamic(const net::httpContext &context,std::string &content_type) {
    std::printf("dynamic:uri=%s\n",context.getRequest().getUri().c_str());

}
void HTTPTask::todoStatic(const net::httpContext &context,std::string &content_type) {
    const static int BUFFER_SIZE=4096;
    std::string filename=SERVER_ROOT+context.getRequest().getUri();
    net::httpResponse response(true);
    response.resetSussessHeader();
    response.setContentType(content_type);
    //to delete
    std::printf("%s\n",filename.c_str());
    FILE *file=fopen(filename.c_str(),"r");
    char buffer[BUFFER_SIZE];
    ssize_t read_size=0;
    std::string str=std::string("");
    while((read_size = fread(buffer, 1, BUFFER_SIZE, file)) && read_size > 0)
    {
        str.append(std::string(buffer));
    }
    //to RAII it
    fclose(file);
    response.setBody(str);
    response.sendResponse(this->sockfd);
}

/*
 *  This function return the
 *  requests header's URI's type
 *  example: /index.html will
 *  will return 0. It means it's
 *  static file.
 */
std::tuple<int,std::string> ParseURI(const std::string &uri)
{
    const static std::string content_type[]={
            "text/html; charset=UTF-8",
            "application/javascript; charset=utf-8",
            "application/pdf;",
    };
    static std::string static_list[]={
            "html","htm","js","pdf","css",
    };
    auto pos=uri.rfind('.');
    if(pos==std::string::npos)
    {
        //dynamic
        return std::tuple<int,std::string>(1,content_type[0]);
    }
    std::string postfix=uri.substr(pos+1);
    if(postfix==static_list[0]||postfix==static_list[1])
    {
        return std::tuple<int,std::string>(0,content_type[0]);
    }else if(postfix==static_list[2]||postfix==static_list[3])
    {
        return std::tuple<int,std::string>(0,content_type[1]);
    }else if(postfix==static_list[3])
    {
        return std::tuple<int,std::string>(1,content_type[2]);
    }
    return std::tuple<int,std::string>(0,content_type[0]);
}
