#ifndef IPIPELINEMANAGER_HPP
#define IPIPELINEMANAGER_HPP

#include <vector>
#include <cstddef>
#include "IClient.hpp"

namespace api
{
    /**
     * @interface IPipelineManager
     * @brief Defines the pipeline manager basic behavior.
     * @tparam RequestDataType Refers to the request data type. It will be transferred from the
     * parser to the modules.
     * @tparam ResponseDataType Refers to the request response data type that will be
     * transferred between the modules and the IReplySender.
     */
    template <class RequestDataType, class ResultDataType>
    class IPipelineManager
    {
        public:
            /**
             * @brief Starts the pipeline listener when called. If the listener is already started, it should throw an
             * exception.
             */
            virtual void listen() = 0;

            /**
             * @brief Stops the pipeline listener when called. If the listener is already stopped, it should throw an
             * exception.
             */
            void stop() = 0;

        private:
            /**
             * @brief Handles a client request by calling the parser, the modules and the sender.
             * @param packet[in] Refers to the packet that was sent by the client.
             * @param client[in] Refers to the client that sent the packet.
             */
            virtual void serveRequest(std::vector<std::byte> &&packet, Client const &client) noexcept = 0;
    };
}

#endif //IPIPELINEMANAGER_HPP
