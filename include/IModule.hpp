#ifndef IMODULE_HPP
#define IMODULE_HPP

namespace api
{
    /**
     * @interface AuthorizationModuleExample
     * @brief Defines the basic behavior of a pipeline module.
     * @tparam RequestDataType Refers to the request data type. It will be transferred from the
     * parser to the modules.
     * @tparam ResponseDataType Refers to the request response data type that will be
     * transferred between the modules and the IReplySender.
     */
    template<class RequestDataType, class ResponseDataType>
    class IModule
    {
        public:
            virtual ~IModule() = default;

            /**
             * @brief Runs the pipeline module, mutating the request and/or the request and the response.
             * @param request[in,out] Refers to the request data. It can be read and mutated by modules
             * (as for middleware in Express).
             * @param response[in, out] Refers to the response data. It can be read and mutated by
             * modules (as for middlewares in Express)
             */
            virtual void process(RequestDataType &request, ResponseDataType &response) = 0;
    };
}

#endif //IMODULE_HPP
