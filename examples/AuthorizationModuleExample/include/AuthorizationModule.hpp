#ifndef AUTHORIZATIONMODULE_HPP
#define AUTHORIZATIONMODULE_HPP

#include <IModule.hpp>
#include <types/HttpRequest.hpp>
#include <types/HttpReply.hpp>

namespace api::modules
{
    class AuthorizationModule : public IModule<HTTPRequest, HTTPReply>
    {
        public:
            void process(HTTPRequest &request, HTTPReply &response) override;
    };
}

#endif //AUTHORIZATIONMODULE_HPP
