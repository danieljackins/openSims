#include "button.h"
#include <string>

Button::Button(float x, float y, string text)
{
    this->x = x;
    this->y = y;
    width = 300;
    height = 33;
    
    buttonRect.setSize(sf::Vector2f(width,height));
    buttonRect.setPosition(x,y);
    
    sf::Color black;
    font.loadFromFile("font.ttf");
    buttonText(text, font);
    buttonText.setCharacterSize(30);
}

sf::RectangleShape Button::get_shape()
{
    return buttonRect;
}

sf::Text Button::get_text()
{
    return buttonText;
}

void update()
{
    buttonRect.setPosition(x,y);
}


#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    private:
    
    int width, height;
    float x, y;
    
    sf::RectangleShape buttonRect;
    sf::Text buttonText;
    
    public:
    
    Button(float x, float y);
    void get_shape();
    void update();
};

#endif
