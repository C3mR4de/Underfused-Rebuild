#include "GUI.hpp"

sf::RenderWindow Underfused::GUI::Window(sf::VideoMode(800, 600), L"Underfused", sf::Style::Default);
sf::Event Underfused::GUI::Event;
sf::Font Underfused::GUI::Font;
sf::Text Underfused::GUI::MessageBox(L"", Underfused::GUI::Font);

Underfused::GUI::Enums::MenuType Underfused::GUI::Menu = Underfused::GUI::Enums::MainMenu;

sf::Vector2f Underfused::GUI::GlobalParameters::MousePosition = sf::Vector2f();
bool Underfused::GUI::GlobalParameters::IsMouseHeld = false;
bool Underfused::GUI::GlobalParameters::WasMouseHeld = false;

void Underfused::GUI::takeScreenshot()
{
    sf::Texture Texture;
    Texture.create(Underfused::GUI::Window.getSize().x, Underfused::GUI::Window.getSize().y);
    Texture.update(Underfused::GUI::Window);
    sf::Image Screenshot = Texture.copyToImage();

    time_t CurrentTime = time(NULL);
    sf::String DateAndTime = ctime(&CurrentTime);
    DateAndTime.erase(DateAndTime.getSize() - 1);

    for (sf::Uint16 i = 0; i < DateAndTime.getSize(); i++)
    {
        if (DateAndTime[i] == ':')
            DateAndTime[i] = '-';
    }

    Screenshot.saveToFile("Screenshots/" + DateAndTime + ".png");
}

sf::Vector2f Underfused::GUI::GlobalParameters::getMousePosition()
{
    return MousePosition;
}

bool Underfused::GUI::GlobalParameters::isMouseHeld()
{
    return IsMouseHeld;
}

bool Underfused::GUI::GlobalParameters::wasMouseHeld()
{
    return WasMouseHeld;
}

void Underfused::GUI::GlobalParameters::update()
{
    WasMouseHeld = IsMouseHeld; // Переприсваиваем значение переменной
    MousePosition = sf::Vector2f(sf::Mouse::getPosition(Window).x / (Window.getSize().x / Window.getDefaultView().getSize().x), sf::Mouse::getPosition(Window).y / (Window.getSize().y / Window.getDefaultView().getSize().y)); // Присваиваем значение позиции мыши
    IsMouseHeld = sf::Mouse::isButtonPressed(sf::Mouse::Left); // Смотрим, нажата ли мышь
}

void Underfused::GUI::ClickableText::draw(sf::RenderTarget& Target, sf::RenderStates States) const
{
    Target.draw(Text, States);
}

Underfused::GUI::ClickableText::ClickableText(sf::Font& Font, sf::String String)
{
    Text = sf::Text(String, Font); // Создаём наш текст

    Text.setFillColor(sf::Color::Black); // Установка цвета текста
    Text.setOutlineThickness(3); // Установка толщины обводки
    Text.setOutlineColor(sf::Color::Black); // Установка цвета обводки

    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2); // Установка центра текста
    Text.setPosition(Window.getDefaultView().getCenter()); // Установка позиции текста
}

void Underfused::GUI::ClickableText::setAction(void (*Action)())
{
    this->Action = Action;
}

void Underfused::GUI::ClickableText::update()
{
    if (isMouseHovered()) // Если мышь наведена на кнопку
    {
        if (Underfused::GUI::GlobalParameters::isMouseHeld()) // Если при этом ЛКМ зажата
        {
            if (!IsMouseHeldAway) // И она не была зажата ранее вне кнопки
                Text.setOutlineColor(sf::Color::Blue); // То окрашиваем обводку кнопки в синий цвет
            else
                Text.setOutlineColor(sf::Color(127, 127, 255)); // Иначе окрашиваем в голубой
        }
        else // Если же ЛКМ не нажата
        {
            if (Underfused::GUI::GlobalParameters::wasMouseHeld() && !IsMouseHeldAway) // Если при этом мышь была наведена на кнопку кадр назад и не зажата вне кнопки
            {
                // Здесь должно быть то, что делает кнопка
                Action();
            }

            Text.setOutlineColor(sf::Color(127, 127, 255)); // Окрашиваем в голубой цвет
            IsMouseHeldAway = false; // Мышь не зажата вне кнопки
        }
    }
    else // Если мышь не наведена на кнопку
    {
        Text.setOutlineColor(sf::Color::White); // Окрашиваем обводку в белый цвет
        IsMouseHeldAway = Underfused::GUI::GlobalParameters::isMouseHeld(); // В зависимости от состояния ЛКМ она зажата или не зажата вне кнопки
    }

    WasMouseHovered = isMouseHovered(); // Обновляем состояние наведения кадр назад
}

      // Наведена ли мышь на кнопку
bool Underfused::GUI::ClickableText::isMouseHovered()
{
    return Text.getGlobalBounds().contains(Underfused::GUI::GlobalParameters::getMousePosition());
}

// Была ли наведена мышь на кнопку кадр назад
bool Underfused::GUI::ClickableText::wasMouseHovered()
{
    return WasMouseHovered;
};

void Underfused::GUI::ClickableText::setPosition(float X, float Y)
{
    Text.setPosition(X, Y);
}

void Underfused::GUI::ClickableText::setPosition(sf::Vector2f Position)
{
    Text.setPosition(Position);
}
