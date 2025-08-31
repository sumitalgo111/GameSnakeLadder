// SnakeLadderQuick.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

int main()
{
	UserInput uInput;
	uInput.takeInput();
	Game& newGame = Game::getInstance(uInput);

	if (newGame.play() == 0)
	{
		std::cout << "Game completed" << std::endl;

	}

	return 0;
}

