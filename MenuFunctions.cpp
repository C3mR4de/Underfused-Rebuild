#include "MenuFunctions.hpp"

void Underfused::MenuFunctions::MainMenu()
{
    // Возвращаем стандартный вид
    Underfused::GUI::Window.setView(Underfused::GUI::Window.getDefaultView());

    // Текст заголовка и его форматирование
    sf::Text Header(L"Underfused", Underfused::GUI::Font, 108);
    Header.setOrigin(Header.getLocalBounds().width / 2, Header.getLocalBounds().height / 2);
    Header.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y / 2);

    // Создание кнопок
    Underfused::GUI::ClickableText Play(Underfused::GUI::Font, L"Играть");
    Underfused::GUI::ClickableText Settings(Underfused::GUI::Font, L"Настройки");
    Underfused::GUI::ClickableText Quit(Underfused::GUI::Font, L"Выход");

    struct ButtonActions
    {
        static void Play()
        {
            Underfused::GUI::Menu = Underfused::GUI::Enums::SelectType;
        }

        static void Settings()
        {
            Underfused::GUI::Menu = Underfused::GUI::Enums::Settings;
        }

        static void Quit()
        {
            Underfused::GUI::Window.close();
        }
    };

    Play.setAction(ButtonActions::Play);
    Settings.setAction(ButtonActions::Settings);
    Quit.setAction(ButtonActions::Quit);

    // Задаём позицию
    Settings.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y + 75);
    Quit.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y + 150);

    // Главный цикл
    while (Underfused::GUI::Window.isOpen() && Underfused::GUI::Menu == Underfused::GUI::Enums::MainMenu)
    {
        // Глобально обновляем состояние мыши
        Underfused::GUI::GlobalParameters::update();

        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                case sf::Event::KeyPressed:

                    switch (Underfused::GUI::Event.key.code)
                    {
                        case sf::Keyboard::P:
                            Underfused::GUI::takeScreenshot();
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        // Обновляем кнопки
        Play.update();
        Settings.update();
        Quit.update();

        // Очистка окна и отображение
        Underfused::GUI::Window.clear();

        Underfused::GUI::Window.draw(Header);
        Underfused::GUI::Window.draw(Play);
        Underfused::GUI::Window.draw(Settings);
        Underfused::GUI::Window.draw(Quit);

        Underfused::GUI::Window.display();
    }
}

void Underfused::MenuFunctions::Settings()
{
    // Возвращаем стандартный вид
    Underfused::GUI::Window.setView(Underfused::GUI::Window.getDefaultView());

    while (Underfused::GUI::Window.isOpen() && Underfused::GUI::Menu == Underfused::GUI::Enums::Settings)
    {
        // Глобально обновляем состояние мыши
        Underfused::GUI::GlobalParameters::update();

        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                case sf::Event::KeyPressed:

                    switch (Underfused::GUI::Event.key.code)
                    {
                        case sf::Keyboard::P:
                            Underfused::GUI::takeScreenshot();
                            break;

                        case sf::Keyboard::Escape:
                            Underfused::GUI::Menu = Underfused::GUI::Enums::MainMenu;
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        Underfused::GUI::Window.clear();
        Underfused::GUI::Window.display();
    }
}

void Underfused::MenuFunctions::SelectType()
{
    // Возвращаем стандартный вид
    Underfused::GUI::Window.setView(Underfused::GUI::Window.getDefaultView());

    sf::Text Text(L"Сетевая игра", Underfused::GUI::Font, 72);
    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2);
    Text.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y / 3);

    Underfused::GUI::ClickableText CreateServer(Underfused::GUI::Font, L"Создать игру");
    CreateServer.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x / 2, Underfused::GUI::Window.getDefaultView().getCenter().y);

    Underfused::GUI::ClickableText ConnectToServer(Underfused::GUI::Font, L"Подключиться к игре");
    ConnectToServer.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x * 3 / 2, Underfused::GUI::Window.getDefaultView().getCenter().y);

    struct ButtonActions
    {
        static void CreateServer()
        {
            Underfused::GUI::Menu = Underfused::GUI::Enums::CreateServer;
        }

        static void ConnectToServer()
        {
            Underfused::GUI::Menu = Underfused::GUI::Enums::ConnectToServer;
        }
    };

    CreateServer.setAction(ButtonActions::CreateServer);
    ConnectToServer.setAction(ButtonActions::ConnectToServer);

    while (Underfused::GUI::Window.isOpen() && Underfused::GUI::Menu == Underfused::GUI::Enums::SelectType)
    {
        // Глобально обновляем состояние мыши
        Underfused::GUI::GlobalParameters::update();

        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                case sf::Event::KeyPressed:

                    switch (Underfused::GUI::Event.key.code)
                    {
                        case sf::Keyboard::P:
                            Underfused::GUI::takeScreenshot();
                            break;

                        case sf::Keyboard::Escape:
                            Underfused::GUI::Menu = Underfused::GUI::Enums::MainMenu;
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        CreateServer.update();
        ConnectToServer.update();

        Underfused::GUI::Window.clear();

        Underfused::GUI::Window.draw(Text);
        Underfused::GUI::Window.draw(CreateServer);
        Underfused::GUI::Window.draw(ConnectToServer);

        Underfused::GUI::Window.display();
    }
}

