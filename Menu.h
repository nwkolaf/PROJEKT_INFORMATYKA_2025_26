#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Menu
{
public:
    Menu(float width, float height);
    void draw(sf::RenderTarget& window);
    void moveUp();
    void moveDown();
    int getPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menuItems;
};