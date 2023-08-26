#include "Button.hpp"

bool Button::isMouseDown = false;

void Button::update(const sf::RenderWindow & window)
{
    if (m_onUpdate) m_onUpdate();
    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (m_button.getGlobalBounds().contains(mousePosition) && m_onHover)
    {
        m_onHover();
    }
    
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        isMouseDown = false;
    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) 
        && m_button.getGlobalBounds().contains(mousePosition)
        && m_onClick)
    {
        if (!isMouseDown)
        {
            m_onClick();
            isMouseDown = true;
        }
    }
}

Button& Button::setTextCenter()
{
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    
    return *this;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_button, states);
    target.draw(m_text, states);    
}