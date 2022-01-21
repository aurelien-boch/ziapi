#ifndef HTTPREPLY_HPP
#define HTTPREPLY_HPP

#include <string>
#include <unordered_map>

namespace api
{
    /**
     * @struct HTTPReply
     * @brief This structure defines an example type for HTTP(S) responses.
     */
    struct HTTPReply
    {
        /**
         * @brief This field refers to the response code.
         */
        std::uint16_t code;

        /**
         * @brief This string refers to the response body.
         */
        std::string body;

        /**
         * @brief This map of strings refers to the response headers.
         * The key represents the header name and the value represents it's value.
         */
        std::unordered_map<std::string, std::string> headers;
    };
}

#endif //HTTPREPLY_HPP
