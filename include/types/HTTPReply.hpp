#ifndef HTTPREPLY_HPP
#define HTTPREPLY_HPP

#include <vector>
#include <string>

namespace api
{
    /**
     * todo
     */
    struct HTTPReply
    {
        /**
         * todo
         */
        std::uint16_t code;

        /**
         * todo
         */
        std::string body;

        /**
         * todo
         */
        std::vector<std::string> headers;
    };
}

#endif //HTTPREPLY_HPP
