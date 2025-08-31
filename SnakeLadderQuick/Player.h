#pragma once
#include <string>

class Player {
private:
    int id;
    std::string name;
    int pos;
    int score;
public:
    Player(int id, const std::string& name, int pos = 0, int score = 0)
        : id(id), name(name), pos(pos), score(score) {}

    // Getters
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    int getPos() const { return pos; }
    int getScore() const { return score; }

    // Setters
    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setPos(int newPos) { 
		std::cout << "Player " << name << " moved from " << pos << "to position " << newPos << std::endl;
        pos = newPos;
    }
    void setScore(int newScore) { score = newScore; }
};
