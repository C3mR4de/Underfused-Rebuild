#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <ctime>

namespace Underfused
{
    namespace GUI
    {
        extern sf::RenderWindow Window;
        extern sf::Event Event;
        extern sf::Font Font;
        extern sf::Text MessageBox;

        void takeScreenshot();

        namespace Enums
        {
            enum MenuType
            {
                MainMenu,
                Settings,
                SelectType,
                CreateServer,
                ConnectToServer,
                GameServer,
                GameClient
            };
        }

        extern Enums::MenuType Menu;

        class GlobalParameters
        {
            static sf::Vector2f MousePosition;
            static bool IsMouseHeld;
            static bool WasMouseHeld;

        public:

            static void update();

            static sf::Vector2f getMousePosition();
            static bool isMouseHeld();
            static bool wasMouseHeld();
        };

        class ClickableText: public sf::Drawable
        {
            void draw(sf::RenderTarget&, sf::RenderStates) const;

            sf::Text Text;

            bool WasMouseHovered;
            bool IsMouseHeldAway;

            void (*Action)();

        public:

            ClickableText(sf::Font&, sf::String);

            void setAction(void(*)());
            void update();

            inline bool isMouseHovered();
            inline bool wasMouseHovered();

            void setPosition(float, float);
            void setPosition(sf::Vector2f);
        };
    }
}

#endif // GUI_HPP_INCLUDED