void Underfused::MenuFunctions::CreateServer()
{
    // Возвращаем стандартный вид
    Underfused::GUI::Window.setView(Underfused::GUI::Window.getDefaultView());

    sf::Text Text(L"Создать игру", Underfused::GUI::Font, 72);
    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2);
    Text.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y / 3);

    sf::Text NicknameText(L"Никнейм: ", Underfused::GUI::Font);
    NicknameText.setOrigin(NicknameText.getLocalBounds().width + Underfused::GUI::Window.getDefaultView().getSize().x / 16, NicknameText.getLocalBounds().height / 2);
    NicknameText.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y);
    NicknameText.setString(L"Никнейм: " + Underfused::Multiplayer::GlobalNickname);

    Underfused::GUI::ClickableText CreateButton(Underfused::GUI::Font, L"Создать игру");
    CreateButton.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y * 1.8f);

    struct ButtonActions
    {
        static void CreateServer()
        {
            Underfused::GUI::Menu = Underfused::GUI::Enums::GameServer;
        }
    };

    CreateButton.setAction(ButtonActions::CreateServer);

    while (Underfused::GUI::Window.isOpen() && Underfused::GUI::Menu == Underfused::GUI::Enums::CreateServer)
    {
        // Глобально обновляем состояние мыши
        Underfused::GUI::GlobalParameters::update();

        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                case sf::Event::TextEntered:

                    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
                    {
                        if (Underfused::GUI::Event.text.unicode != 8 && Underfused::GUI::Event.text.unicode != 27)
                            Underfused::Multiplayer::GlobalNickname += (wchar_t)Underfused::GUI::Event.text.unicode;
                        else
                        {
                            if (Underfused::GUI::Event.text.unicode != 27)
                            {
                                if (Underfused::Multiplayer::GlobalNickname.getSize() > 0)
                                    Underfused::Multiplayer::GlobalNickname.erase(Underfused::Multiplayer::GlobalNickname.getSize() - 1);
                            }
                        }

                        NicknameText.setString(L"Никнейм: " + Underfused::Multiplayer::GlobalNickname);
                    }

                    break;

                // Выход в главное меню на Escape
                case sf::Event::KeyPressed:

                    switch (Underfused::GUI::Event.key.code)
                    {
                        case sf::Keyboard::P:
                            Underfused::GUI::takeScreenshot();
                            break;

                        case sf::Keyboard::Escape:
                            Underfused::GUI::Menu = Underfused::GUI::Enums::SelectType;
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;

            }
        }

        CreateButton.update();

        // Очистка окна и отрисовка всего
        Underfused::GUI::Window.clear();

        Underfused::GUI::Window.draw(Text);
        Underfused::GUI::Window.draw(NicknameText);
        Underfused::GUI::Window.draw(CreateButton);

        Underfused::GUI::Window.display();
    }
}

