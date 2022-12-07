#include "NetworkInterface.hpp"

Underfused::NetworkInterface::UdpServer::UdpServer(sf::Uint16 SendPort = CLIENT_PORT, sf::Uint16 ReceivePort = SERVER_PORT)
{
    ConnectedUsers.push_back(sf::IpAddress::Any);
    this->SendPort = SendPort;
    this->ReceivePort = ReceivePort;
    Socket.setBlocking(false);
    Socket.bind(ReceivePort);
}

sf::Packet& Underfused::NetworkInterface::UdpServer::operator<<(const sf::String& Data)
{
    return SendPacket << Data;
}

sf::Packet& Underfused::NetworkInterface::UdpServer::operator>>(sf::String& Data)
{
    return ReceivePacket >> Data;
}

void Underfused::NetworkInterface::UdpServer::sendData()
{
    for (std::list<sf::IpAddress>::iterator Receiver = ConnectedUsers.begin(); Receiver != ConnectedUsers.end(); Receiver++)
        Socket.send(SendPacket, *Receiver, SendPort);
}

sf::Socket::Status Underfused::NetworkInterface::UdpServer::receiveData()
{
    return Socket.receive(ReceivePacket, LastClientAddress, ReceivePort);
}

void Underfused::NetworkInterface::UdpServer::clearSendPacket()
{
    SendPacket.clear();
}

void Underfused::NetworkInterface::UdpServer::clearReceivePacket()
{
    ReceivePacket.clear();
}

void Underfused::NetworkInterface::UdpClient::clearSendPacket()
{
    SendPacket.clear();
}

void Underfused::NetworkInterface::UdpClient::clearReceivePacket()
{
    ReceivePacket.clear();
}

sf::IpAddress Underfused::NetworkInterface::UdpServer::getLastClient()
{
    return LastClientAddress;
}

void Underfused::NetworkInterface::UdpServer::setBlocking(bool Blocking)
{
    Socket.setBlocking(Blocking);
}

Underfused::NetworkInterface::UdpServer::~UdpServer()
{
    Socket.unbind();
}

Underfused::NetworkInterface::UdpClient::UdpClient(sf::IpAddress ServerAddress, sf::Uint16 SendPort = SERVER_PORT, sf::Uint16 ReceivePort = CLIENT_PORT)
{
    SendServerAddress = ServerAddress;
    this->SendPort = SendPort;
    this->ReceivePort = ReceivePort;
    Socket.setBlocking(false);
    Socket.bind(ReceivePort);
}

sf::Packet& Underfused::NetworkInterface::UdpClient::operator<<(const sf::String& Data)
{
    return SendPacket << Data;
}

sf::Packet& Underfused::NetworkInterface::UdpClient::operator>>(sf::String& Data)
{
    return ReceivePacket >> Data;
}

void Underfused::NetworkInterface::UdpClient::sendData()
{
    Socket.send(SendPacket, SendServerAddress, SendPort);
}

sf::Socket::Status Underfused::NetworkInterface::UdpClient::receiveData()
{
    return Socket.receive(ReceivePacket, ReceiveServerAddress, ReceivePort);
}

void Underfused::NetworkInterface::UdpClient::setBlocking(bool Blocking)
{
    Socket.setBlocking(Blocking);
}

Underfused::NetworkInterface::UdpClient::~UdpClient()
{
    Socket.unbind();
}
