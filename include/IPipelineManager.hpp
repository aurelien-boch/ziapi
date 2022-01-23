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
            virtual ~IPipelineManager() = default;

            /**
             * @brief Starts the pipeline listener when called. If the listener is already started, it should throw an
             * exception.
             */
            virtual void listen() = 0;

            /**
             * @brief Stops the pipeline listener when called. If the listener is already stopped, it should throw an
             * exception.
             */
            virtual void stop() = 0;

            /**
             * @brief Configures the pipeline by loading modules, parsers, senders, listeners.
             * @param config[in] The PipelineConfig struct containing all paths to libraries.
             * @warning If the PipelineManager is unable to load the library, it should throw an exception.
             */
            virtual void configurePipeline(PipelineConfig const &config) = 0;
    };
}

#endif //IPIPELINEMANAGER_HPP
