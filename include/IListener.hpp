#ifndef ILISTENER_HPP
#define ILISTENER_HPP

#include <cstddef>
#include <vector>
#include <functional>

#include "IClient.hpp"

namespace api
{
    /**
     * @interface HttpListenerExample.
     * @brief Defines the basic behavior of the pipeline listener.
     */
    class IListener
    {
        public:
            virtual ~IListener() = default;

            /**
             * @typedef packetReceivedCallback
             * @brief Defines the callback that will be called when a complete packet is received.
             * @param [in]packet Refers to a vector containing the raw data sent by the client as bytes.
             * @param [in]client Refers to the client that sent the packet.
             */
            using packetReceivedCallback = std::function<void (std::vector<std::byte> &&packet, IClient const &client)>;

            /**
             * @brief Starts the listener when called. If the listener is already started, it should throw an exception.
             */
            virtual void listen() = 0;

            /**
             * @brief Stops the listener when called. If the listener is already stopped, it should throw an exception.
             */
            virtual void stop() = 0;

            /**
             * @brief Changes the callback function that will be called when a complete packet is received.
             */
            virtual void onPacket(packetReceivedCallback &&cb) noexcept = 0;
    };
}

#endif //ILISTENER_HPP
