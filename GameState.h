#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Paletka.h"
#include "Pilka.h"
#include "Klocek.h"

struct BlockData {
    float x, y;
    int hp; 
};

struct BallData {
    float x, y, vx, vy;
};

class GameState
{
public:
    sf::Vector2f paddlePosition;
    float paddleWidth;
    
    std::vector<BallData> ballsData;
    std::vector<BlockData> blocksData;
    int savedScore;

    void capture(Paletka& p, std::vector<Pilka>& balls, std::vector<Klocek>& klocki, int currentScore);
    void apply(Paletka& p, std::vector<Pilka>& balls, std::vector<Klocek>& klocki, int& currentScore);

    bool saveToFile(const std::string& filename);
    bool loadFromFile(const std::string& filename);
};