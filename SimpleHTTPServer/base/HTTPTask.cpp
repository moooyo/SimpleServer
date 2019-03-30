//
// Created by lengyu on 2019/3/8.
//

#include <io.h>
#include <Buffer.h>
#include <HTTP/httpContext.h>
#include <sys/socket.h>
#include <HTTP/httpResponse.h>
#include <errHelp.h>
#include "Logger.h"
#include <map>
#include <unistd.h>
#include <fcntl.h>
#include <Logging.h>
#include <Cache.h>
#include "HTTPTask.h"
#include "ListenServer.h"

using namespace SimpleServer;

std::tuple<int, std::string> ParseURI(const std::string &uri);
void HTTPTask::Run() {
    const static int BUFFER_SIZE = 4096;
    tool::Buffer readBuffer;
    readBuffer.printBuffer();
    char buffer[BUFFER_SIZE];
    ssize_t read_size = 0;
    net::httpContext context;
    while ((read_size = read(this->sockfd, buffer, BUFFER_SIZE)) && read_size > 0) {
        readBuffer.write(buffer, read_size);
        context.parseRequest(readBuffer);
        if (context.parseFinished()) {
            break;
        }
    }
    ServerKey key(context.getRequest().getHost(),this->port);
    LOG_INFO<<"Accept: host="<<context.getRequest().getHost()<<" port="<<this->port;
    auto config=ListenServer::ServerConfig()[key];
    auto ret = ParseURI(context.getRequest().getUri());
    std::string SERVER_ROOT = config.Root();
    LOG_INFO<<"SERVER_ROOT:"<<SERVER_ROOT;
    std::string type = std::get<1>(ret);
    int postfix_attr = std::get<0>(ret);
    LOG_INFO<<"URI:"<<context.getRequest().getUri()<<" type:"<<postfix_attr;
    switch (postfix_attr) {
        case 0:
            todoStatic(SERVER_ROOT,context, type);
            break;
        case 1:
            todoDynamic(SERVER_ROOT,context, type);
            break;
        default:
            tool::panic("match postfix error!");
            break;
    }
    close(this->sockfd);
}

void HTTPTask::todoDynamic(const std::string &SERVER_ROOT,const net::httpContext &context, std::string &content_type) {

}

void HTTPTask::todoStatic(const std::string &SERVER_ROOT,const net::httpContext &context, std::string &content_type) {
    const static int BUFFER_SIZE = 4096;
    auto Cache = tool::SingletonCache::getInstance();
    const tool::CacheKey key(context.getRequest());
    auto CacheNode = Cache->getCache(key);
    net::httpResponse response(true);
    response.resetSussessHeader();
    response.setContentType(content_type);
    if (CacheNode == nullptr) {
        std::string filename = SERVER_ROOT + context.getRequest().getUri();
        LOG_INFO<<"filename:"<<filename;
        int filefd = open((filename).c_str(), O_RDONLY);
        char buffer[BUFFER_SIZE];
        ssize_t read_size = 0;
        std::string str = std::string("");
        while ((read_size = read(filefd, buffer, BUFFER_SIZE - 1)) && read_size > 0) {
            buffer[read_size] = '\0';
            str.append(std::string(buffer));
        }
        //to RAII it
        close(filefd);
        response.setBody(str);
        const std::string body = response.getResponseBody();
        bool ret = Cache->insert(body.c_str(), body.length(), key);
        LOG_INFO<<"URI: "<<context.getRequest().getUri()<<" cache miss insert:"<<ret<<" size="<<body.length();
    } else {
        LOG_INFO<<"URI: "<<context.getRequest().getUri()<<" cache hit";
        std::string body(CacheNode->getBuffer());
        response.setBody(body);
    }
    response.sendResponse(this->sockfd);
}

/*
 *  This function return the
 *  requests header's URI's type
 *  example: /index.html will
 *  will return 0. It means it's
 *  static file.
 */
std::tuple<int, std::string> ParseURI(const std::string &uri) {
    const static std::unordered_map<std::string, std::string> static_mime_type({
                                                                                       {"css",   "text/css;charset=UTF-8"},
                                                                                       {"htm",   "text/html;charset=UTF-8"},
                                                                                       {"html",  "text/html;charset=UTF-8"},
                                                                                       {"js",    "application/javascript; charset=utf-8"},
                                                                                       {"gif",   "image/gif"},
                                                                                       {"jpe",   "image/jpeg"},
                                                                                       {"jpeg",  "image/jpeg"},
                                                                                       {"jpg",   "image/jpeg"},
                                                                                       {"svg",   "image/svg+xml"},
                                                                                       {"tif",   "image/tiff"},
                                                                                       {"tiff",  "image/tiff"},
                                                                                       {"mp2",   "video/mpeg"},
                                                                                       {"mpeg",  "video/mpeg"},
                                                                                       {"movie", "video/x-sgi-movie"},
                                                                                       {"woff",  "font/woff2"},
                                                                                       {"ttf",   "application/octet-stream"},
                                                                                       {"woff2", "font/woff2"},
                                                                                       {"png",   "image/png"},
                                                                               });
    const static std::unordered_map<std::string, std::string> dynamic_mime_type({
                                                                                        {"php", "text/html;charset=UTF-8"},
                                                                                });
    auto pos = uri.rfind('.');
    if (pos == std::string::npos) {
        //static
        return std::tuple<int, std::string>(0, "");
    }
    std::string postfix = uri.substr(pos + 1);
    if (static_mime_type.count(postfix) != 0) {
        return std::tuple<int, std::string>(0, static_mime_type.find(postfix)->second);
    } else if (dynamic_mime_type.count(postfix) != 0) {
        return std::tuple<int, std::string>(1, dynamic_mime_type.find(postfix)->second);
    }
    return std::tuple<int, std::string>(0, "");
}
