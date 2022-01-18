#ifndef CLIENT_HPP
#define CLIENT_HPP

#ifdef _WIN32
    #include <Windows.h>
#endif

#include <cstddef>
#include <vector>

namespace api
{
    /**
     * @interface This interface, defines the basic behavior of a client. It can be either an asio encapsulation or your
     * own socket abstraction.
     */
    class IClient
    {
        public:
        #ifdef _WIN32
            using socket_type = SOCKET;
        #else
            using socket_type = int;
        #endif

            /**
             * @brief This method sends items to the client trough the socket. If the socket isn't able to wrote all
             * the bytes, the method should throw an exception.
             * @param content[in] This parameter refers to a vector that will contains all the elements to send.
             */
            virtual void send(std::vector<std::byte> const &content) const = 0;

            /**
             * @brief This method received items from the client trough the socket. If there is no bytes to read
             * the method should throw an exception.
             * @param bytesToRead[in] This parameter refers to the num=ber of bytes to read from the socket.
             * @return a vector containing the bytes that has be read.
             */
            virtual std::vector<std::byte> recv(std::size_t bytesToRead) = 0;

            /**
             * @brief This method connects the socket a to given ip and port. If the socket is already connected (using
             * connect or as a client for example, this method should throw an exception).
             * @param ip[in] This parameter refers to the ip to connect to.
             * @param port[in] This parameter refers to the port to connect to.
             */
            virtual void connect(std::uint32_t ip, std::uint16_t port) = 0;

            /**
             * @brief This methods run the socket internal event loop (it can use select / poll / epoll / ...).
             * If the socket loop is already running of the client is connected to another event loop (for example, a
             * listener one), the method should throw an error.
             */
            virtual void run() = 0;

            /**
             * @brief This method returns the file descriptor corresponding to the socket.
             */
            virtual socket_type getNativeHandle() const noexcept = 0;
    };
}

#endif //CLIENT_HPP
