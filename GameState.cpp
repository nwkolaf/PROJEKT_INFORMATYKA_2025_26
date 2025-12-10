#include "GameState.h"
#include <fstream>
#include <iostream>

void GameState::capture(Paletka& p, std::vector<Pilka>& balls, std::vector<Klocek>& klocki, int currentScore)
{
    paddlePosition = p.shape.getPosition();
    paddleWidth = p.shape.getSize().x;
    savedScore = currentScore;

    ballsData.clear();
    for(auto& b : balls) {
        sf::Vector2f pos = b.shape.getPosition();
        ballsData.push_back({pos.x, pos.y, b.predkosc.x, b.predkosc.y});
    }

    blocksData.clear();
    for (const auto& k : klocki)
    {
        if (k.jestAktywny) 
        {
            sf::Vector2f pos = k.shape.getPosition();
            blocksData.push_back({pos.x, pos.y, k.hp});
        }
    }
}

void GameState::apply(Paletka& p, std::vector<Pilka>& balls, std::vector<Klocek>& klocki, int& currentScore)
{
    p.setPosition(paddlePosition.x, paddlePosition.y);
    p.setWidth(paddleWidth);
    currentScore = savedScore;

    balls.clear();
    for(auto& bData : ballsData) {
        Pilka nowa(bData.x, bData.y);
        nowa.setVelocity(bData.vx, bData.vy);
        balls.push_back(nowa);
    }

    klocki.clear();
    float w = 75.f;
    float h = 20.f;

    for (const auto& data : blocksData)
    {
        klocki.push_back(Klocek(data.x, data.y, w, h, data.hp));
    }
}

bool GameState::saveToFile(const std::string& filename)
{
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    file << "PADDLE " << paddlePosition.x << " " << paddlePosition.y << " " << paddleWidth << "\n";
    file << "SCORE " << savedScore << "\n";

    file << "BALLS " << ballsData.size() << "\n";
    for(const auto& b : ballsData) {
        file << b.x << " " << b.y << " " << b.vx << " " << b.vy << "\n";
    }

    file << "BLOCKS " << blocksData.size() << "\n";
    for (const auto& block : blocksData)
    {
        file << block.x << " " << block.y << " " << block.hp << "\n";
    }

    file.close();
    return true;
}

bool GameState::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string label;
    
    file >> label >> paddlePosition.x >> paddlePosition.y >> paddleWidth;
    file >> label >> savedScore;

    int ballsCount;
    file >> label >> ballsCount;
    ballsData.clear();
    for(int i=0; i<ballsCount; i++) {
        BallData b;
        file >> b.x >> b.y >> b.vx >> b.vy;
        ballsData.push_back(b);
    }

    int count;
    file >> label >> count;
    blocksData.clear();
    for (int i = 0; i < count; i++)
    {
        BlockData data;
        file >> data.x >> data.y >> data.hp;
        blocksData.push_back(data);
    }

    file.close();
    return true;
}