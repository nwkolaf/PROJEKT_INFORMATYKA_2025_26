#include "Bonus.h"
#include <cstdlib> 

Bonus::Bonus(float x, float y) {
    active = true;

    if (rand() % 2 == 0) type = MULTIBALL;
    else type = RESIZE_PADDLE;

    shape.setPointCount(3);
    shape.setPoint(0, {0.f, 0.f});
    shape.setPoint(1, {20.f, 0.f});
    shape.setPoint(2, {10.f, 20.f});
    
    if (type == MULTIBALL) shape.setFillColor(sf::Color::Red);
    else shape.setFillColor(sf::Color::Cyan);

    shape.setOrigin({10.f, 10.f}); 
    shape.setPosition({x, y});
}

void Bonus::update() {
    if (!active) return;
    
    shape.move({0.f, 3.f}); 
    shape.rotate(sf::degrees(5.f)); 
    
    if (shape.getPosition().y > 600.f) {
        active = false;
    }
}

void Bonus::draw(sf::RenderTarget& target) {
    if (active) target.draw(shape);
}

sf::FloatRect Bonus::getBounds() {
    return shape.getGlobalBounds();
}