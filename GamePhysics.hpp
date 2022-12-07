#ifndef GAMEPHYSICS_HPP_INCLUDED
#define GAMEPHYSICS_HPP_INCLUDED

#include "GUI.hpp"

#define PI acos(-1) // Число пи

namespace Underfused
{
    namespace GamePhysics
    {
        class Frame
        {
            static sf::Clock Counter;
            static float Duration;

        public:

            static void update();
            static float getDuration();
        };

        namespace Enums
        {
            enum Direction
            {
                Negative = -1,
                Neutral,
                Positive
            };

            enum Team
            {
                Antimatter = -1,
                None,
                Matter
            };
        }

        class Player: public sf::Drawable
        {
            void draw(sf::RenderTarget&, sf::RenderStates) const;

            sf::CircleShape Body;
            sf::Text Nickname;

            sf::String Identifier;
            sf::String NicknameString;
            Enums::Team Team;
            float Size;
            sf::Vector2f Position;
            sf::Vector2f Velocity;
            sf::Vector2f Acceleration;
            Enums::Direction DirectionX;
            Enums::Direction DirectionY;

        public:

            Player();

            Player(sf::String, sf::String, Enums::Team, float);

            void control();
            void update(float);

            sf::String getIdentifier();
            sf::String getNickname();
            Enums::Team getTeam();
            float getSize();
            sf::Vector2f getPosition();
            sf::Vector2f getVelocity();
            sf::Vector2f getAcceleration();
            Enums::Direction getDirectionX();
            Enums::Direction getDirectionY();

            void setIdentifier(sf::String);
            void setNickname(sf::String);
            void setTeam(Enums::Team);
            void setSize(float);
            void setPosition(float, float);
            void setPosition(sf::Vector2f);
            void setVelocity(float, float);
            void setVelocity(sf::Vector2f);
            void setAcceleration(float, float);
            void setAcceleration(sf::Vector2f);
            void setDirectionX(Enums::Direction);
            void setDirectionY(Enums::Direction);
        };
    }
}

#endif // GAMEPHYSICS_HPP_INCLUDED
