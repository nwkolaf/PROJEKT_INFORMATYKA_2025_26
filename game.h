#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Paletka.h"
#include "Pilka.h"
#include "Klocek.h" 
#include "Bonus.h" 

class Game
{
public:
    Game(); 
    bool update(sf::Time dt); 
    void render(sf::RenderTarget& target);
    void reset();

    void saveGame();
    bool loadGame();

    int score; 

private:
    Paletka paletka;
    std::vector<Pilka> pilki;
    std::vector<Klocek> klocki;
    std::vector<Bonus> bonusy; 

    const float predkoscPaletki = 10.f;

    sf::Font font;
    sf::Text textPoints;
};