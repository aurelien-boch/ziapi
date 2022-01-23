#ifndef HTTPREPLYSENDER_HPP
#define HTTPREPLYSENDER_HPP

#include <IReplySender.hpp>
#include <types/HttpReply.hpp>

namespace api::senders
{
    class HttpReplySender : IReplySender<HTTPReply>
    {
        public:
            void send(HTTPReply const &reply, IClient const &client) override;
    };
}

#endif //HTTPREPLYSENDER_HPP
