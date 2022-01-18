#ifndef IMODULE_HPP
#define IMODULE_HPP

namespace api
{
    /**
     * @interface This interface defines the basic behavior of a pipeline module.
     * @tparam RequestDataType This template parameter refers to the request data type. It will be transferred from the
     * parser to the modules.
     * @tparam ResponseDataType This template parameter refers to the request response data type that will be
     * transferred between the modules and the IReplySender.
     */
    template<class RequestDataType, class ResponseDataType>
    class IModule
    {
        public:
            /**
             *
             * @param request[in,out] This parameter refers to the request data. It can be read and mutated by modules
             * (as for middleware in Express).
             * @param response[in, out] This parameter refers to the response data. It can be read and mutated by
             * modules (as for middlewares in Express)
             */
            virtual void process(RequestDataType &request, ResponseDataType &response) = 0;
    };
}

#endif //IMODULE_HPP
