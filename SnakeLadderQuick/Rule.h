#pragma once

#include "Board.h"

// Abstract Rule class
class Rule {
protected:
    Rule() = default;
    Rule(const Rule&) = delete;
    Rule& operator=(const Rule&) = delete;
public:
    static Rule& getInstance();
    virtual bool isValidMove(int pos, int dvalue, Board& board) const = 0;
    virtual bool isPlayerWin(int pos, Board& board) const = 0;
    virtual int calculateNewPos(int currpos, int dvalue, Board& board) const = 0;
    virtual ~Rule() = default;
};

// StandardRule subclass
class StandardRule : public Rule {
public:
    static StandardRule& getInstance();
    bool isValidMove(int pos, int dvalue, Board& board) const override;
    bool isPlayerWin(int pos, Board& board) const override;
    int calculateNewPos(int currpos, int dvalue, Board& board) const override;
};
