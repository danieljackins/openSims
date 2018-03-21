#include "menu.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "button.h"

Menu::Menu(float x, float y)
{
    this->x = x;
    this->y = y;
    width = 300; 
    height = 99;
    open = false;
    font.loadFromFile("font.ttf");
    sf::Color black;
    for (int i = 0; i <= 2; i++)
    {
        entries[i] = Button(this->x, this->y + i*33, "");
    }
    
    menuRect.setSize(sf::Vector2f(width,height));
    menuRect.setPosition(x,y);  
}

void Menu::add_entry(std::string entry)
{
    for (int i = 0; i <= 2; i++)
    {
        if (entries[i].get_text().getString() == "")
        {
            entries[i].get_text().setString(entry);
            return;
        }
    }
}

void Menu::set_position(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Menu::set_open(bool value)
{
    open = value;
}

bool Menu::get_open()
{
    return open;
}

sf::RectangleShape Menu::get_shape()
{
    return menuRect;
}

sf::Text* Menu::get_menu()
{
    return entries;
}

void Menu::update()
{
    for (int i = 0; i <= 2; i++)
    {
        entries[i].get_text().setPosition(x,y+(i*entries[i].getCharacterSize()));
        entries[i].get_shape().setPosition(x,y+(i*entries[i].getCharacterSize())); 
    }
    menuRect.setPosition(x,y);
}
