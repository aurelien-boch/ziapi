#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <string>
#include <any>
#include <vector>
#include <unordered_map>

namespace api
{
    /**
     * @struct HTTPRequest
     * @brief Defines an example type for HTTP(S) reply.
     */
    struct HTTPRequest
    {
        /**
         * @brief The URI that has been queried by user.
         */
        std::string uri;

        /**
         * @brief The method used by the client to query the server.
         * example: POST / GET / PUT ...
         */
        std::string method;

        /**
         * @brief The request body.
         */
        std::string body;

        /**
         * @brief The query options provided by the client.
         * The key represents the value and the value represents the query value.
         */
        std::unordered_map<std::string, std::string> queryOptions;

        /**
         * @brief The query options provided by the client.
         * The key represents the value and the value represents the query value.
         */
        std::unordered_map<std::string, std::string> headers;

        /**
         * @brief Data that can be passed between middlewares through the request.
         * The key represents the data name and the value is an any that can be used to store any type of data.
         */
        std::unordered_map<std::string, std::any> middlewareData;
    };
}

#endif //HTTPREQUEST_HPP
