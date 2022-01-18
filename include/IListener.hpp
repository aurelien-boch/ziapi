#ifndef ILISTENER_HPP
#define ILISTENER_HPP

#include <functional>

//TODO demander a victoire de relire tout les commentaires pour trouver une meilleure formulation
namespace api
{
    /**
     * @interface This interface defines the pipeline listener basic behavior.
     */
    class IListener
    {
        public:
            /**
             * @brief This type refers to the callback to be called when a complete packet is received.
             * The first parameter of the std::function is a vector of std::byte that will contain all packet data
             * as bytes.
             * The second parameter of the std::function is a const reference to a Client struct. It refers to the
             * client that sent the packet.
             */
            using packetRecievedCallback = std::function<void (std::vector<std::byte> &&packet, Client const &client)>;

            /**
             * @brief This method will start listener when called. If the listener is already started, it should throw
             * an exception.
             */
            virtual void listen() = 0;

            /**
             * @brief This method will stop the listener when called. If the listener is already stopped, it should
             * throw an exception.
             */
            void stop() = 0;

            /**
             * @brief This method will change the callback function that will be called when a complete packet is
             * received.
             */
            virtual void onPacket(packetRecievedCallback &&cb) = 0 noexcept;
    };
}

#endif //ILISTENER_HPP
