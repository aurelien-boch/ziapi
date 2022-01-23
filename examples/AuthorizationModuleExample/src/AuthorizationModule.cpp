#include <iostream>
#include "AuthorizationModule.hpp"

namespace api::modules
{
    void AuthorizationModule::process(HTTPRequest &request, HTTPReply &response)
    {
        std::cout << "Processing request !" << std::endl;
    }
}
