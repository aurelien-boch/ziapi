#ifndef IREPLYSENDER_HPP
#define IREPLYSENDER_HPP

#include "IClient.hpp"

namespace api
{
    /**
     * @interface This interface defines the basic behavior of a reply sender
     * @tparam ResDataType This template parameter refers to the type of the response data type that will be send to the
     * client.
     */
    template <class ResponseDataType>
    class IReplySender
    {
        public:
            /**
             * @brief This method sends the response data to the client if the client isn't able to send the data, the
             * method should throw.
             * @param reply[in] This parameter refers to the data to send to the client.
             * @param client[in] This parameter refers to the client to send the data to.
             */
            virtual void send(ResponseDataType const &reply, Client const &client) = 0;
    };
}

#endif //IREPLYSENDER_HPP
