#include "Paletka.h"

Paletka::Paletka(float startX, float startY)
{
    shape.setSize(sf::Vector2f(100.f, 20.f));
    shape.setFillColor(sf::Color::White);
    shape.setPosition({startX, startY});
}

void Paletka::rysuj(sf::RenderTarget& target)
{
    target.draw(shape);
}

void Paletka::aktualizuj(float predkosc)
{
    float pozycjaX = shape.getPosition().x;
    float szerokosc = shape.getSize().x;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && pozycjaX > 0)
    {
        shape.move({-predkosc, 0.f});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && pozycjaX < 800 - szerokosc)
    {
        shape.move({predkosc, 0.f});
    }
}

void Paletka::setPosition(float x, float y)
{
    shape.setPosition({x, y});
}

void Paletka::setWidth(float width)
{
    shape.setSize({width, 20.f});
}