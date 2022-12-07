#include "MenuFunctions.hpp"

int main()
{
    // Задаём опору для рандомайзера
    srand(time(NULL));

    // Загружаем шрифт
    Underfused::GUI::Font.loadFromFile("C:/Windows/Fonts/comic.ttf");

    // Генерируем рандомный ID игрока
    for (sf::Uint32 i = 0; i < 16; i++)
        Underfused::Multiplayer::GlobalIdentifier += (wchar_t)(rand() % 94 + 33);

    while (Underfused::GUI::Window.isOpen())
    {
        switch (Underfused::GUI::Menu)
        {
            case Underfused::GUI::Enums::MainMenu:
                Underfused::MenuFunctions::MainMenu();
                break;

            case Underfused::GUI::Enums::Settings:
                Underfused::MenuFunctions::Settings();
                break;

            case Underfused::GUI::Enums::SelectType:
                Underfused::MenuFunctions::SelectType();
                break;

            case Underfused::GUI::Enums::CreateServer:
                Underfused::MenuFunctions::CreateServer();
                break;

            case Underfused::GUI::Enums::ConnectToServer:
                Underfused::MenuFunctions::ConnectToServer();
                break;

            case Underfused::GUI::Enums::GameServer:
                Underfused::MenuFunctions::GameServer();
                break;

            case Underfused::GUI::Enums::GameClient:
                Underfused::MenuFunctions::GameClient();
                break;

            default:
                break;
        }
    }

    return 0;
}