void Underfused::MenuFunctions::ConnectToServer()
{
    // Возвращаем стандартный вид
    Underfused::GUI::Window.setView(Underfused::GUI::Window.getDefaultView());

    enum EntryField
    {
        Nickname,
        ServerAddress
    };

    EntryField SelectedEntryField = Nickname;

    sf::Text Text(L"Подключиться к игре", Underfused::GUI::Font, 72);
    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2);
    Text.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y / 3);

    sf::Text NicknameText(L"Никнейм: ", Underfused::GUI::Font);
    NicknameText.setOrigin(NicknameText.getLocalBounds().width + Underfused::GUI::Window.getDefaultView().getSize().x / 16, NicknameText.getLocalBounds().height / 2);
    NicknameText.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y * (1 - 1.f / 4));
    NicknameText.setString(L"Никнейм: " + Underfused::Multiplayer::GlobalNickname);

    sf::Text ServerAddressText(L"IP-адрес сервера: ", Underfused::GUI::Font);
    ServerAddressText.setOrigin(ServerAddressText.getLocalBounds().width + Underfused::GUI::Window.getDefaultView().getSize().x / 16, ServerAddressText.getLocalBounds().height / 2);
    ServerAddressText.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y * (1 + 1.f / 4));
    ServerAddressText.setString(L"IP-адрес сервера: " + Underfused::Multiplayer::GlobalAddress);

    Underfused::GUI::ClickableText JoinButton(Underfused::GUI::Font, L"Подключиться к игре");
    JoinButton.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y * 1.8f);

    struct ButtonActions
    {
        static void ConnectToServer()
        {
            Underfused::GUI::Menu = Underfused::GUI::Enums::GameClient;
        }
    };

    JoinButton.setAction(ButtonActions::ConnectToServer);

    while (Underfused::GUI::Window.isOpen() && Underfused::GUI::Menu == Underfused::GUI::Enums::ConnectToServer)
    {
        // Глобально обновляем состояние мыши
        Underfused::GUI::GlobalParameters::update();

        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                case sf::Event::TextEntered:

                    switch (SelectedEntryField)
                    {
                        case Nickname:

                            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
                            {
                                if (Underfused::GUI::Event.text.unicode != 8 && Underfused::GUI::Event.text.unicode != 27)
                                    Underfused::Multiplayer::GlobalNickname += (wchar_t)Underfused::GUI::Event.text.unicode;
                                else
                                {
                                    if (Underfused::GUI::Event.text.unicode != 27)
                                    {
                                        if (Underfused::Multiplayer::GlobalNickname.getSize() > 0)
                                            Underfused::Multiplayer::GlobalNickname.erase(Underfused::Multiplayer::GlobalNickname.getSize() - 1);
                                    }
                                }

                                NicknameText.setString(L"Никнейм: " + Underfused::Multiplayer::GlobalNickname);
                            }

                            break;

                        case ServerAddress:

                            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
                            {
                                if (Underfused::GUI::Event.text.unicode != 8 && Underfused::GUI::Event.text.unicode != 27)
                                    Underfused::Multiplayer::GlobalAddress += (wchar_t)Underfused::GUI::Event.text.unicode;
                                else
                                {
                                    if (Underfused::GUI::Event.text.unicode != 27)
                                    {
                                        if (Underfused::Multiplayer::GlobalAddress.getSize() > 0)
                                            Underfused::Multiplayer::GlobalAddress.erase(Underfused::Multiplayer::GlobalAddress.getSize() - 1);
                                    }
                                }

                                ServerAddressText.setString(L"IP-адрес сервера: " + Underfused::Multiplayer::GlobalAddress);
                            }

                            break;

                        default:
                            break;
                    }

                    break;

                case sf::Event::KeyPressed:

                    switch (Underfused::GUI::Event.key.code)
                    {
                        case sf::Keyboard::Up: case sf::Keyboard::Down:
                            SelectedEntryField = (EntryField)!(bool)SelectedEntryField;
                            break;

                        case sf::Keyboard::P:
                            Underfused::GUI::takeScreenshot();
                            break;

                        case sf::Keyboard::Escape:
                            Underfused::GUI::Menu = Underfused::GUI::Enums::SelectType;
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        JoinButton.update();

        Underfused::GUI::Window.clear();

        Underfused::GUI::Window.draw(Text);
        Underfused::GUI::Window.draw(NicknameText);
        Underfused::GUI::Window.draw(ServerAddressText);
        Underfused::GUI::Window.draw(JoinButton);

        Underfused::GUI::Window.display();
    }
}

