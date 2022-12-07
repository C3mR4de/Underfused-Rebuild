#ifndef STRINGMANIP_HPP_INCLUDED // Защита от повторного включения
#define STRINGMANIP_HPP_INCLUDED

#include <SFML/System/String.hpp> // Строки
#include <sstream> // Строковые потоки
#include <vector> // Векторы
#include <algorithm> // Алгоритмы

// Пространство имён игры
namespace Underfused
{
    namespace StringManip
    {
        sf::String FloatToString(const float&);
        float StringToFloat(const sf::String&, bool&);

        sf::String IntToString(const sf::Int32&);
        sf::Int32 StringToInt(const sf::String&, bool&);
    }
}

#endif // STRINGMANIP_HPP_INCLUDED
