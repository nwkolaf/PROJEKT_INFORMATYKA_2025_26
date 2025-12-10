#pragma once
#include <SFML/Graphics.hpp>

enum BonusType { MULTIBALL, RESIZE_PADDLE };

class Bonus {
public:
    sf::ConvexShape shape; 
    bool active;
    BonusType type; 

    Bonus(float x, float y);
    void update();
    void draw(sf::RenderTarget& target);
    sf::FloatRect getBounds();
};