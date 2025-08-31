#include "Game.h"
#include <iostream>

Game::Game(Board& board, Dice& dice, Rule& rule, Strategy& strategy, const std::vector<Player>& players)
    : board(board), dice(dice), rule(rule), strategy(strategy), isGameFinished(false) {

    for(auto player : players) {
		addPlayer(player);
	}
}

Game::~Game()
{
    for(auto player : players) {
        delete player;
    }
	players.clear();
}

void Game::addPlayer(Player& player) {
    players.push_back(new Player(player));
}

bool Game::isGameOver() {
    return isGameFinished;
}

int Game::play() {
    // Example: Play logic (implement actual logic as needed)
    // Returns the id of the winning player or -1
    try {
        while (!players.empty() && !isGameOver()) {
            std::cout << "\nPress any key and enter for continue...";
            std::cin.get();

            Player* player = (players.front());
            players.pop_front();
            players.push_back(player);
			std::cout << "Player " << player->getName() << "'s turn. Current position: " << player->getPos() << std::endl;

            //player run dice
            int dvalue = dice.roll();
            //if not valid move skip the player chance
            if (!rule.isValidMove(player->getPos(), dvalue, board))
            {
                std::cout << "Invalid Move!\n";
                continue;
            }


            //calculate new position
            int newpos = rule.calculateNewPos(player->getPos(), dvalue, board);
            player->setPos(newpos);

            isGameFinished = rule.isPlayerWin(player->getPos(), board);
        }

        if (isGameOver()) {
            std::cout << "Player " << players.back()->getName() << " wins!" << std::endl;
			return players.back()->getId(); // Return the winning player's ID
		}
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1; // Indicate an error occurred
	}

    return 0;
}

Game& Game::getInstance(const UserInput& uInput)
{
    Board& board = Board::getInstance(uInput.boardSize);
	Dice& dice = (Dice::getInstance(uInput.diceFace));
    //set StandardRule as default
	Rule& rule = (StandardRule::getInstance());
    Strategy& strategy = BuilderStrategy::createStrategy(uInput.strategyType);

    return *(new Game(board, dice, rule, strategy, uInput.players));
}