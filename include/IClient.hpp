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
     * @interface IClient
     * @brief Defines the basic behavior of a client. It can either be an asio encapsulation or your
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
             * @brief Send items to the client through the socket. If the socket isn't able to write all
             * the bytes, it should throw an exception.
             * @param content[in] Refers to a vector that will contain all the elements to send.
             */
            virtual void send(std::vector<std::byte> const &content) const = 0;

            /**
             * @brief Receives items from the client trough the socket. If there are no bytes to read
             * it should throw an exception.
             * @param bytesToRead[in] Refers to the number of bytes to read from the socket.
             * @return a vector containing the bytes that have been read.
             */
            [[nodiscard]] virtual std::vector<std::byte> receive(std::size_t bytesToRead) = 0;

            /**
             * @brief Connects the socket to a given ip and port. If the socket is already connected (using
             * connect or as a client for example, it should throw an exception).
             * @param ip[in] Refers to the ip to connect to.
             * @param port[in]Refers to the port to connect to.
             */
            virtual void connect(std::uint32_t ip, std::uint16_t port) = 0;

            /**
             * @brief Runs the socket internal event loop (it can use select / poll / epoll / ...).
             * If the socket loop is already running or the client is connected to another event loop (for example, a
             * listener one), it should throw an error.
             */
            virtual void run() = 0;

            /**
             * @brief Returns the file descriptor corresponding to the socket.
             */
            [[nodiscard]] virtual socket_type getNativeHandle() const noexcept = 0;
    };
}

#endif //CLIENT_HPP
