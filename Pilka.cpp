#include "Pilka.h"

Pilka::Pilka(float startX, float startY)
{
    shape.setRadius(10.f); 
    shape.setFillColor(sf::Color::White); 
    shape.setPosition({startX, startY});

    predkosc = sf::Vector2f(5.f, 5.f); 
}

void Pilka::rysuj(sf::RenderTarget& target)
{
    target.draw(shape);
}

void Pilka::aktualizuj()
{
    shape.move(predkosc);

    sf::Vector2f pos = shape.getPosition();
    
    if (pos.x < 0.f) {
        predkosc.x = -predkosc.x;
        shape.setPosition({0.f, pos.y}); 
    }
    else if (pos.x + 20.f > 800.f) {
        predkosc.x = -predkosc.x;
        shape.setPosition({780.f, pos.y}); 
    }
    
    if (pos.y < 0.f) {
        predkosc.y = -predkosc.y;
        shape.setPosition({pos.x, 0.f});
    }
}

void Pilka::setPosition(float x, float y)
{
    shape.setPosition({x, y});
}

void Pilka::setVelocity(float vx, float vy)
{
    predkosc = sf::Vector2f(vx, vy);
}