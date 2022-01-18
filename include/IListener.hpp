#ifndef ILISTENER_HPP
#define ILISTENER_HPP

#include <functional>

namespace api
{
    /**
     * @interface IListener.
     * @brief This interface defines the basic behavior of the pipeline listener.
     */
    class IListener
    {
        public:
            /**
             * @typedef packetReceivedCallback
             * @brief This type refers to the callback that will be called when a complete packet is received.
             * @param [in]packet This parameter refers to a vector containing the raw data sent by the client as bytes.
             * @param [in]client This parameter refers to the client that sent the packet.
             */
            using packetReceivedCallback = std::function<void (std::vector<std::byte> &&packet, Client const &client)>;

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
            virtual void onPacket(packetRecievedCallback &&cb) = 0 noexcept;
    };
}

#endif //ILISTENER_HPP
