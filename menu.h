#ifndef MENU_H
#define MENU_H

#include <string>
#include <SFML/Graphics.hpp>
#include "button.h"

class Menu
{
    private:
    
    float x,y;
    int width,height;
    Button entries[3];
    bool open;
    sf::Font font;
    
    
    sf::RectangleShape menuRect;
    
    public:
    
    Menu(float x, float y);
    
    void add_entry(std::string entry);
    void update();
    void set_position(float x, float y);
    void set_open(bool value);
    sf::RectangleShape get_shape();
    bool get_open();
    sf::Text* get_menu();
};

#endif
