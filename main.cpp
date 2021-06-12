#include "cube.hpp"
#include <vector>

int main() {
    std::vector<std::vector<std::string>> config {{"GWB", "OWG", "YWR"}, {"GWB", "YBB", "YGW"}, {"ORR", "OOY", "RYW"},
                                                  {"YGW", "BGG", "GBB"}, {"OBW", "ORR", "RYO"}, {"BRG", "RYW", "OOY"}};

    Rubik c(config);

    c.first();
    c.currentState();

    c.x();
    c.currentState();

    c.firstLayer();
    c.currentState();

    c.secondLayer();
    c.currentState();

    c.thirdLayer();
    c.currentState();

    c.checkYellowX();
    c.currentState();

    c.checkCorners();
    c.currentState();

    c.turnCorners();
    c.currentState();

    return 0;
}