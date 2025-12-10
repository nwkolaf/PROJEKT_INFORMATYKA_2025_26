#pragma once
#include <SFML/Graphics.hpp>

class Pilka
{
public:
    sf::CircleShape shape;
    sf::Vector2f predkosc;

    Pilka(float startX, float startY);
    void rysuj(sf::RenderTarget& target);
    void aktualizuj();
    void setPosition(float x, float y);
    void setVelocity(float vx, float vy);
};