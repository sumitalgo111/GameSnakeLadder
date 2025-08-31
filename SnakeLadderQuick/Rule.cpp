#include "Rule.h"
#include "Board.h" // Add this include to resolve incomplete type error
#include <memory>

StandardRule& StandardRule::getInstance() {
    static StandardRule instance;
    return instance;
}

bool StandardRule::isValidMove(int pos, int dvalue, Board& board) const {
    return (pos + dvalue <= board.getSize());
}

bool StandardRule::isPlayerWin(int pos, Board& board) const {
    return (pos == board.getSize());
}

int StandardRule::calculateNewPos(int currpos, int dvalue, Board& board) const {
    // Example logic: just add dice value
	int newpos = currpos + dvalue;

	auto itr = board.getEntityMap().find(newpos);
    if(itr != board.getEntityMap().end()) {
        // If there's a snake or ladder at the new position, move to its end
		itr->second->display(); // Display the entity encountered
        newpos = itr->second->end;
	}

    return newpos;
}
