#ifndef PIPELINECONFIG_HPP
#define PIPELINECONFIG_HPP

#include <string>
#include <vector>

namespace api
{
    /**
     * @struct PipelineConfig
     * @brief Defines a type that will be used to provide configuration to the PipelineManager
     * @warning As the (modules / listener / parser / sender) are loaded by path. If templates are different, the
     * libraries will be incompatibles. To prevent undefined behavior due to incompatible libraries, another `extern "C"`
     * function can be used, it will return the typeid of the template. The core may then, check the typeid of all libs
     * and compare if they are the same (modules may have two templates typeids (the request one and the response one)).
     */
    struct PipelineConfig
    {
        /**
         * @brief The path of the listener library.
         */
        std::string listenerPath;

        /**
         * @brief The path of the parser library.
         */
        std::string parserPath;

        /**
         * @brief The path of the sender library.
         */
        std::string senderPath;

        /**
         * @brief The path of all the modules that will be loaded.
         * @warning The modules should be loaded in the order they are in the vector.
         */
        std::vector<std::string> modulesPaths;
    };
}

#endif //PIPELINECONFIG_HPP
