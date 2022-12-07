#include "StringManip.hpp"

sf::String Underfused::StringManip::FloatToString(const float& Value)
{
    std::stringstream StringStream;

    StringStream.precision(15);
    StringStream << Value;

    return StringStream.str();
}

float Underfused::StringManip::StringToFloat(const sf::String& Value, bool& Ok)
{
    std::stringstream StringStream(Value.toAnsiString());
    float NewValue;

    StringStream >> NewValue;
    Ok = !StringStream.fail();

    return NewValue;
}

sf::String Underfused::StringManip::IntToString(const sf::Int32& Value)
{
    std::stringstream StringStream;

    StringStream << Value;

    return StringStream.str();
}

sf::Int32 Underfused::StringManip::StringToInt(const sf::String& Value, bool& Ok)
{
    std::stringstream StringStream(Value.toAnsiString());
    sf::Int32 NewValue;

    StringStream >> NewValue;
    Ok = !StringStream.fail();

    return NewValue;
}
