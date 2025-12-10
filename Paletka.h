#pragma once
#include <SFML/Graphics.hpp>

class Paletka
{
public:
    sf::RectangleShape shape;

    Paletka(float startX, float startY);
    void rysuj(sf::RenderTarget& target);
    void aktualizuj(float predkosc);
    void setPosition(float x, float y);
    void setWidth(float width);
};