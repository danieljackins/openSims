#include "player.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(float x, float y)
{
    this->x = x;
    this->y = y;  
    width = 100;
    height = 100;
    speed = 0.5;
    
    end_x, end_y, start_x, start_y, vec_x, vec_y = 0;
    distance, distance_travelled = 0;
    moving = false;
    
    playerRect.setSize(sf::Vector2f(width,height));
    playerRect.setPosition(x,y);  
}
    
void Player::move_player(int x_direction, int y_direction)
{
    y += y_direction*speed;
    x += x_direction*speed;
}

void Player::move_to(float x, float y)
{
    this->moving = true;
    
    sf::Vector2<float> end = sf::Vector2<float> (x ,y);
    sf::Vector2<float> start = sf::Vector2<float> (this->x, this->y);
    distance = sqrt((end.y-start.y)*(end.y-start.y) + (end.x-start.x)*(end.x-start.x));
    
    this->start_y = start.y;
    this->start_x = start.x;
    this->end_x = end.x;
    this->end_y = end.y;
    sf::Vector2<float> vec = end-start;
    this->vec_x = vec.x;
    this->vec_y = vec.y;
    
    float magnitude = sqrt(vec.x*vec.x + vec.y*vec.y);
    
    this->vec_x /= magnitude;
    this->vec_y /= magnitude;
    
}

void Player::update()
{
    if (this->moving)
    {
        this->x += this->vec_x*speed;
        this->y += this->vec_y*speed;
       
        this->distance_travelled = sqrt((this->x-this->start_x)*(this->x-this->start_x)+(this->y-this->start_y)*(this->y-this->start_y));

        if (this->distance_travelled >= this->distance)
        {
            this->x = this->end_x;
            this->y = this->end_y;
            this->moving = false;
            this->distance,this->distance_travelled = 0;
            this->end_x,end_y = 0;
        }
    }

    playerRect.setPosition(x,y);
}

int Player::get_width()
{
    return width;
}

int Player::get_height()
{
    return height;
}

sf::RectangleShape Player::get_shape()
{
    return playerRect;
}
    

