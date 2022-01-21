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
     * @brief This structure defines an example type for HTTP(S) reply.
     */
    struct HTTPRequest
    {
        /**
         * @brief This string represents the URI that has been queried by user.
         */
        std::string uri;

        /**
         * @brief This string refers to the method used by the client to query the server.
         * example: POST / GET / PUT ...
         */
        std::string method;

        /**
         * @brief This string refers to the request body.
         */
        std::string body;

        /**
         * @brief This map refers to the query options provided by the client.
         * The key represents the value and the value represents the query value.
         */
        std::unordered_map<std::string, std::string> queryOptions;

        /**
         * @brief This map refers to the query options provided by the client.
         * The key represents the value and the value represents the query value.
         */
        std::unordered_map<std::string, std::string> headers;

        /**
         * @brief This map refers to the data that can be passed between middlewares through the request.
         * The key represents the data name and the value is an any that can be used to store any type of data.
         */
        std::unordered_map<std::string, std::any> middlewareData;
    };
}

#endif //HTTPREQUEST_HPP
