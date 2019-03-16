//
// Created by lengyu on 2019/3/5.
//

#ifndef SIMPLEHTTPSERVER_HTTPRESPONSE_H
#define SIMPLEHTTPSERVER_HTTPRESPONSE_H

#include <unordered_map>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <zconf.h>
#include <iostream>

namespace SimpleServer {
    namespace net {
        class httpResponse {
        public:
            enum class httpStatusCode {
                NOT_SUPPORT,
                SUCCESS = 200,
                MOVED_PERMANNENTLY = 301,
                BAD_REQUEST = 400,
                NOT_FOUND = 404,
            };

            explicit httpResponse(bool close) :
                    statusCode(httpStatusCode::NOT_SUPPORT),
                    closeConnection(close) {}

            void setStatusCode(httpStatusCode code) {
                this->statusCode = code;
            }

            void setStatusMessage(const std::string &message) {
                this->statusMessage = message;
            }

            void setCloseConnection(bool close) {
                this->closeConnection = close;
            }

            bool getCloseConnection() {
                return this->closeConnection;
            }

            void setContentType(const std::string &contentType) {
                addHeader("Content-Type", contentType);
            }

            void addHeader(const std::string &key, const std::string &value) {
                this->headers[key] = value;
            }

            void setBody(const std::string &body) {
                this->body = body;
            }
            void resetSussessHeader();
            void sendResponse(int socketfd);
            const std::string &getResponseBody() const {
                return this->body;
            }
        private:
            std::unordered_map<std::string, std::string> headers;
            httpStatusCode statusCode;
            std::string statusMessage;
            bool closeConnection;
            std::string body;
        };

        void httpResponse::resetSussessHeader() {
            this->setStatusCode(httpStatusCode::SUCCESS);
            this->setStatusMessage("OK");
            this->setCloseConnection(true);
            this->setContentType("text/html;charset=UTF-8");
            const int bufferSize=64;
            char timeStr[bufferSize];
            time_t timenow;
            struct tm timeInfo;
            time(&timenow);
            gmtime_r(&timenow,&timeInfo);
            strftime(timeStr,bufferSize,"%a, %d %b %Y %H:%M:%S GMT",&timeInfo);
            this->addHeader("Date",std::string(timeStr));
            this->addHeader("Server","SimpleServer/1.0");
        }

        void httpResponse::sendResponse(int socketfd) {
            const int BUFFER_SIZE=4096;
            char buffer[BUFFER_SIZE];
            memset(buffer,0,BUFFER_SIZE);
            std::string str;
            sprintf(buffer,"HTTP/1.0 %d %s\r\n",this->statusCode,this->statusMessage.c_str());
            str.append(buffer);
            for (auto &header : this->headers) {
                sprintf(buffer,"%s: %s\r\n", header.first.c_str(), header.second.c_str());
                str.append(buffer);
            }
            sprintf(buffer,"\r\n");
            str.append(buffer);
            write(socketfd,str.c_str(),str.size());
            write(socketfd,this->body.c_str(),this->body.size());
        }
    }
}
#endif //SIMPLEHTTPSERVER_HTTPRESPONSE_H
