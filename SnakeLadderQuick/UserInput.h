#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
#include "Strategy.h"

class UserInput {
public:
    int boardSize;
    int diceFace;
    int nofPlayers;
    std::vector<Player> players;
    StrategyType strategyType;

    void takeInput() {
        std::cout << "Enter board size: ";
        std::cin >> boardSize;

        std::cout << "Enter dice face count: ";
        std::cin >> diceFace;

        std::cout << "Select strategy type (0: Standard, 1: Random, 2: Custom): ";
        int stype;

        std::cin >> stype;
        switch (stype) {
        case 0: strategyType = StrategyType::Standard; break;
        case 1: strategyType = StrategyType::Random; break;
        case 2: strategyType = StrategyType::Custom; break;
        default: strategyType = StrategyType::Standard; break;
        }

        std::cout << "Enter number of players: ";
        std::cin >> nofPlayers;
        players.clear();
        for (int i = 0; i < nofPlayers; ++i) {
            std::string name;
            std::cout << "Enter name for player " << (i+1) << ": ";
            std::cin >> name;
            players.push_back(Player(i+1, name));
        }
    }
};
