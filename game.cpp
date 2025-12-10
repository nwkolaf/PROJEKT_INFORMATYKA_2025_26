#include "Game.h"
#include "GameState.h"
#include <string> 
#include <cstdlib> 
#include <ctime>

Game::Game() : 
    paletka(400.f, 550.f),
    score(0),
    textPoints(font)
{
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
         if (!font.openFromFile("C:/Windows/Fonts/verdana.ttf")) {}
    }

    textPoints.setCharacterSize(24);
    textPoints.setFillColor(sf::Color::White);
    textPoints.setPosition({10.f, 10.f});
    textPoints.setString("Punkty: 0");

    Pilka startowa(400.f, 300.f);
    startowa.setVelocity(5.f, 5.f);
    pilki.push_back(startowa);

    const int iloscKolumn = 10;
    const int iloscRzedow = 4;
    const float szerokoscKlocka = 75.f;
    const float wysokoscKlocka = 20.f;
    const float odstep = 5.f;

    for (int rzad = 0; rzad < iloscRzedow; ++rzad)
    {
        for (int kolumna = 0; kolumna < iloscKolumn; ++kolumna)
        {
            float posX = (szerokoscKlocka + odstep) * kolumna;
            float posY = (wysokoscKlocka + odstep) * rzad + 50.f; 
            
            int startHp = (iloscRzedow - rzad); 
            if (startHp > 3) startHp = 3; 

            klocki.push_back(Klocek(posX, posY, szerokoscKlocka, wysokoscKlocka, startHp));
        }
    }
}

bool Game::update(sf::Time dt)
{
    paletka.aktualizuj(predkoscPaletki);
    
    textPoints.setString("Punkty: " + std::to_string(score));
    sf::FloatRect paletkaBounds = paletka.shape.getGlobalBounds();

    for (size_t i = 0; i < pilki.size(); i++)
    {
        Pilka& aktualnaPilka = pilki[i];
        aktualnaPilka.aktualizuj();

        sf::FloatRect pilkaBounds = aktualnaPilka.shape.getGlobalBounds();

        if (pilkaBounds.findIntersection(paletkaBounds))
        {
            if (aktualnaPilka.predkosc.y > 0.f) aktualnaPilka.predkosc.y = -aktualnaPilka.predkosc.y;
        }

        for (Klocek& klocek : klocki)
        {
            if (!klocek.jestAktywny) continue; 

            sf::FloatRect klocekBounds = klocek.getGlobalBounds();
            if (pilkaBounds.findIntersection(klocekBounds))
            {
                klocek.hp--; 
                klocek.aktualizujKolor(); 

                aktualnaPilka.predkosc.y = -aktualnaPilka.predkosc.y;

                if (klocek.hp <= 0)
                {
                    klocek.jestAktywny = false;
                    score += 10;

                    if (rand() % 5 == 0) {
                        bonusy.push_back(Bonus(klocekBounds.position.x, klocekBounds.position.y));
                    }
                }
                else 
                {
                    score += 1;
                }
                break; 
            }
        }
        
        if (aktualnaPilka.shape.getPosition().y > 600.f) {
            pilki.erase(pilki.begin() + i);
            i--;
        }
    }

    for (auto& b : bonusy) {
        b.update();
        if (b.active && b.getBounds().findIntersection(paletkaBounds)) {
            b.active = false;
            score += 50; 

            if (b.type == MULTIBALL) {
                Pilka nowa(paletkaBounds.position.x + 50.f, 540.f);
                float randX = ((rand() % 100) / 10.f) - 5.f;
                nowa.setVelocity(randX, -5.f);
                pilki.push_back(nowa);
            }
            else if (b.type == RESIZE_PADDLE) {
                if (rand() % 2 == 0) paletka.setWidth(150.f);
                else paletka.setWidth(50.f);
            }
        }
    }

    if (pilki.empty())
    {
        return false; 
    }

    return true; 
}

void Game::render(sf::RenderTarget& target)
{
    paletka.rysuj(target);
    for(auto& p : pilki) p.rysuj(target);
    for (Klocek& klocek : klocki) klocek.rysuj(target);
    for (auto& b : bonusy) b.draw(target);
    target.draw(textPoints);
}

void Game::reset()
{
    paletka.shape.setPosition({400.f, 550.f});
    paletka.setWidth(100.f);
    
    pilki.clear();
    Pilka startowa(400.f, 300.f);
    startowa.setVelocity(5.f, 5.f);
    pilki.push_back(startowa);
    
    score = 0;
    bonusy.clear();
    
    klocki.clear();
    const int iloscKolumn = 10;
    const int iloscRzedow = 4;
    const float szerokoscKlocka = 75.f;
    const float wysokoscKlocka = 20.f;
    const float odstep = 5.f;

    for (int rzad = 0; rzad < iloscRzedow; ++rzad)
    {
        for (int kolumna = 0; kolumna < iloscKolumn; ++kolumna)
        {
            float posX = (szerokoscKlocka + odstep) * kolumna;
            float posY = (wysokoscKlocka + odstep) * rzad + 50.f; 
            int startHp = (iloscRzedow - rzad); 
            if (startHp > 3) startHp = 3;
            klocki.push_back(Klocek(posX, posY, szerokoscKlocka, wysokoscKlocka, startHp));
        }
    }
}

void Game::saveGame()
{
    GameState state;
    state.capture(paletka, pilki, klocki, score);
    state.saveToFile("savegame.txt");
}

bool Game::loadGame()
{
    GameState state;
    if (state.loadFromFile("savegame.txt"))
    {
        state.apply(paletka, pilki, klocki, score);
        bonusy.clear(); 
        return true;
    }
    return false;
}