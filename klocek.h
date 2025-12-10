#pragma once
#include <SFML/Graphics.hpp>

class Klocek
{
public:
    sf::RectangleShape shape;
    bool jestAktywny;
    int hp; 

    Klocek(float startX, float startY, float szerokosc, float wysokosc, int startHp);

    void rysuj(sf::RenderTarget& target);
    sf::FloatRect getGlobalBounds();
    void aktualizujKolor();
};