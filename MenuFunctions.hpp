#ifndef MENUFUNCTIONS_HPP_INCLUDED
#define MENUFUNCTIONS_HPP_INCLUDED

#include "Multiplayer.hpp"
#include "GamePhysics.hpp"
#include "StringManip.hpp"
#include <cmath>

#define SEND_COOLDOWN 0.f

namespace Underfused
{
    namespace MenuFunctions
    {
        void MainMenu();
        void Settings();
        void SelectType();
        void CreateServer();
        void ConnectToServer();
        void GameServer();
        void GameClient();
    }
}

#endif // MENUFUNCTIONS_HPP_INCLUDED
