//
// Created by lengyu on 2019/3/4.
//

#ifndef SIMPLEHTTPSERVER_HTTPCONTEXT_H
#define SIMPLEHTTPSERVER_HTTPCONTEXT_H

#include "Buffer.h"
#include "httpRequest.h"

namespace SimpleServer {
    namespace net {
        enum class httpRequestParseState
        {
            ExpectRequestLine,
            ExpectHeaders,
            ExpectBody,
            Finished,
        };
        class httpContext {
        public:
            httpContext():parseState(httpRequestParseState::ExpectRequestLine){}
            void reset()
            {
                parseState=httpRequestParseState ::ExpectRequestLine;
                httpRequest temp;
                this->request.swap(temp);
            }
            bool parseRequest(SimpleServer::tool::Buffer& buf);
            const httpRequest& getRequest() const
            {
                return request;
            }
            const httpRequestParseState& getState()
            {
                return this->parseState;
            }
            bool parseFinished()
            {
                return this->parseState==httpRequestParseState ::Finished;
            }
            bool parseRequestLine(const char *begin, const char *end);
        private:
            httpRequest request;
            httpRequestParseState parseState;
        };

    }
}

#endif //SIMPLEHTTPSERVER_HTTPCONTEXT_H
