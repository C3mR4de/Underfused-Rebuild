#ifndef NETWORKINTERFACE_HPP_INCLUDED
#define NETWORKINTERFACE_HPP_INCLUDED

#include <SFML/Network.hpp>
#include <list>

#define SERVER_PORT 9093 // Порт сервера
#define CLIENT_PORT 9094 // Порт клиента

namespace Underfused
{
    namespace NetworkInterface
    {
        class UdpServer
        {
            sf::UdpSocket Socket;
            sf::IpAddress LastClientAddress;
            sf::Uint16 SendPort;
            sf::Uint16 ReceivePort;
            sf::Packet SendPacket;
            sf::Packet ReceivePacket;

        public:

            std::list<sf::IpAddress> ConnectedUsers;

            UdpServer(sf::Uint16, sf::Uint16);

            sf::Packet& operator<<(const sf::String&);

            sf::Packet& operator>>(sf::String&);

            void sendData();

            sf::Socket::Status receiveData();

            void clearSendPacket();
            void clearReceivePacket();

            sf::IpAddress getLastClient();

            void setBlocking(bool);

            ~UdpServer();
        };

        class UdpClient
        {
            sf::UdpSocket Socket;
            sf::IpAddress SendServerAddress;
            sf::IpAddress ReceiveServerAddress;
            sf::Uint16 SendPort;
            sf::Uint16 ReceivePort;
            sf::Packet SendPacket;
            sf::Packet ReceivePacket;

        public:

            UdpClient(sf::IpAddress, sf::Uint16, sf::Uint16);

            sf::Packet& operator<<(const sf::String&);

            sf::Packet& operator>>(sf::String&);

            void sendData();

            sf::Socket::Status receiveData();

            void clearSendPacket();
            void clearReceivePacket();

            void setBlocking(bool);

            ~UdpClient();
        };
    }
}

#endif // NETWORKINTERFACE_HPP_INCLUDED
