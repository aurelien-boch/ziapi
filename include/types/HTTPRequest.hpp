#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <string>
#include <any>
#include <vector>
#include <unordered_map>

namespace api
{
    /**
     * todo
     */
    struct HTTPRequest
    {
        /**
         * todo
         */
        std::string uri;

        /**
         * todo
         */
        std::string method;

        /**
         * todo
         */
        std::string body;

        /**
         * todo
         */
        std::vector<std::string> headers;

        /**
         * todo
         */
        std::unordered_map<std::string, std::any> middlewareData;
    };
}

#endif //HTTPREQUEST_HPP
