#ifndef IPIPELINEMANAGER_HPP
#define IPIPELINEMANAGER_HPP

#include <vector>
#include <cstddef>

#include "IClient.hpp"
#include "types/PipelineConfig.hpp"

namespace api
{
    /**
     * @interface IPipelineManager
     * @brief Defines the basic behavior of the pipeline manager.
     */
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

            /**
             * @brief Configures the pipeline by loading modules, parsers, senders, listeners.
             * @param config[in] The PipelineConfig struct containing all paths to libraries.
             * @warning If the PipelineManager is unable to load the library, it should throw an exception.
             */
            void configurePipeline(PipelineConfig const &config);

        protected:
            /**
             * @brief Handles a client request by calling the parser, the modules and the sender.
             * @param packet[in] Refers to the packet that was sent by the client.
             * @param client[in] Refers to the client that sent the packet.
             */
            virtual void processRequest(std::vector<std::byte> &&packet, IClient const &client) noexcept = 0;
    };
}

#endif //IPIPELINEMANAGER_HPP
