#include "Strategy.h"
#include "Board.h"

void StandardStrategy::setupBoard(Board& board) {
	//standard board setup logic here
    board.addEntity(*(new Snake(14, 6)));
    board.addEntity(*(new Snake(7, 2)));
    board.addEntity(*(new Ladder(3, 9)));
    board.addEntity(*(new Ladder(1, 11)));
    board.addEntity(*(new Ladder(4, 13)));
}

void RandomStrategy::setupBoard(Board& board) {
    // Example: Random board setup logic
}

void CustomStrategy::setupBoard(Board& board) {
    // Example: Custom board setup logic
}

Strategy& BuilderStrategy::createStrategy(StrategyType type) {
    switch (type) {
        case StrategyType::Standard:
            return *(new StandardStrategy());
        case StrategyType::Random:
            return *(new RandomStrategy());
        case StrategyType::Custom:
            return *(new CustomStrategy());
        default:
            return *(new StandardStrategy());
    }
}
