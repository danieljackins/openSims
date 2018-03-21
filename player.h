#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Player
{
    private:
    
    float x, y;
    float speed;
    int width, height;
    float end_x, end_y, start_x, start_y, vec_x, vec_y;
    bool moving;
    float distance, distance_travelled;
    
    sf::RectangleShape playerRect;
    
    public:

    Player(float x, float y);
    void move_player(int x_direction, int y_direction);
    void move_to(float x, float y);
    void update();
    int get_width();
    int get_height();
    sf::RectangleShape get_shape();
};

#endif
