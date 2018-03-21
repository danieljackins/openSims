#include <SFML/Graphics.hpp>
#include "player.h"
#include "menu.h"
#include <iostream>
#include <string>

int main()
{
    int windowHeight = 800;
    int windowWidth = 1200;
    
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "openPong");

    Player player (10.0,320.0);
    Menu menu (0.0, 0.0);
    menu.add_entry("test1");
    menu.add_entry("test2");
    menu.add_entry("test3");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move_player(-1,0);
            
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move_player(1,0);
            
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move_player(0,1);
            
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move_player(0,-1);
            
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
            
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            player.move_to(localPosition.x,localPosition.y);
            
            if(menu.get_open())
                menu.set_open(false);
        }
        
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            menu.set_position(localPosition.x, localPosition.y);
            menu.set_open(true);
        }
            
        player.update();

        window.clear();
        window.draw(player.get_shape());
        if (menu.get_open())
        {
            menu.update();
            window.draw(menu.get_shape());
            for (int i = 0; i <= 2; i++)
                window.draw(menu.get_menu()[i]);
        }
        window.display();
    }

    return 0;
}
