#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    private:
    
    int width, height;
    float x, y;
    
    sf::RectangleShape buttonRect;
    sf::Text buttonText;
    sf::Font font;
    
    public:
    
    Button(float x, float y);
    sf::RectangleShape get_shape();
    sf::Text get_text();
    void update();
};

#endif
