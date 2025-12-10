#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height)
{
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
       if (!font.openFromFile("C:/Windows/Fonts/verdana.ttf")) {}
    }

    sf::Text gra(font, "Nowa Gra"); 
    gra.setFillColor(sf::Color::Red);
    gra.setPosition({width / 2 - 50, height / 2 - 100});
    menuItems.push_back(gra);

    sf::Text wczytaj(font, "Wczytaj Gre");
    wczytaj.setFillColor(sf::Color::White);
    wczytaj.setPosition({width / 2 - 50, height / 2 - 20});
    menuItems.push_back(wczytaj);

    sf::Text wyjscie(font, "Wyjscie");
    wyjscie.setFillColor(sf::Color::White);
    wyjscie.setPosition({width / 2 - 50, height / 2 + 60});
    menuItems.push_back(wyjscie);

    selectedItemIndex = 0;
}

void Menu::draw(sf::RenderTarget& window)
{
    for (int i = 0; i < menuItems.size(); i++)
    {
        window.draw(menuItems[i]);
    }
}

void Menu::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedItemIndex + 1 < menuItems.size())
    {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}