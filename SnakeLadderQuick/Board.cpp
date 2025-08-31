#include "Board.h"
#include <iostream>

Board::Board(int size) : size(size) {}

Board::~Board() {
    for (auto entity : listentity) {
        delete entity;
    }
    listentity.clear();
    mapentity.clear();
}

void Board::addEntity(BoardEntity& entity) {
    if (canAddEntity(entity)) {
        listentity.push_back(&entity);
        mapentity[entity.start] = &entity;
    }
}

bool Board::canAddEntity(BoardEntity& entity) {
    // Example: Prevent duplicate start positions
    return mapentity.find(entity.start) == mapentity.end();
}

void Board::display() const {
    std::cout << "Board size: " << size << std::endl;
    for (auto entity : listentity) {
        entity->display();
    }
}