void Underfused::MenuFunctions::GameServer()
{
    Underfused::NetworkInterface::UdpServer Server(CLIENT_PORT, SERVER_PORT);

    sf::View View;
    View.setSize(Underfused::GUI::Window.getDefaultView().getSize().x, Underfused::GUI::Window.getDefaultView().getSize().y);
    View.setCenter(0, 0);

    float ScaleCoefficient = 1.f;

    sf::VertexArray Grid(sf::Lines, 2);

    sf::CircleShape HubbleSphere(100000, 10000);
    HubbleSphere.setFillColor(sf::Color::Black);
    HubbleSphere.setOutlineThickness(200);
    HubbleSphere.setOutlineColor(sf::Color(127, 0, 0));
    HubbleSphere.setOrigin(HubbleSphere.getRadius(), HubbleSphere.getRadius());

    std::list<Underfused::GamePhysics::Player> Players;
    Players.push_back(Underfused::GamePhysics::Player(Underfused::Multiplayer::GlobalNickname, Underfused::Multiplayer::GlobalIdentifier, Underfused::GamePhysics::Enums::None, 50));

    sf::Text Warning(L"", Underfused::GUI::Font);
    Warning.setFillColor(sf::Color::Black);
    Warning.setOutlineThickness(3);
    Warning.setOutlineColor(sf::Color::White);

    sf::String SendData;

    sf::Clock SendCooldown;

    while (Underfused::GUI::Window.isOpen() && Underfused::GUI::Menu == Underfused::GUI::Enums::GameServer)
    {
        Underfused::GUI::GlobalParameters::update();
        Underfused::GamePhysics::Frame::update();

        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                case sf::Event::MouseWheelScrolled:

                    if (ScaleCoefficient - Underfused::GUI::Event.mouseWheelScroll.delta / 10 >= 0.1f && ScaleCoefficient - Underfused::GUI::Event.mouseWheelScroll.delta / 10 <= 5.f)
                    {
                        ScaleCoefficient -= Underfused::GUI::Event.mouseWheelScroll.delta / 10;
                        View.setSize(Underfused::GUI::Window.getDefaultView().getSize().x * ScaleCoefficient, Underfused::GUI::Window.getDefaultView().getSize().y * ScaleCoefficient);
                    }

                    break;

                case sf::Event::KeyPressed:

                    switch (Underfused::GUI::Event.key.code)
                    {
                        case sf::Keyboard::P:
                            Underfused::GUI::takeScreenshot();
                            break;

                        case sf::Keyboard::Escape:
                            Underfused::GUI::Menu = Underfused::GUI::Enums::SelectType;
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        switch (Server.receiveData())
        {
            case sf::Socket::Done:
                {
                    sf::String ReceiveData;
                    Server >> ReceiveData;

                    std::wstringstream WideStringStream(ReceiveData.toWideString());
                    std::wstring Excerpt;

                    std::getline(WideStringStream, Excerpt);

                    if (Excerpt == CMD_CONNECT)
                    {
                        bool Existed = false;

                        for (std::list<sf::IpAddress>::iterator Address = Server.ConnectedUsers.begin(); Address != Server.ConnectedUsers.end(); Address++)
                        {
                            if (*Address == Server.getLastClient())
                                Existed = true;
                        }

                        if (!Existed)
                        {
                            Server.ConnectedUsers.push_back(Server.getLastClient());

                            std::getline(WideStringStream, Excerpt);
                            sf::String Identifier = Excerpt;

                            std::getline(WideStringStream, Excerpt);
                            sf::String Nickname = Excerpt;

                            Players.push_back(Underfused::GamePhysics::Player(Nickname, Identifier, Underfused::GamePhysics::Enums::None, 50));

                            Underfused::GUI::MessageBox.setString(Underfused::GUI::MessageBox.getString() + Nickname + L" подключился к игре\n");
                        }
                    }
                    else if (Excerpt == CMD_DATA)
                    {
                        bool Ok = false;

                        std::getline(WideStringStream, Excerpt);

                        for (std::list<Underfused::GamePhysics::Player>::iterator Sender = Players.begin(); Sender != Players.end(); Sender++)
                        {
                            if (Sender->getIdentifier() == Excerpt)
                            {
                                std::getline(WideStringStream, Excerpt);
                                Sender->setDirectionX((Underfused::GamePhysics::Enums::Direction)Underfused::StringManip::StringToInt(Excerpt, Ok));

                                std::getline(WideStringStream, Excerpt);
                                Sender->setDirectionY((Underfused::GamePhysics::Enums::Direction)Underfused::StringManip::StringToInt(Excerpt, Ok));
                                break;
                            }
                        }
                    }
                    else if (Excerpt == CMD_DISCONNECT)
                    {
                        Server.ConnectedUsers.erase(std::remove(Server.ConnectedUsers.begin(), Server.ConnectedUsers.end(), Server.getLastClient()), Server.ConnectedUsers.end());

                        std::getline(WideStringStream, Excerpt);

                        for (std::list<Underfused::GamePhysics::Player>::iterator Sender = Players.begin(); Sender != Players.end(); Sender++)
                        {
                            if (Sender->getIdentifier() == Excerpt)
                            {
                                Underfused::GUI::MessageBox.setString(Underfused::GUI::MessageBox.getString() + Sender->getNickname() + L" отключился от игры\n");
                                Players.erase(Sender);
                                break;
                            }
                        }
                    }
                    else if (Excerpt == CMD_MESSAGE)
                    {
                        std::getline(WideStringStream, Excerpt);

                        Underfused::GUI::MessageBox.setString(Underfused::GUI::MessageBox.getString() + Excerpt + L"\n");

                        SendData += CMD_MESSAGE + Excerpt;
                        Server << SendData;
                        Server.sendData();
                        SendData.clear();
                        Server.clearSendPacket();
                    }

                    Server.clearReceivePacket();
                }
                break;

            default:
                break;
        }

        for (std::list<Underfused::GamePhysics::Player>::iterator Player = Players.begin(); Player != Players.end(); Player++)
        {
            if (Player->getIdentifier() == Underfused::Multiplayer::GlobalIdentifier)
                Player->control();

            Player->update(ScaleCoefficient);

            if (Player->getIdentifier() == Underfused::Multiplayer::GlobalIdentifier)
            {
                View.setCenter(Player->getPosition());

                // Обновляем текст предупреждения
                if (HubbleSphere.getRadius() - sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2)) <= 50000.f)
                {
                    Warning.setString(L"Вы в " + Underfused::StringManip::FloatToString((int)(HubbleSphere.getRadius() - sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2)))) + L" метрах от границы сферы Хаббла");

                    if (HubbleSphere.getRadius() <= sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2)))
                    {
                        Warning.setString(L"Вы попали за границу сферы Хаббла. Игра окончена!");

                        Player->setVelocity(300000.f * (Player->getPosition().x / sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2))), 300000.f * (Player->getPosition().y / sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2))));
                    }
                }
                else
                {
                    Warning.setString(L"");
                }

                // Форматируем текст предупреждения
                Warning.setScale(ScaleCoefficient, ScaleCoefficient);
                Warning.setOrigin(Warning.getLocalBounds().width / 2, Warning.getLocalBounds().height / 2);
                Warning.setPosition(Player->getPosition().x, Player->getPosition().y - 100 * ScaleCoefficient);

                Underfused::GUI::MessageBox.setScale(ScaleCoefficient, ScaleCoefficient);
                Underfused::GUI::MessageBox.setOrigin(0, Underfused::GUI::MessageBox.getLocalBounds().height);
                Underfused::GUI::MessageBox.setPosition(Player->getPosition().x - View.getSize().x / 2, Player->getPosition().y + View.getSize().y / 2);
            }
        }

        // Обновляем состояние Сфера Хаббла
        HubbleSphere.setRadius(HubbleSphere.getRadius() - 500 * Underfused::GamePhysics::Frame::getDuration());
        HubbleSphere.setOrigin(HubbleSphere.getRadius(), HubbleSphere.getRadius());

        if (SendCooldown.getElapsedTime().asSeconds() >= SEND_COOLDOWN)
        {
            SendData += CMD_DATA;
            SendData += L"\n";
            SendData += Underfused::StringManip::FloatToString(HubbleSphere.getRadius()) + L"\n";
            SendData += Underfused::StringManip::IntToString(Players.size()) + L"\n";

            for (std::list<Underfused::GamePhysics::Player>::iterator Player = Players.begin(); Player != Players.end(); Player++)
            {
                SendData += Player->getIdentifier() + L"\n";
                SendData += Player->getNickname() + L"\n";
                SendData += Underfused::StringManip::IntToString((sf::Int16)Player->getTeam()) + L"\n";
                SendData += Underfused::StringManip::FloatToString(Player->getSize()) + L"\n";
                SendData += Underfused::StringManip::FloatToString(Player->getPosition().x) + L"\n";
                SendData += Underfused::StringManip::FloatToString(Player->getPosition().y) + L"\n";
                SendData += Underfused::StringManip::FloatToString(Player->getVelocity().x) + L"\n";
                SendData += Underfused::StringManip::FloatToString(Player->getVelocity().y) + L"\n";
                SendData += Underfused::StringManip::FloatToString(Player->getAcceleration().x) + L"\n";
                SendData += Underfused::StringManip::FloatToString(Player->getAcceleration().y) + L"\n";
                SendData += Underfused::StringManip::IntToString(Player->getDirectionX()) + L"\n";
                SendData += Underfused::StringManip::IntToString(Player->getDirectionY()) + L"\n";
            }

            Server << SendData;
            Server.sendData();
            Server.clearSendPacket();
            SendData.clear();

            SendCooldown.restart();
        }

        Underfused::GUI::Window.setView(View);

        Underfused::GUI::Window.clear(sf::Color::Red);

        Underfused::GUI::Window.draw(HubbleSphere);

        for (float i = round((View.getCenter().x - View.getSize().x / 2) / 200) * 200; i < View.getCenter().x + View.getSize().x / 2; i += 200)
        {
            if (i == 0)
            {
                Grid[0].color = sf::Color::White;
                Grid[1].color = sf::Color::White;
            }
            else
            {
                Grid[0].color = sf::Color(255, 255, 255, 127);
                Grid[1].color = sf::Color(255, 255, 255, 127);
            }

            Grid[0].position = sf::Vector2f(i, View.getCenter().y - View.getSize().y / 2);
            Grid[1].position = sf::Vector2f(i, View.getCenter().y + View.getSize().y / 2);

            Underfused::GUI::Window.draw(Grid);
        }

        // Отрисовка горизонтальных полос сетки
        for (float i = round((View.getCenter().y - View.getSize().y / 2) / 200) * 200; i < View.getCenter().y + View.getSize().y / 2; i += 200)
        {
            if (i == 0)
            {
                Grid[0].color = sf::Color::White;
                Grid[1].color = sf::Color::White;
            }
            else
            {
                Grid[0].color = sf::Color(255, 255, 255, 127);
                Grid[1].color = sf::Color(255, 255, 255, 127);
            }

            Grid[0].position = sf::Vector2f(View.getCenter().x - View.getSize().x / 2, i);
            Grid[1].position = sf::Vector2f(View.getCenter().x + View.getSize().x / 2, i);

            Underfused::GUI::Window.draw(Grid);
        }

        for (std::list<Underfused::GamePhysics::Player>::iterator Player = Players.begin(); Player != Players.end(); Player++)
            Underfused::GUI::Window.draw(*Player);

        Underfused::GUI::Window.draw(Warning);
        Underfused::GUI::Window.draw(Underfused::GUI::MessageBox);

        Underfused::GUI::Window.display();
    }

    Server.clearSendPacket();
    SendData.clear();
    SendData += CMD_DISCONNECT;
    Server << SendData;
    Server.sendData();
}

