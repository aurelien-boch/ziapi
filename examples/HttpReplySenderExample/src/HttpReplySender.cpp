#include <iostream>
#include "HttpReplySender.hpp"

namespace api::senders
{
    void HttpReplySender::send(const HTTPReply &reply, const IClient &client)
    {
        std::cout << "Sending reply to client !" << std::endl;
    }
}
