#pragma once
#include <deque>
#include <vector>
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Rule.h"
#include "UserInput.h"

class Game {
private:
    Board& board;
    Dice& dice;
    std::deque<Player*> players;

    Rule& rule;
	Strategy& strategy;
    bool isGameFinished;
public:
    Game(Board& board, Dice& dice, Rule& rule, Strategy& strategy, const std::vector<Player>& Players);
    void addPlayer(Player& player);
    bool isGameOver();
    int play();

    ~Game(); // Destructor declaration
    static Game& getInstance(const UserInput& uInput);
};
