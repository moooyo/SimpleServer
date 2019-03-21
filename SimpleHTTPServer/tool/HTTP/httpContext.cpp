//
// Created by lengyu on 2019/3/4.
//

#include "httpContext.h"

using namespace SimpleServer;

bool net::httpContext::parseRequestLine(const char *begin, const char *end) {
    bool success = false;
    const char *start = begin;
    const char *space = std::find(start, end, ' ');
    if (space != end) {
        request.setMethod(start, space);
        start = space + 1;
        space = std::find(start, end, ' ');
        if (space != end) {
            const char *question = std::find(start, space, '?');
            if (question != space) {
                request.setUri(start, question);
                request.setQuery(question, space);
            } else {
                request.setUri(start, space);
            }
            start = space + 1;
            success = end - start == 8 && std::equal(start, end - 1, "HTTP/1.");
            if (success) {
                if (*(end - 1) == '1') {
                    request.setVersion(HTTP_VERSION::V1);
                } else if (*(end - 1) == '2') {
                    request.setVersion(HTTP_VERSION::V2);
                } else {
                    request.setVersion(HTTP_VERSION::NOT_SUPPORT);
                    success = false;
                }
            }

        }
    }
    return success;
}

bool net::httpContext::parseRequest(tool::Buffer &buf) {
    bool ok = true;
    bool hasMore = true;
    while (hasMore) {
        if (this->parseState == httpRequestParseState::ExpectRequestLine) {
            const char *crlf = buf.findCRLF();
            if (crlf) {
                ok = parseRequestLine(buf.peek(), crlf);
                if (ok) {
                    //this maybe should be crlf-buf.peek+1
                    buf.read(crlf - buf.peek());
                    this->parseState = httpRequestParseState::ExpectHeaders;
                } else {
                    hasMore = false;
                }
            } else {
                hasMore = false;
            }
        } else if (this->parseState == httpRequestParseState::ExpectHeaders) {
            const char *crlf = buf.findCRLF();
            if (crlf) {
                const char *key = std::find(buf.peek(), crlf, ':');
                if (key != crlf) {
                    request.appendHeader(buf.peek(), key, crlf);
                } else {
                    this->parseState = httpRequestParseState::Finished;
                    hasMore = false;
                }
                //this maybe should be crlf-buf.peek+1
                buf.read(crlf - buf.peek());
            } else {
                hasMore = false;
            }
        } else if (this->parseState == httpRequestParseState::ExpectBody) {

        }

    }
    return ok;
}
