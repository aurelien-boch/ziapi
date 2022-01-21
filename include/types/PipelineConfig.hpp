#ifndef PIPELINECONFIG_HPP
#define PIPELINECONFIG_HPP

#include <string>
#include <vector>

namespace api
{
    /**
     * todo
     * Warn user that if incompatibles modules / listeners / parsers / senders are loaded, the behavior is undefined.
     * It can however be checked using typeid (decltype won't work since it's compile time). To check just add a second
     * extern "C" function that will return the typeid of the parameters and check it in the PipelineManager using the
     * typeid of the types provided in the template, if it matches, * ok, otherwise, an error must be thrown.
     */
    struct PipelineConfig
    {
        /**
         * todo
         */
        std::string listenerPath;

        /**
         * todo
         */
        std::string parserPath;

        /**
         * todo
         */
        std::string senderPath;

        /**
         * todo
         */
        std::vector<std::string> modulesPaths;
    };
}

#endif //PIPELINECONFIG_HPP
