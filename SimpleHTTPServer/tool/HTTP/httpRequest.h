//
// Created by lengyu on 2019/3/3.
//

#ifndef UNTITLED3_HTTPREQUEST_H
#define UNTITLED3_HTTPREQUEST_H

#include <string>
#include <cstring>
#include <unordered_map>
namespace SimpleServer{
    namespace net {
        enum class HTTP_METHOD {
            GET, POST, PUT, PATCH, DELETE, UPDATE, NOT_SUPPORT
        };

        inline std::string methodToString(HTTP_METHOD method) {
            switch (method) {
                case HTTP_METHOD::GET:
                    return "GET";
                case HTTP_METHOD::DELETE:
                    return "DELETE";
                case HTTP_METHOD::PATCH:
                    return "PATCH";
                case HTTP_METHOD::POST:
                    return "POST";
                case HTTP_METHOD::PUT:
                    return "PUT";
                case HTTP_METHOD::UPDATE:
                    return "UPDATE";
                default:
                    return "NOT_SUPPORT";
            }
        }

        inline HTTP_METHOD stringToMethod(const std::string &buf) {
            if (buf=="GET") {
                return HTTP_METHOD::GET;
            } else if (buf=="POST") {
                return HTTP_METHOD::POST;
            } else if (buf=="DELETE") {
                return HTTP_METHOD::DELETE;
            } else if (buf=="PATCH") {
                return HTTP_METHOD::PATCH;
            } else if (buf=="PUT") {
                return HTTP_METHOD::PUT;
            } else if (buf=="UPDATE") {
                return HTTP_METHOD::UPDATE;
            } else {
                return HTTP_METHOD::NOT_SUPPORT;
            }
        }

        enum class HTTP_VERSION {
            V1, V2, NOT_SUPPORT
        };

        inline std::string versionToString(HTTP_VERSION version) {
            switch (version) {
                case HTTP_VERSION::V1:
                    return "1.1";
                case HTTP_VERSION::V2:
                    return "1.2";
                default:
                    return "0.0";
            }
        }

        inline HTTP_VERSION stringToVersion(const std::string &buf) {
            if (buf=="1.1") {
                return HTTP_VERSION::V1;
            } else if (buf=="1.2") {
                return HTTP_VERSION::V2;
            } else {
                return HTTP_VERSION::NOT_SUPPORT;
            }
        }

        class httpRequest {
        public:
            httpRequest() = default;
            void setVersion(HTTP_VERSION v)
            {
                this->version=v;
            }
            const HTTP_VERSION & getVersion() const
            {
                return this->version;
            }
            void setMethod(const char *start,const char *end)
            {
                std::string temp(start,end);
                this->method=stringToMethod(temp);
            }
            const HTTP_METHOD & getMethod() const
            {
                return this->method;
            }
            void setUri(const char *start, const char *end)
            {
                this->uri.assign(start,end);
            }
            const std::string& getUri() const
            {
                return this->uri;
            }
            void setQuery(const char *start, const char *end)
            {
                this->query.assign(start,end);
            }
            const std::string& getQuery() const
            {
                return this->query;
            }
            void appendHeader(const char *start, const char *steep ,const char *end)
            {
                // key means that a key in header
                std::string key(start,steep);
                ++steep;
                while(steep<end&&isspace(*steep))
                {
                    ++steep;
                }
                std::string value;
                while(steep<end)
                {
                    const char *ptr=end;
                    ptr--;
                    if(!isspace(*ptr))
                    {
                        break;
                    }
                    end--;
                }
                value.assign(steep,end);
                this->headers[key]=value;
            }
            const std::unordered_map<std::string,std::string>& getHeaders() const
            {
                return this->headers;
            }
            void swap(httpRequest &that)
            {
                std::swap(method,that.method);
                std::swap(version,that.version);
                std::swap(uri,that.uri);
                std::swap(query,that.query);
                std::swap(headers,that.headers);
            }
        private:
            HTTP_METHOD method;
            HTTP_VERSION version;
            std::string uri;
            std::string query;
            std::unordered_map<std::string, std::string> headers;
        };
    }
}

#endif //UNTITLED3_HTTPREQUEST_H
