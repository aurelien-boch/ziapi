#include <iostream>
#include "HttpPacketParser.hpp"

namespace api::parsers
{

    HTTPRequest HttpPacketParser::parse(const std::vector<std::byte> &rawRequest)
    {
        std::cout << "Parsing the request !" << std::endl;
        return {};
    }
}
