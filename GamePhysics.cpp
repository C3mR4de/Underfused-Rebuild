#include "GamePhysics.hpp"

sf::Clock Underfused::GamePhysics::Frame::Counter;
float Underfused::GamePhysics::Frame::Duration;

void Underfused::GamePhysics::Frame::update()
{
    Duration = Counter.restart().asSeconds();
}

float Underfused::GamePhysics::Frame::getDuration()
{
    return Duration;
}

void Underfused::GamePhysics::Player::draw(sf::RenderTarget& Target, sf::RenderStates States) const
{
    Target.draw(Body, States);
    Target.draw(Nickname, States);
}

Underfused::GamePhysics::Player::Player()
{
    Body = sf::CircleShape(50);
    Body.setOrigin(Body.getRadius(), Body.getRadius());
    Body.setOutlineThickness(2);

    Body.setFillColor(sf::Color::White);
    Body.setOutlineColor(sf::Color(127, 127, 127));

    this->Nickname = sf::Text(L"Игрок", Underfused::GUI::Font);
    this->Nickname.setOrigin(this->Nickname.getLocalBounds().width / 2, this->Nickname.getLocalBounds().height / 2);
    this->Nickname.setFillColor(sf::Color::Black);
    this->Nickname.setOutlineThickness(3);
    this->Nickname.setOutlineColor(sf::Color::White);

    this->Identifier = L"0000000000000000";
    NicknameString = L"Игрок";
    this->Team = Enums::None;
    this->Size = 50;
    Position = sf::Vector2f();
    Velocity = sf::Vector2f();
    Acceleration = sf::Vector2f(10000 / Size, 10000 / Size);
    DirectionX = Enums::Neutral;
    DirectionY = Enums::Neutral;
}

Underfused::GamePhysics::Player::Player(sf::String Nickname = L"Игрок", sf::String Identifier = L"0000000000000000", Enums::Team Team = Enums::None, float Size = 50)
{
    Body = sf::CircleShape(Size);
    Body.setOrigin(Body.getRadius(), Body.getRadius());
    Body.setOutlineThickness(2);

    switch (Team)
    {
        case Enums::Matter:

            Body.setFillColor(sf::Color::Red);
            Body.setOutlineColor(sf::Color(127, 0, 0));

            break;

        case Enums::Antimatter:

            Body.setFillColor(sf::Color::Cyan);
            Body.setOutlineColor(sf::Color(0, 127, 127));

            break;

        default:

            Body.setFillColor(sf::Color::White);
            Body.setOutlineColor(sf::Color(127, 127, 127));

            break;
    }

    this->Nickname = sf::Text(Nickname, Underfused::GUI::Font);
    this->Nickname.setOrigin(this->Nickname.getLocalBounds().width / 2, this->Nickname.getLocalBounds().height / 2);
    this->Nickname.setFillColor(sf::Color::Black);
    this->Nickname.setOutlineThickness(3);
    this->Nickname.setOutlineColor(sf::Color::White);

    this->Identifier = Identifier;
    NicknameString = Nickname;
    this->Team = Team;
    this->Size = Size;
    Position = sf::Vector2f();
    Velocity = sf::Vector2f();
    Acceleration = sf::Vector2f(10000 / Size, 10000 / Size);
    DirectionX = Enums::Neutral;
    DirectionY = Enums::Neutral;
}

void Underfused::GamePhysics::Player::control()
{
    // Задаём направление движения по X
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        DirectionX = Enums::Negative;
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        DirectionX = Enums::Positive;
    else
        DirectionX = Enums::Neutral;

    // Задаём направление движения по Y
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        DirectionY = Enums::Negative;
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        DirectionY = Enums::Positive;
    else
        DirectionY = Enums::Neutral;
}

void Underfused::GamePhysics::Player::update(float ScaleCoefficient)
{
    Acceleration = sf::Vector2f(10000 / Size, 10000 / Size); // Задаём ускорёние в зависимости от размера

    Velocity.x += DirectionX * Acceleration.x * Underfused::GamePhysics::Frame::getDuration(); // Изменяем скорость по оси X
    Velocity.y += DirectionY * Acceleration.y * Underfused::GamePhysics::Frame::getDuration(); // И по оси Y

    Position.x += Velocity.x * Underfused::GamePhysics::Frame::getDuration(); // Изменяем координату на оси X
    Position.y += Velocity.y * Underfused::GamePhysics::Frame::getDuration(); // И на оси Y тоже

    Body.setOrigin(Body.getRadius(), Body.getRadius()); // Меняем точку отсчёта игрока
    Body.setPosition(Position); // Задаём позицию для тела

    Nickname.setString(NicknameString);
    Nickname.setOrigin(Nickname.getLocalBounds().width / 2, Nickname.getLocalBounds().height / 2);
    Nickname.setPosition(Position.x - 0 * ScaleCoefficient, Position.y - 5.f * ScaleCoefficient); // И для никнейма
    Nickname.setScale(ScaleCoefficient, ScaleCoefficient);
}

sf::String Underfused::GamePhysics::Player::getIdentifier()
{
    return Identifier;
}

sf::String Underfused::GamePhysics::Player::getNickname()
{
    return NicknameString;
}

Underfused::GamePhysics::Enums::Team Underfused::GamePhysics::Player::getTeam()
{
    return Team;
}

float Underfused::GamePhysics::Player::getSize()
{
    return Size;
}

sf::Vector2f Underfused::GamePhysics::Player::getPosition()
{
    return Position;
}

sf::Vector2f Underfused::GamePhysics::Player::getVelocity()
{
    return Velocity;
}

sf::Vector2f Underfused::GamePhysics::Player::getAcceleration()
{
    return Acceleration;
}

Underfused::GamePhysics::Enums::Direction Underfused::GamePhysics::Player::getDirectionX()
{
    return DirectionX;
}

Underfused::GamePhysics::Enums::Direction Underfused::GamePhysics::Player::getDirectionY()
{
    return DirectionY;
}

void Underfused::GamePhysics::Player::setIdentifier(sf::String Identifier)
{
    this->Identifier = Identifier;
}

void Underfused::GamePhysics::Player::setNickname(sf::String Nickname)
{
    NicknameString = Nickname;
}

void Underfused::GamePhysics::Player::setTeam(Enums::Team Team)
{
    this->Team = Team;
}

void Underfused::GamePhysics::Player::setSize(float Size)
{
    this->Size = Size;
}

void Underfused::GamePhysics::Player::setPosition(float X, float Y)
{
    Position = sf::Vector2f(X, Y);
}

void Underfused::GamePhysics::Player::setPosition(sf::Vector2f Position)
{
    this->Position = Position;
}

void Underfused::GamePhysics::Player::setVelocity(float X, float Y)
{
    Velocity = sf::Vector2f(X, Y);
}

void Underfused::GamePhysics::Player::setVelocity(sf::Vector2f)
{
    this->Velocity = Velocity;
}

void Underfused::GamePhysics::Player::setAcceleration(float X, float Y)
{
    Acceleration = sf::Vector2f(X, Y);
}

void Underfused::GamePhysics::Player::setAcceleration(sf::Vector2f)
{
    this->Acceleration = Acceleration;
}

void Underfused::GamePhysics::Player::setDirectionX(Enums::Direction Direction)
{
    DirectionX = Direction;
}

void Underfused::GamePhysics::Player::setDirectionY(Enums::Direction Direction)
{
    DirectionY = Direction;
}
