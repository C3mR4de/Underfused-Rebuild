#ifndef MULTIPLAYER_HPP_INCLUDED
#define MULTIPLAYER_HPP_INCLUDED

#include "NetworkInterface.hpp"

#define CMD_CONNECT L"-Con"
#define CMD_DISCONNECT L"-Dsc"
#define CMD_DATA L"-Dat"
#define CMD_MESSAGE L"-Msg"

namespace Underfused
{
    namespace Multiplayer
    {
        extern sf::String GlobalNickname;
        extern sf::String GlobalAddress;
        extern sf::String GlobalIdentifier;
    }
}

#endif // MULTIPLAYER_HPP_INCLUDED
