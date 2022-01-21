#ifndef PIPELINECONFIG_HPP
#define PIPELINECONFIG_HPP

#include <string>
#include <vector>

namespace api
{
    /**
     * @struct PipelineConfig
     * @brief This structure defines a type that will be used to provide configuration to the PipelineManager
     * @warning As the (modules / listener / parser / sender) are loaded by path. If templates are different, the
     * libraries will be incompatibles. To prevent undefined behavior due to incompatible libraries, another `extern "C"`
     * function can be used, it will return the typeid of the template. The core may then, check the typeid of all libs
     * and compare if they are the same (modules may have two templates typeids (the request one and the response one)).
     */
    struct PipelineConfig
    {
        /**
         * @brief This string refers to the path of the listener library.
         */
        std::string listenerPath;

        /**
         * @brief This string refers to the path of the parser library.
         */
        std::string parserPath;

        /**
         * @brief This string refers to the path of the sender library.
         */
        std::string senderPath;

        /**
         * @brief This vector of string contains the path of all the modules that will be loaded.
         * @warning The modules should be loaded in the order they are in the vector.
         */
        std::vector<std::string> modulesPaths;
    };
}

#endif //PIPELINECONFIG_HPP
