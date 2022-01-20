#ifndef IPACKETPARSER_HPP
#define IPACKETPARSER_HPP

#include <vector>
#include <cstddef>

namespace api
{
    /**
     * @interface IPacketParser
     * @brief Defines the basic behavior of the pipeline packet parser.
     * @tparam RequestDataType Refers to the request data type to be used with modules trough
     * the core.
     */
    template <class RequestDataType>
    class IPacketParser
    {
        public:
            /**
             * @brief Parses the request from raw bytes to the type of the request.
             * @param rawRequest[in] Refers to the raw request received from the client as bytes.
             * @return The raw request converted to the request data type.
             */
            [[nodiscard]] virtual RequestDataType parse(std::vector<std::byte> const &rawRequest) = 0;
    };
}

#endif //IPACKETPARSER_HPP
