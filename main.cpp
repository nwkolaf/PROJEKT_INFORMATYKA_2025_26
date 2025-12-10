#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>   

enum class GameState { Menu, Playing, Exiting };

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Arkanoid");
    window.setFramerateLimit(60);

    Menu menu(800, 600); 
    Game game;          
    
    GameState state = GameState::Menu; 
    sf::Clock clock; 

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();

            if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>())
            {
                if (state == GameState::Menu)
                {
                    if (keyEvent->code == sf::Keyboard::Key::Up) menu.moveUp();
                    if (keyEvent->code == sf::Keyboard::Key::Down) menu.moveDown();
                    
                    if (keyEvent->code == sf::Keyboard::Key::Enter)
                    {
                        int wybrane = menu.getPressedItem();
                        
                        if (wybrane == 0) 
                        {
                            game.reset(); 
                            state = GameState::Playing;
                        }
                        
                        if (wybrane == 1) 
                        {
                            if (game.loadGame()) {
                                state = GameState::Playing;
                            } else {
                                std::cout << "brak pliku" << std::endl;
                            }
                        }
                        if (wybrane == 2) window.close(); 
                    }
                }
                else if (state == GameState::Playing)
                {
                    if (keyEvent->code == sf::Keyboard::Key::Escape) state = GameState::Menu; 
                    if (keyEvent->code == sf::Keyboard::Key::F5) game.saveGame();
                }
            }
        }

        if (state == GameState::Playing)
        {
            if (game.update(dt) == false)
            {
                state = GameState::Menu;
                game.reset(); 
            }
        }

        window.clear(); 

        if (state == GameState::Menu) menu.draw(window); 
        else if (state == GameState::Playing) game.render(window); 

        window.display(); 
    }

    return 0;
}