#include <SFML/Graphics.hpp>

#include <iostream>

#include "UI/Button.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    int counterValue = 0;
    
    Button counter;
    counter.setButtonSize(sf::Vector2f(200, 100));
    counter.setOrigin(sf::Vector2f(100, 50));
    counter.setButtonColor(sf::Color::Red);
    counter.setButtonPosition(sf::Vector2f(400, 300));
    counter.setTextPosition(sf::Vector2f(400, 300));
    counter.setTextString(std::to_string(counterValue) + " clicks");
    counter.setTextSize(30);
    counter.setTextColor(sf::Color::Green);
    counter.setTextCenter();
    counter.setButtonOnClick([&counterValue, &counter](){
        counterValue++;
        counter.setTextString(std::to_string(counterValue) + " clicks");
    });
    counter.setButtonOnUpdate([&counter](){
        counter.setButtonColor(sf::Color::Red);
        counter.setTextColor(sf::Color::Green);
    });
    counter.setButtonOnHover([&counter](){
        counter.setButtonColor(sf::Color::Blue);
        counter.setTextColor(sf::Color::Red);
    });
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        
        counter.update(window);
        
        window.clear();
            window.draw(shape);
            window.draw(counter);

        window.display();
    }

    return 0;
}