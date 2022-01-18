#ifndef IREPLYSENDER_HPP
#define IREPLYSENDER_HPP

#include "IClient.hpp"

namespace api
{
    /**
     * @interface IReplySender
     * @brief This interface defines the basic behavior of a pipeline reply sender
     * @tparam ResDataType This template parameter refers to the type of the response data type that will be send to the
     * client.
     */
    template <class ResponseDataType>
    class IReplySender
    {
        public:
            /**
             * @brief Sends the response data to the client. If the client isn't able to send the data, the
             * method should throw an exception.
             * @param reply[in] This parameter refers to the data that will be sent to the client.
             * @param client[in] This parameter refers to the client to send the data to.
             */
            virtual void send(ResponseDataType const &reply, Client const &client) = 0;
    };
}

#endif //IREPLYSENDER_HPP
