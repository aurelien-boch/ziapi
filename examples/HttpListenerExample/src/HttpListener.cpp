#include <iostream>

#include "HttpListener.hpp"

namespace api::listeners
{
    HttpListener::HttpListener() :
        _callback{}
    {}

    void HttpListener::listen()
    {
        //put the event loop here
        std::cout << "Listening !" << std::endl;
    }

    void HttpListener::stop()
    {
        //stop the event loop here
        std::cout << "Stopped !" << std::endl;
    }

    void HttpListener::onPacket(IListener::packetReceivedCallback &&cb) noexcept
    {
        _callback = std::forward<packetReceivedCallback>(cb);
    }
}
