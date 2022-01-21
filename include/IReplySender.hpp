#ifndef IREPLYSENDER_HPP
#define IREPLYSENDER_HPP

#include "IClient.hpp"

namespace api
{
    /**
     * @interface IReplySender
     * @brief Defines the basic behavior of a pipeline reply sender
     * @tparam ResDataType Refers to the type of the response data type that will be sent to the
     * client.
     */
    template <class ResponseDataType>
    class IReplySender
    {
        public:
            /**
             * @brief Sends the response data to the client. If the client isn't able to send the data, it should throw
             * an exception.
             * @param reply[in] Refers to the data that will be sent to the client.
             * @param client[in] Refers to the client to send the data to.
             */
             virtual void send(ResponseDataType const &reply, IClient const &client) = 0;
    };
}

#endif //IREPLYSENDER_HPP
