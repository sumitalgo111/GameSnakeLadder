#pragma once
#include <iostream>

// Abstract class representing a board entity
class BoardEntity {
public:
    int start;
    int end;
public:
    BoardEntity(int start, int end) : start(start), end(end) {}
    virtual void display() const = 0; // Pure virtual function
    virtual ~BoardEntity() = default;
};

// Snake class derived from BoardEntity
class Snake : public BoardEntity {
public:
    Snake(int start, int end) : BoardEntity(start, end) {}
    void display() const override {
        std::cout << "Snake: from " << start << " to " << end << std::endl;
    }
};

// Ladder class derived from BoardEntity
class Ladder : public BoardEntity {
public:
    Ladder(int start, int end) : BoardEntity(start, end) {}
    void display() const override {
        std::cout << "Ladder: from " << start << " to " << end << std::endl;
    }
};
