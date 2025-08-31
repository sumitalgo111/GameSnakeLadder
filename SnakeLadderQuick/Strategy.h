#pragma once

class Board;

// Enum for strategy types
enum class StrategyType {
    Standard,
    Random,
    Custom
};

// Abstract Strategy class
class Strategy {
public:
    virtual void setupBoard(Board& board) = 0;
    virtual ~Strategy() = default;
};

class StandardStrategy : public Strategy {
public:
    void setupBoard(Board& board) override;
};

class RandomStrategy : public Strategy {
public:
    void setupBoard(Board& board) override;
};

class CustomStrategy : public Strategy {
public:
    void setupBoard(Board& board) override;
};

// BuilderStrategy class
class BuilderStrategy {
public:
    static Strategy& createStrategy(StrategyType type);
};
