#ifndef HTTPPACKETPARSER_HPP
#define HTTPPACKETPARSER_HPP

#include <IPacketParser.hpp>
#include <types/HttpRequest.hpp>

namespace api::parsers
{
    class HttpPacketParser : IPacketParser<HTTPRequest>
    {
        public:
            [[nodiscard]] HTTPRequest parse(std::vector<std::byte> const &rawRequest) override;
    };
}

#endif //HTTPPACKETPARSER_HPP
