#pragma once
#include <random>
#include <memory>

class Dice {
private:
    int face;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;

    Dice(const Dice&) = delete;
    Dice& operator=(const Dice&) = delete;
public:
    Dice(int face) : face(face), rng(std::random_device{}()), dist(1, face) {}
    static Dice& getInstance(int face = 6) {
        static Dice instance(face);
        return instance;
    }
    int roll() {
		int result = dist(rng);
		std::cout << "Dice rolled: " << result << std::endl;
        return result;
    }
    int getFace() const { return face; }
    void setFace(int newFace) {
        face = newFace;
        dist = std::uniform_int_distribution<int>(1, newFace);
    }
};