void Underfused::MenuFunctions::GameClient()
{
    Underfused::NetworkInterface::UdpClient Client(sf::IpAddress(Underfused::Multiplayer::GlobalAddress), SERVER_PORT, CLIENT_PORT);

    sf::View View;
    View.setSize(Underfused::GUI::Window.getDefaultView().getSize().x, Underfused::GUI::Window.getDefaultView().getSize().y);
    View.setCenter(0, 0);

    float ScaleCoefficient = 1.f;

    // Сетка
    sf::VertexArray Grid(sf::Lines, 2);

    // Сфера Хаббла
    sf::CircleShape HubbleSphere(100000, 10000);
    HubbleSphere.setFillColor(sf::Color::Black);
    HubbleSphere.setOutlineThickness(200);
    HubbleSphere.setOutlineColor(sf::Color(127, 0, 0));
    HubbleSphere.setOrigin(HubbleSphere.getRadius(), HubbleSphere.getRadius());

    std::list<Underfused::GamePhysics::Player> Players;

    sf::Text Warning(L"", Underfused::GUI::Font);
    Warning.setFillColor(sf::Color::Black);
    Warning.setOutlineThickness(3);
    Warning.setOutlineColor(sf::Color::White);

    sf::String SendData;
    SendData += CMD_CONNECT;
    SendData += L"\n";
    SendData += Underfused::Multiplayer::GlobalIdentifier + L"\n" + Underfused::Multiplayer::GlobalNickname + L"\n";
    Client << SendData;
    Client.sendData();

    sf::Clock SendCooldown;

    bool ConnectedSuccessfully = false;

    sf::Text Text(L"Подключение к серверу...", Underfused::GUI::Font);
    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2);
    Text.setPosition(Underfused::GUI::Window.getDefaultView().getCenter().x, Underfused::GUI::Window.getDefaultView().getCenter().y);

    while (Underfused::GUI::Window.isOpen() && !ConnectedSuccessfully)
    {
        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                default:
                    break;
            }
        }

        switch (Client.receiveData())
        {
            case sf::Socket::Done:
                {
                    sf::String ReceiveData;
                    Client >> ReceiveData;

                    std::wstringstream WideStringStream(ReceiveData.toWideString());
                    std::wstring Excerpt;

                    std::getline(WideStringStream, Excerpt);

                    if (Excerpt == CMD_DATA)
                    {
                        bool Ok = false;

                        std::getline(WideStringStream, Excerpt);
                        HubbleSphere.setRadius(Underfused::StringManip::StringToFloat(Excerpt, Ok));

                        std::getline(WideStringStream, Excerpt);
                        sf::Uint32 NumOfPlayers = Underfused::StringManip::StringToInt(Excerpt, Ok);

                        if (Players.size() != NumOfPlayers)
                            Players.resize(NumOfPlayers);

                        std::list<Underfused::GamePhysics::Player>::iterator Player = Players.begin();

                        for (sf::Uint16 i = 0; i < NumOfPlayers; i++)
                        {
                            std::getline(WideStringStream, Excerpt);
                            Player->setIdentifier(Excerpt);

                            std::getline(WideStringStream, Excerpt);
                            Player->setNickname(Excerpt);

                            std::getline(WideStringStream, Excerpt);
                            Player->setTeam((Underfused::GamePhysics::Enums::Team)Underfused::StringManip::StringToInt(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setSize(Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setPosition(Underfused::StringManip::StringToFloat(Excerpt, Ok), Player->getPosition().y);

                            std::getline(WideStringStream, Excerpt);
                            Player->setPosition(Player->getPosition().x, Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setVelocity(Underfused::StringManip::StringToFloat(Excerpt, Ok), Player->getVelocity().y);

                            std::getline(WideStringStream, Excerpt);
                            Player->setVelocity(Player->getVelocity().x, Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setAcceleration(Underfused::StringManip::StringToFloat(Excerpt, Ok), Player->getAcceleration().y);

                            std::getline(WideStringStream, Excerpt);
                            Player->setAcceleration(Player->getAcceleration().x, Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setDirectionX((Underfused::GamePhysics::Enums::Direction)Underfused::StringManip::StringToInt(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setDirectionY((Underfused::GamePhysics::Enums::Direction)Underfused::StringManip::StringToInt(Excerpt, Ok));

                            Player++;
                        }
                    }

                    ConnectedSuccessfully = true;
                }
                break;

            default:

                if (SendCooldown.getElapsedTime().asSeconds() >= SEND_COOLDOWN)
                {
                    Client.sendData();
                    SendCooldown.restart();
                }

                break;
        }

        Underfused::GUI::Window.clear();
        Underfused::GUI::Window.draw(Text);
        Underfused::GUI::Window.display();
    }

    Client.clearSendPacket();
    Client.clearReceivePacket();

    while (Underfused::GUI::Window.isOpen() && Underfused::GUI::Menu == Underfused::GUI::Enums::GameClient)
    {
        Underfused::GUI::GlobalParameters::update();
        Underfused::GamePhysics::Frame::update();

        while (Underfused::GUI::Window.pollEvent(Underfused::GUI::Event))
        {
            switch (Underfused::GUI::Event.type)
            {
                case sf::Event::Closed:
                    Underfused::GUI::Window.close();
                    break;

                case sf::Event::MouseWheelScrolled:

                    if (ScaleCoefficient - Underfused::GUI::Event.mouseWheelScroll.delta / 10 >= 0.1f && ScaleCoefficient - Underfused::GUI::Event.mouseWheelScroll.delta / 10 <= 5.f)
                    {
                        ScaleCoefficient -= Underfused::GUI::Event.mouseWheelScroll.delta / 10;
                        View.setSize(Underfused::GUI::Window.getDefaultView().getSize().x * ScaleCoefficient, Underfused::GUI::Window.getDefaultView().getSize().y * ScaleCoefficient);
                    }

                    break;

                case sf::Event::KeyPressed:

                    switch (Underfused::GUI::Event.key.code)
                    {
                        case sf::Keyboard::P:
                            Underfused::GUI::takeScreenshot();
                            break;

                        case sf::Keyboard::Escape:
                            Underfused::GUI::Menu = Underfused::GUI::Enums::SelectType;
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        switch (Client.receiveData())
        {
            case sf::Socket::Done:
                {
                    sf::String ReceiveData;
                    Client >> ReceiveData;

                    std::wstringstream WideStringStream(ReceiveData.toWideString());
                    std::wstring Excerpt;

                    std::getline(WideStringStream, Excerpt);

                    if (Excerpt == CMD_DATA)
                    {
                        bool Ok = false;

                        std::getline(WideStringStream, Excerpt);
                        HubbleSphere.setRadius(Underfused::StringManip::StringToFloat(Excerpt, Ok));

                        std::getline(WideStringStream, Excerpt);
                        sf::Uint32 NumOfPlayers = Underfused::StringManip::StringToInt(Excerpt, Ok);

                        Players.resize(NumOfPlayers);

                        std::list<Underfused::GamePhysics::Player>::iterator Player = Players.begin();

                        for (sf::Uint16 i = 0; i < NumOfPlayers; i++)
                        {
                            std::getline(WideStringStream, Excerpt);
                            Player->setIdentifier(Excerpt);

                            std::getline(WideStringStream, Excerpt);
                            Player->setNickname(Excerpt);

                            std::getline(WideStringStream, Excerpt);
                            Player->setTeam((Underfused::GamePhysics::Enums::Team)Underfused::StringManip::StringToInt(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setSize(Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setPosition(Underfused::StringManip::StringToFloat(Excerpt, Ok), Player->getPosition().y);

                            std::getline(WideStringStream, Excerpt);
                            Player->setPosition(Player->getPosition().x, Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setVelocity(Underfused::StringManip::StringToFloat(Excerpt, Ok), Player->getVelocity().y);

                            std::getline(WideStringStream, Excerpt);
                            Player->setVelocity(Player->getVelocity().x, Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setAcceleration(Underfused::StringManip::StringToFloat(Excerpt, Ok), Player->getAcceleration().y);

                            std::getline(WideStringStream, Excerpt);
                            Player->setAcceleration(Player->getAcceleration().x, Underfused::StringManip::StringToFloat(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setDirectionX((Underfused::GamePhysics::Enums::Direction)Underfused::StringManip::StringToInt(Excerpt, Ok));

                            std::getline(WideStringStream, Excerpt);
                            Player->setDirectionY((Underfused::GamePhysics::Enums::Direction)Underfused::StringManip::StringToInt(Excerpt, Ok));

                            Player++;
                        }
                    }
                    else if (Excerpt == CMD_DISCONNECT)
                    {
                        Underfused::GUI::Menu = Underfused::GUI::Enums::MainMenu;
                    }
                    else if (Excerpt == CMD_MESSAGE)
                    {
                        std::getline(WideStringStream, Excerpt);
                        Underfused::GUI::MessageBox.setString(Underfused::GUI::MessageBox.getString()  + Excerpt + L"\n");
                    }

                    Client.clearReceivePacket();
                }
                break;

            default:
                break;
        }

        for (std::list<Underfused::GamePhysics::Player>::iterator Player = Players.begin(); Player != Players.end(); Player++)
        {
            if (Player->getIdentifier() == Underfused::Multiplayer::GlobalIdentifier)
                Player->control();

            Player->update(ScaleCoefficient);

            if (Player->getIdentifier() == Underfused::Multiplayer::GlobalIdentifier)
            {
                View.setCenter(Player->getPosition());

                // Обновляем текст предупреждения
                if (HubbleSphere.getRadius() - sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2)) <= 50000.f)
                {
                    Warning.setString(L"Вы в " + Underfused::StringManip::FloatToString((int)(HubbleSphere.getRadius() - sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2)))) + L" метрах от границы сферы Хаббла");

                    if (HubbleSphere.getRadius() <= sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2)))
                    {
                        Warning.setString(L"Вы попали за границу сферы Хаббла. Игра окончена!");

                        Player->setVelocity(300000.f * (Player->getPosition().x / sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2))), 300000.f * (Player->getPosition().y / sqrt(pow(Player->getPosition().x, 2) + pow(Player->getPosition().y, 2))));
                    }
                }
                else
                {
                    Warning.setString(L"");
                }

                // Форматируем текст предупреждения
                Warning.setScale(ScaleCoefficient, ScaleCoefficient);
                Warning.setOrigin(Warning.getLocalBounds().width / 2, Warning.getLocalBounds().height / 2);
                Warning.setPosition(Player->getPosition().x, Player->getPosition().y - 100 * ScaleCoefficient);

                SendData += CMD_DATA;
                SendData += L"\n";
                SendData += Underfused::Multiplayer::GlobalIdentifier + L"\n" + Underfused::StringManip::IntToString((sf::Int32)Player->getDirectionX()) + L"\n" + Underfused::StringManip::IntToString((sf::Int32)Player->getDirectionY());
            }
        }

        // Обновляем состояние Сфера Хаббла
        HubbleSphere.setRadius(HubbleSphere.getRadius() - 500 * Underfused::GamePhysics::Frame::getDuration());
        HubbleSphere.setOrigin(HubbleSphere.getRadius(), HubbleSphere.getRadius());

        if (SendCooldown.getElapsedTime().asSeconds() >= SEND_COOLDOWN)
        {
            Client << SendData;
            Client.sendData();
            Client.clearSendPacket();
            SendData.clear();
        }
        else
            SendData.clear();

        Underfused::GUI::Window.setView(View);

        Underfused::GUI::Window.clear(sf::Color::Red);

        Underfused::GUI::Window.draw(HubbleSphere);

        for (float i = round((View.getCenter().x - View.getSize().x / 2) / 200) * 200; i < View.getCenter().x + View.getSize().x / 2; i += 200)
        {
            if (i == 0)
            {
                Grid[0].color = sf::Color::White;
                Grid[1].color = sf::Color::White;
            }
            else
            {
                Grid[0].color = sf::Color(255, 255, 255, 127);
                Grid[1].color = sf::Color(255, 255, 255, 127);
            }

            Grid[0].position = sf::Vector2f(i, View.getCenter().y - View.getSize().y / 2);
            Grid[1].position = sf::Vector2f(i, View.getCenter().y + View.getSize().y / 2);

            Underfused::GUI::Window.draw(Grid);
        }

        // Отрисовка горизонтальных полос сетки
        for (float i = round((View.getCenter().y - View.getSize().y / 2) / 200) * 200; i < View.getCenter().y + View.getSize().y / 2; i += 200)
        {
            if (i == 0)
            {
                Grid[0].color = sf::Color::White;
                Grid[1].color = sf::Color::White;
            }
            else
            {
                Grid[0].color = sf::Color(255, 255, 255, 127);
                Grid[1].color = sf::Color(255, 255, 255, 127);
            }

            Grid[0].position = sf::Vector2f(View.getCenter().x - View.getSize().x / 2, i);
            Grid[1].position = sf::Vector2f(View.getCenter().x + View.getSize().x / 2, i);

            Underfused::GUI::Window.draw(Grid);
        }

        for (std::list<Underfused::GamePhysics::Player>::iterator Player = Players.begin(); Player != Players.end(); Player++)
            Underfused::GUI::Window.draw(*Player);

        Underfused::GUI::Window.draw(Warning);

        Underfused::GUI::Window.display();
    }

    Client.clearSendPacket();
    SendData.clear();
    SendData += CMD_DISCONNECT;
    SendData += L"\n";
    SendData += Underfused::Multiplayer::GlobalIdentifier;
    Client << SendData;
    Client.sendData();
}
