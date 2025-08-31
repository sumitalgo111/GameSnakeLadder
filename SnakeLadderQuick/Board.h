#pragma once
#include <vector>
#include <map>
#include <memory>
#include "BoardEntity.h"

class Board {
private:
    int size;
    std::vector<BoardEntity*> listentity;
    std::map<int, BoardEntity*> mapentity;

    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
public:
    Board(int size); // Private constructor for singleton
    ~Board(); // Destructor declaration
    static Board& getInstance(int size = 100) {
        static Board instance(size);
        return instance;
    }

    void addEntity(BoardEntity& entity);
    bool canAddEntity(BoardEntity& entity);
    void display() const;
    int getSize() const { return size; }
    const std::vector<BoardEntity*>& getEntities() const { return listentity; }
    const std::map<int, BoardEntity*>& getEntityMap() const { return mapentity; }
};
