#include "Global.hpp"

sf::Font& defaultFont()
{
    static sf::Font font;
    if (font.getInfo().family == "") font.loadFromFile("Resources/Fonts/firaFont.ttf");
    return font;
}