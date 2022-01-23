#ifndef HTTPLISTENER_HPP
#define HTTPLISTENER_HPP

#include <IListener.hpp>

namespace api::listeners
{
    class HttpListener : public IListener
    {
        public:
            HttpListener();

            void listen() override;

            void stop() override;

            void onPacket(packetReceivedCallback &&cb) noexcept override;

        private:
            packetReceivedCallback _callback;
    };
}

#endif //HTTPLISTENER_HPP
