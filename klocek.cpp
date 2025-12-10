#include "Klocek.h" 

Klocek::Klocek(float startX, float startY, float szerokosc, float wysokosc, int startHp)
{
    shape.setSize(sf::Vector2f(szerokosc, wysokosc));
    shape.setPosition({startX, startY});
    
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1.f);

    jestAktywny = true;
    hp = startHp;
    
    aktualizujKolor();
}

void Klocek::aktualizujKolor()
{
    if (hp >= 3) {
        shape.setFillColor(sf::Color::Red);
    } else if (hp == 2) {
        shape.setFillColor(sf::Color(255, 165, 0)); 
    } else {
        shape.setFillColor(sf::Color::Yellow); 
    }
}

void Klocek::rysuj(sf::RenderTarget& target)
{
    if (jestAktywny)
    {
        target.draw(shape);
    }
}

sf::FloatRect Klocek::getGlobalBounds()
{
    return shape.getGlobalBounds();
}