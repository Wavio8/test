#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <cstring>
#include <vector>

class Rubik {
private:
    std::vector<std::vector<std::string>> colors;
    std::vector<std::string> state;
public:
    explicit Rubik(std::vector<std::vector<std::string>> &c);

    void LTurn(int x);

    void RTurn(int x);

    void T180(int x);

    void first();

    void x(); //x like a cross

    void firstLayer();

    void secondLayer();

    void thirdLayer();

    void checkYellowX();

    void checkCorners();

    void turnCorners();

    void currentState();

    void out();
};

#endif