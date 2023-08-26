#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

#include "System/Global.hpp"

class Button : public sf::Drawable
{
public:
    Button() { }
    
    Button& setOrigin(sf::Vector2f origin) {m_button.setOrigin(origin); return *this;}
    Button& setButtonPosition(sf::Vector2f position) {m_button.setPosition(position); return *this;}
    Button& setButtonSize(sf::Vector2f size) {m_button.setSize(size); return *this;}
    Button& setButtonColor(sf::Color color) {m_button.setFillColor(color); return *this;}
    Button& setButtonOutlineColor(sf::Color color) {m_button.setOutlineColor(color); return *this;}
    Button& setButtonOutlineThickness(float thickness) {m_button.setOutlineThickness(thickness); return *this;}
    Button& setButtonTexture(sf::Texture& texture) {m_button.setTexture(&texture); return *this;}
    
    Button& setFont(sf::Font font) {m_text.setFont(font); return *this;}
    Button& setTextCenter();
    Button& setTextString(std::string string) {m_text.setString(string); return *this;}
    Button& setTextSize(unsigned int size) {m_text.setCharacterSize(size); return *this;}
    Button& setTextColor(sf::Color color) {m_text.setFillColor(color); return *this;}
    Button& setTextPosition(sf::Vector2f position) {m_text.setPosition(position); return *this;}
    
    Button& setButtonOnClick(std::function<void()> functionOnClick) {m_onClick = functionOnClick; return *this;}
    Button& setButtonOnHover(std::function<void()> functionOnHover) {m_onHover = functionOnHover; return *this;}
    Button& setButtonOnUpdate(std::function<void()> functionOnUpdate) {m_onUpdate = functionOnUpdate; return *this;}
    
    void update(const sf::RenderWindow & window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::RectangleShape m_button = sf::RectangleShape(sf::Vector2f(100, 50));
    sf::Text m_text = sf::Text("Button", defaultFont(), 24);
    
    std::function<void()> m_onClick;
    std::function<void()> m_onHover;
    std::function<void()> m_onRelease;
    std::function<void()> m_onUpdate;
    
    static bool isMouseDown;
};

