#include "cube.hpp"

Rubik::Rubik(std::vector<std::vector<std::string>> &c) {
    colors = c;
}

void Rubik::LTurn(int x) {
    char ul = colors[x][0][0];
    char um = colors[x][0][1];
    char ue1;
    char ue2;
    char ue3;

    colors[x][0][0] = colors[x][0][2];
    colors[x][0][2] = colors[x][2][2];
    colors[x][2][2] = colors[x][2][0];
    colors[x][2][0] = ul;

    colors[x][0][1] = colors[x][1][2];
    colors[x][1][2] = colors[x][2][1];
    colors[x][2][1] = colors[x][1][0];
    colors[x][1][0] = um;

    if (x == 0) {
        ue1 = colors[1][2][0];
        ue2 = colors[1][2][1];
        ue3 = colors[1][2][2];
        for (int i = 0; i < 3; i++) {
            colors[1][2][i] = colors[2][2][i];
            colors[2][2][i] = colors[3][2][i];
            colors[3][2][i] = colors[4][2][i];
        }
        colors[4][2][0] = ue1;
        colors[4][2][1] = ue2;
        colors[4][2][2] = ue3;
    } else if (x == 1) {
        ue1 = colors[5][2][0];
        ue2 = colors[5][2][1];
        ue3 = colors[5][2][2];

        for (int i = 0; i < 3; i++)
            colors[5][2][i] = colors[2][i][0];

        for (int i = 0; i < 3; i++)
            colors[2][i][0] = colors[0][0][2 - i];

        for (int i = 0; i < 3; i++)
            colors[0][0][i] = colors[4][i][2];

        colors[4][2][2] = ue1;
        colors[4][1][2] = ue2;
        colors[4][0][2] = ue3;
    } else if (x == 2) {
        ue1 = colors[5][2][2];
        ue2 = colors[5][1][2];
        ue3 = colors[5][0][2];

        for (int i = 0; i < 3; i++)
            colors[5][i][2] = colors[3][2 - i][0];

        for (int i = 0; i < 3; i++)
            colors[3][i][0] = colors[0][2 - i][2];

        for (int i = 0; i < 3; i++)
            colors[0][i][2] = colors[1][i][2];

        colors[1][2][2] = ue1;
        colors[1][1][2] = ue2;
        colors[1][0][2] = ue3;
    } else if (x == 3) {
        ue1 = colors[5][0][2];
        ue2 = colors[5][0][1];
        ue3 = colors[5][0][0];

        for (int i = 0; i < 3; i++)
            colors[5][0][2 - i] = colors[4][i][0];

        for (int i = 0; i < 3; i++)
            colors[4][i][0] = colors[0][2][i];

        for (int i = 0; i < 3; i++)
            colors[0][2][i] = colors[2][2 - i][2];

        colors[2][2][2] = ue1;
        colors[2][1][2] = ue2;
        colors[2][0][2] = ue3;
    } else if (x == 4) {
        ue1 = colors[5][0][0];
        ue2 = colors[5][1][0];
        ue3 = colors[5][2][0];
        for (int i = 0; i < 3; i++)
            colors[5][i][0] = colors[1][i][0];

        for (int i = 0; i < 3; i++)
            colors[1][i][0] = colors[0][i][0];

        for (int i = 0; i < 3; i++)
            colors[0][i][0] = colors[3][2 - i][2];

        colors[3][2][2] = ue1;
        colors[3][1][2] = ue2;
        colors[3][0][2] = ue3;
    } else if (x == 5) {
        ue1 = colors[3][0][2];
        ue2 = colors[3][0][1];
        ue3 = colors[3][0][0];

        for (int i = 0; i < 3; i++) {
            colors[3][0][i] = colors[2][0][i];
            colors[2][0][i] = colors[1][0][i];
            colors[1][0][i] = colors[4][0][i];
        }

        colors[4][0][2] = ue1;
        colors[4][0][1] = ue2;
        colors[4][0][0] = ue3;
    } else {
        std::cout << "Error in function LTurn";
        return;
    }

    std::string now;
    if (x == 0) {
        now = "WL";
        state.push_back(now);
    } else if (x == 1) {
        now = "BL";
        state.push_back(now);
     
    } else if (x == 2) {
        now = "OL";
        state.push_back(now);
      
    } else if (x == 3) {
        now = "GL";
        state.push_back(now);
        
    } else if (x == 4) {
        now = "RL";
        state.push_back(now);
       
    } else if (x == 5) {
        now = "YL";
        state.push_back(now);
        
    }
    if (state.size() >= 4 && state[state.size() - 1] == state[state.size() - 2] &&
        state[state.size() - 3] == state[state.size() - 4] &&
        state[state.size() - 2] == state[state.size() - 3]) {
        state.pop_back();
        state.pop_back();
        state.pop_back();
        state.pop_back();
    }
}

void Rubik::RTurn(int x) {
    char ul = colors[x][0][0]; // upper left
    char um = colors[x][0][1]; // upper middle
    char ue1; // first upper edge
    char ue2; // second upper edge
    char ue3; // third upper edge

    colors[x][0][0] = colors[x][2][0];
    colors[x][2][0] = colors[x][2][2];
    colors[x][2][2] = colors[x][0][2];
    colors[x][0][2] = ul;

    colors[x][0][1] = colors[x][1][0];
    colors[x][1][0] = colors[x][2][1];
    colors[x][2][1] = colors[x][1][2];
    colors[x][1][2] = um;

    if (x == 0) {
        ue1 = colors[1][2][0];
        ue2 = colors[1][2][1];
        ue3 = colors[1][2][2];

        for (int i = 0; i < 3; i++) {
            colors[1][2][i] = colors[4][2][i];
            colors[4][2][i] = colors[3][2][i];
            colors[3][2][i] = colors[2][2][i];
        }

        colors[2][2][0] = ue1;
        colors[2][2][1] = ue2;
        colors[2][2][2] = ue3;
    } else if (x == 1) {
        ue1 = colors[5][2][0];
        ue2 = colors[5][2][1];
        ue3 = colors[5][2][2];

        for (int i = 0; i < 3; i++)
            colors[5][2][i] = colors[4][2 - i][2];

        for (int i = 0; i < 3; i++)
            colors[4][i][2] = colors[0][0][i];

        for (int i = 0; i < 3; i++)
            colors[0][0][i] = colors[2][2 - i][0];

        colors[2][0][0] = ue1;
        colors[2][1][0] = ue2;
        colors[2][2][0] = ue3;
    } else if (x == 2) {
        ue1 = colors[5][2][2];
        ue2 = colors[5][1][2];
        ue3 = colors[5][0][2];

        for (int i = 0; i < 3; i++)
            colors[5][i][2] = colors[1][i][2];

        for (int i = 0; i < 3; i++)
            colors[1][i][2] = colors[0][i][2];

        for (int i = 0; i < 3; i++)
            colors[0][i][2] = colors[3][2 - i][0];

        colors[3][0][0] = ue1;
        colors[3][1][0] = ue2;
        colors[3][2][0] = ue3;
    } else if (x == 3) {
        ue1 = colors[5][0][2];
        ue2 = colors[5][0][1];
        ue3 = colors[5][0][0];

        for (int i = 0; i < 3; i++)
            colors[5][0][2 - i] = colors[2][2 - i][2];

        for (int i = 0; i < 3; i++)
            colors[2][i][2] = colors[0][2][2 - i];

        for (int i = 0; i < 3; i++)
            colors[0][2][i] = colors[4][i][0];

        colors[4][0][0] = ue1;
        colors[4][1][0] = ue2;
        colors[4][2][0] = ue3;
    } else if (x == 4) {
        ue1 = colors[5][0][0];
        ue2 = colors[5][1][0];
        ue3 = colors[5][2][0];

        for (int i = 0; i < 3; i++)
            colors[5][i][0] = colors[3][2 - i][2];

        for (int i = 0; i < 3; i++)
            colors[3][i][2] = colors[0][2 - i][0];

        for (int i = 0; i < 3; i++)
            colors[0][i][0] = colors[1][i][0];

        colors[1][0][0] = ue1;
        colors[1][1][0] = ue2;
        colors[1][2][0] = ue3;
    } else if (x == 5) {
        ue1 = colors[3][0][2];
        ue2 = colors[3][0][1];
        ue3 = colors[3][0][0];

        for (int i = 0; i < 3; i++) {
            colors[3][0][i] = colors[4][0][i];
            colors[4][0][i] = colors[1][0][i];
            colors[1][0][i] = colors[2][0][i];
        }

        colors[2][0][2] = ue1;
        colors[2][0][1] = ue2;
        colors[2][0][0] = ue3;
    } else {
        std::cout << "Error in function RTurn";
        return;
    }

    std::string now;
    if (x == 0) {
        now = "WR";
        state.push_back(now);
        if (state.size() > 1 && state[size(state) - 2] == "WL") {
            state.pop_back();
            state.pop_back();
        }
    } else if (x == 1) {
        now = "BR";
        state.push_back(now);
        if (state.size() > 1 && state[size(state) - 2] == "BL") {
            state.pop_back();
            state.pop_back();
        }
    } else if (x == 2) {
        now = "OR";
        state.push_back(now);
        if (state.size() > 1 && state[size(state) - 2] == "OL") {
            state.pop_back();
            state.pop_back();
        }
    } else if (x == 3) {
        now = "GR";
        state.push_back(now);
        if (state.size() > 1 && state[size(state) - 2] == "GL") {
            state.pop_back();
            state.pop_back();
        }
    } else if (x == 4) {
        now = "RR";
        state.push_back(now);
        if (state.size() > 1 && state[size(state) - 2] == "RL") {
            state.pop_back();
            state.pop_back();
        }
    } else if (x == 5) {
        now = "YR";
        state.push_back(now);
        if (state.size() > 1 && state[size(state) - 2] == "YL") {
            state.pop_back();
            state.pop_back();
        }
    }
    if (state.size() >= 4 && state[state.size() - 1] == state[state.size() - 2] &&
        state[state.size() - 3] == state[state.size() - 4] &&
        state[state.size() - 2] == state[state.size() - 3]) {
        state.pop_back();
        state.pop_back();
        state.pop_back();
        state.pop_back();
    }
}

void Rubik::T180(int x) {
    RTurn(x);
    RTurn(x);
}

void Rubik::first() {
    int p = 0, count = 0;
    while (p != 4) {
        
        if ((colors[5][0][1] == 'W') && (colors[5][1][0] == 'W') && (colors[5][2][1] == 'W') &&
            (colors[5][1][2] == 'W')) {
            p = 4;
            break;
        } else if (colors[1][1][0] == 'W') {
            while (colors[5][1][0] == 'W')
                LTurn(5);
            LTurn(4);
        } else if (colors[1][1][2] == 'W') {
            while (colors[5][1][2] == 'W')
                LTurn(5);
            RTurn(2);
        } else if (colors[2][1][0] == 'W') {
            while (colors[5][2][1] == 'W')
                LTurn(5);
            LTurn(1);
        } else if (colors[2][1][2] == 'W') {
            while (colors[5][0][1] == 'W')
                LTurn(5);
            RTurn(3);
        } else if (colors[3][1][0] == 'W') {
            while (colors[5][1][2] == 'W')
                LTurn(5);
            LTurn(2);
        } else if (colors[3][1][2] == 'W') {
            while (colors[5][1][0] == 'W')
                LTurn(5);
            RTurn(4);
        } else if (colors[4][1][0] == 'W') {
            while (colors[5][0][1] == 'W')
                LTurn(5);
            LTurn(3);
        } else if (colors[4][1][2] == 'W') {
            while (colors[5][2][1] == 'W') {
                LTurn(5);
            }
            RTurn(1);
        } else if (colors[0][1][0] == 'W') {
            while (colors[5][1][0] == 'W')
                LTurn(5);
            T180(4);
        } else if (colors[0][0][1] == 'W') {
            while (colors[5][2][1] == 'W')
                LTurn(5);
            T180(1);
        } else if (colors[0][1][2] == 'W') {
            while (colors[5][1][2] == 'W')
                LTurn(5);
            T180(2);
        } else if (colors[0][2][1] == 'W') {
            while (colors[5][0][1] == 'W')
                LTurn(5);
            T180(3);
        } else {
            for (int j = 1; j <= 4; j++) {
                if ((colors[j][0][1] == 'W') || (colors[j][2][1] == 'W')) {
                    if (j == 1) {
                        while (colors[5][2][1] == 'W')
                            LTurn(5);
                    } else if (j == 2) {
                        while (colors[5][1][2] == 'W')
                            LTurn(5);
                    } else if (j == 3) {
                        while (colors[5][0][1] == 'W')
                            LTurn(5);
                    } else if (j == 4) {
                        while (colors[5][1][0] == 'W')
                            LTurn(5);
                    }
                    RTurn(j);
                    break;
                }
            }
        }
    }
    out();
}


void Rubik::x() {
    int p = 0;
    while (p != 4) {
        if (colors[1][0][1] == 'B' && colors[5][2][1] == 'W') {
            T180(1);
            p++;

        } else if (colors[1][0][1] == 'R' && colors[5][2][1] == 'W') {
            RTurn(5);
            T180(4);
            p++;

        } else if (colors[1][0][1] == 'O' && colors[5][2][1] == 'W') {
            LTurn(5);
            T180(2);
            p++;

        } else if (colors[1][0][1] == 'G' && colors[5][2][1] == 'W') {
            T180(5);
            T180(3);
            p++;

        } else if (colors[2][0][1] == 'O' && colors[5][1][2] == 'W') {
            T180(2);
            p++;

        } else if (colors[2][0][1] == 'B' && colors[5][1][2] == 'W') {
            RTurn(5);
            T180(1);
            p++;

        } else if (colors[2][0][1] == 'G' && colors[5][1][2] == 'W') {
            LTurn(5);
            T180(3);
            p++;

        } else if (colors[2][0][1] == 'R' && colors[5][1][2] == 'W') {
            T180(5);
            T180(4);
            p++;

        } else if (colors[3][0][1] == 'G' && colors[5][0][1] == 'W') {
            T180(3);
            p++;

        } else if (colors[3][0][1] == 'R' && colors[5][0][1] == 'W') {
            LTurn(5);
            T180(4);
            p++;

        } else if (colors[3][0][1] == 'B' && colors[5][0][1] == 'W') {
            T180(5);
            T180(1);
            p++;

        } else if (colors[3][0][1] == 'O' && colors[5][0][1] == 'W') {
            RTurn(5);
            T180(2);
            p++;

        } else if (colors[4][0][1] == 'R' && colors[5][1][0] == 'W') {
            T180(4);
            p++;

        } else if (colors[4][0][1] == 'O' && colors[5][1][0] == 'W') {
            T180(5);
            T180(2);
            p++;

        } else if (colors[4][0][1] == 'B' && colors[5][1][0] == 'W') {
            LTurn(5);
            T180(1);
            p++;

        } else if (colors[4][0][1] == 'G' && colors[5][1][0] == 'W') {
            RTurn(5);
            T180(3);
            p++;

        }
    }
    out();
}

void Rubik::firstLayer() {
    int f = 0;
    while (f != 4) {
        if ((colors[1][2][1] == 'B') && (colors[1][0][2] == 'W') && (colors[2][0][0] == 'O') &&
            (colors[2][2][1] == 'O') && (colors[5][2][2] == 'B')) {
            f = 0;
            LTurn(1);
            LTurn(5);
            RTurn(1);
        } else if ((colors[4][2][1] == 'R') && (colors[4][0][2] == 'W') && (colors[1][0][0] == 'B') &&
                   (colors[1][2][1] == 'B') && (colors[5][2][0] == 'R')) {
            f = 0;
            LTurn(4);
            LTurn(5);
            RTurn(4);
        } else if ((colors[2][2][1] == 'O') && (colors[2][0][2] == 'W') && (colors[3][0][0] == 'G') &&
                   (colors[3][2][1] == 'G') && (colors[5][0][2] == 'O')) {
            f = 0;
            LTurn(2);
            LTurn(5);
            RTurn(2);
        } else if ((colors[3][2][1] == 'G') && (colors[3][0][2] == 'W') && (colors[4][0][0] == 'R') &&
                   (colors[4][2][1] == 'R') && (colors[5][0][0] == 'G')) {
            f = 0;
            LTurn(3);
            LTurn(5);
            RTurn(3);
        } else if ((colors[1][2][1] == 'B') && (colors[1][0][2] == 'B') && (colors[2][0][0] == 'W') &&
                   (colors[2][2][1] == 'O') && (colors[5][2][2] == 'O')) {
            f = 0;
            RTurn(2);
            RTurn(5);
            LTurn(2);
        } else if ((colors[4][2][1] == 'R') && (colors[4][0][2] == 'R') && (colors[1][0][0] == 'W') &&
                   (colors[1][2][1] == 'B') && (colors[5][2][0] == 'B')) {
            f = 0;
            RTurn(1);
            RTurn(5);
            LTurn(1);
        } else if ((colors[2][2][1] == 'O') && (colors[2][0][2] == 'O') && (colors[3][0][0] == 'W') &&
                   (colors[3][2][1] == 'G') && (colors[5][0][2] == 'G')) {
            f = 0;
            RTurn(3);
            RTurn(5);
            LTurn(3);
        } else if ((colors[3][2][1] == 'G') && (colors[3][0][2] == 'G') && (colors[4][0][0] == 'W') &&
                   (colors[4][2][1] == 'R') && (colors[5][0][0] == 'R')) {
            f = 0;
            RTurn(4);
            RTurn(5);
            LTurn(4);
        } else if ((colors[1][2][1] == 'B') && (colors[1][0][2] == 'O') && (colors[2][0][0] == 'B') &&
                   (colors[2][2][1] == 'O') && (colors[5][2][2] == 'W')) {
            f = 0;
            RTurn(2);
            LTurn(5);
            LTurn(2);
            T180(5);
            RTurn(2);
            RTurn(5);
            LTurn(2);
        } else if ((colors[4][2][1] == 'R') && (colors[4][0][2] == 'B') && (colors[1][0][0] == 'R') &&
                   (colors[1][2][1] == 'B') && (colors[5][2][0] == 'W')) {
            f = 0;
            RTurn(1);
            LTurn(5);
            LTurn(1);
            T180(5);
            RTurn(1);
            RTurn(5);
            LTurn(1);
        } else if ((colors[2][2][1] == 'O') && (colors[2][0][2] == 'G') && (colors[3][0][0] == 'O') &&
                   (colors[3][2][1] == 'G') && (colors[5][0][2] == 'W')) {
            f = 0;
            RTurn(3);
            LTurn(5);
            LTurn(3);
            T180(5);
            RTurn(3);
            RTurn(5);
            LTurn(3);
        } else if ((colors[3][2][1] == 'G') && (colors[3][0][2] == 'R') && (colors[4][0][0] == 'G') &&
                   (colors[4][2][1] == 'R') && (colors[5][0][0] == 'W')) {
            f = 0;
            RTurn(4);
            LTurn(5);
            LTurn(4);
            T180(5);
            RTurn(4);
            RTurn(5);
            LTurn(4);
        } else if (((colors[1][2][1] == 'B') && (colors[2][2][1] == 'O')) &&
                   ((colors[1][2][2] == 'W') || (colors[2][2][0] == 'W'))) {
            f = 0;
            LTurn(1);
            LTurn(5);
            RTurn(1);
        } else if (((colors[4][2][1] == 'R') && (colors[1][2][1] == 'B')) &&
                   ((colors[4][2][2] == 'W') || (colors[1][2][0] == 'W'))) {
            f = 0;
            LTurn(4);
            LTurn(5);
            RTurn(4);
        } else if (((colors[2][2][1] == 'O') && (colors[3][2][1] == 'G')) &&
                   ((colors[2][2][2] == 'W') || (colors[3][2][0] == 'W'))) {
            f = 0;
            LTurn(2);
            LTurn(5);
            RTurn(2);
        } else if (((colors[3][2][1] == 'G') && (colors[4][2][1] == 'R')) &&
                   ((colors[3][2][2] == 'W') || (colors[4][2][0] == 'W'))) {
            f = 0;
            LTurn(3);
            LTurn(5);
            RTurn(3);
        } else if (((colors[4][2][1] == 'R') && (colors[0][0][0] == 'W') && (colors[1][2][1] == 'B')) &&
                   ((colors[4][2][2] != 'R') || (colors[1][2][0] != 'B'))) {
            f = 0;
            RTurn(1);
            LTurn(5);
            LTurn(1);
        } else if (((colors[1][2][1] == 'B') && (colors[2][2][1] == 'O') && (colors[0][0][2] == 'W')) &&
                   ((colors[1][2][2] != 'B') || (colors[2][2][0] != 'O'))) {
            f = 0;
            RTurn(2);
            LTurn(5);
            LTurn(2);
        } else if (((colors[2][2][1] == 'O') && (colors[3][2][1] == 'G') && (colors[0][2][2] == 'W')) &&
                   ((colors[2][2][2] != 'O') || (colors[3][2][0] != 'G'))) {
            f = 0;
            RTurn(3);
            LTurn(5);
            LTurn(3);
        } else if (((colors[3][2][1] == 'G') && (colors[4][2][1] == 'R') && (colors[0][2][0] == 'W')) &&
                   ((colors[3][2][2] != 'G') || (colors[4][2][0] != 'R'))) {
            f = 0;
            RTurn(4);
            LTurn(5);
            LTurn(4);
        } else {
            f++;
            RTurn(5);
        }
    }
    out();
}

void Rubik::secondLayer() {
    int f = 0, iter;
    while (f != 4) {
        iter = 0;
        for (int i = 1; i <= 4; i++) {
            if ((colors[i][0][1] == colors[i][1][1]) && (((i == 1) && (colors[5][2][1] == 'O')) ||
                                                         ((i == 2) && (colors[5][1][2] == 'G')) ||
                                                         ((i == 3) && (colors[5][0][1] == 'R')) ||
                                                         ((i == 4) && (colors[5][1][0] == 'B')))) {
                if (i != 4) {
                    f = 0;
                    RTurn(5);
                    RTurn(i + 1);
                    RTurn(5);
                    LTurn(i + 1);
                    LTurn(5);
                    LTurn(i);
                    LTurn(5);
                    RTurn(i);
                    RTurn(5);
                } else {
                    f = 0;
                    RTurn(5);
                    RTurn(1);
                    RTurn(5);
                    LTurn(1);
                    LTurn(5);
                    LTurn(i);
                    LTurn(5);
                    RTurn(i);
                    RTurn(5);
                }
                iter = 1;
                f = 0;
                break;
            }
        }
        if (iter == 0) {
            for (int i = 1; i <= 4; i++) {
                if ((colors[i][0][1] == colors[i][1][1]) && (((i == 1) && (colors[5][2][1] == 'R')) ||
                                                             ((i == 2) && (colors[5][1][2] == 'B')) ||
                                                             ((i == 3) && (colors[5][0][1] == 'O')) ||
                                                             ((i == 4) && (colors[5][1][0] == 'G')))) {
                    if (i != 1) {
                        LTurn(5);
                        LTurn(i - 1);
                        LTurn(5);
                        RTurn(i - 1);
                        RTurn(5);
                        RTurn(i);
                        RTurn(5);
                        LTurn(i);
                        LTurn(5);
                    } else {
                        LTurn(5);
                        LTurn(4);
                        LTurn(5);
                        RTurn(4);
                        RTurn(5);
                        RTurn(i);
                        RTurn(5);
                        LTurn(i);
                        LTurn(5);
                    }
                    iter = 1;
                    f = 0;
                    break;
                }
            }
        }
        if (iter == 0) {
            f++;
            LTurn(5);
        }
        if ((iter == 0) && (f == 4) &&
            ((colors[1][1][0] != 'B') || (colors[4][1][2] != 'R'))) {
            f = 0;
            RTurn(1);
            RTurn(5);
            LTurn(1);
            LTurn(5);
            LTurn(4);
            LTurn(5);
            RTurn(4);
            RTurn(5);
        } else if ((iter == 0) && (f == 4) &&
                   ((colors[2][1][0] != 'O') || (colors[1][1][2] != 'B'))) {
            f = 0;
            RTurn(2);
            RTurn(5);
            LTurn(2);
            LTurn(5);
            LTurn(1);
            LTurn(5);
            RTurn(1);
            RTurn(5);
        } else if ((iter == 0) && (f == 4) &&
                   ((colors[3][1][0] != 'G') || (colors[2][1][2] != 'O'))) {
            f = 0;
            RTurn(3);
            RTurn(5);
            LTurn(3);
            LTurn(5);
            LTurn(2);
            LTurn(5);
            RTurn(2);
            RTurn(5);
        } else if ((iter == 0) && (f == 4) &&
                   ((colors[4][1][0] != 'R') || (colors[3][1][2] != 'G'))) {
            f = 0;
            RTurn(4);
            RTurn(5);
            LTurn(4);
            LTurn(5);
            LTurn(3);
            LTurn(5);
            RTurn(3);
            RTurn(5);
        }

    }
    out();
}


void Rubik::thirdLayer() {
    if (colors[1][0][1] == 'Y' && colors[2][0][1] == 'Y' && colors[5][0][1] == 'Y' &&
        colors[5][1][0] == 'Y') {
        RTurn(1);
        RTurn(5);
        RTurn(2);
        LTurn(5);
        LTurn(2);
        LTurn(1);
    } else if (colors[1][0][1] == 'Y' && colors[4][0][1] == 'Y' && colors[5][0][1] == 'Y' &&
               colors[5][1][2] == 'Y') {
        RTurn(4);
        RTurn(5);
        RTurn(1);
        LTurn(5);
        LTurn(1);
        LTurn(4);
    } else if (colors[2][0][1] == 'Y' && colors[3][0][1] == 'Y' && colors[5][2][1] == 'Y' &&
               colors[5][1][0] == 'Y') {
        RTurn(2);
        RTurn(5);
        RTurn(3);
        LTurn(5);
        LTurn(3);
        LTurn(2);
    } else if (colors[3][0][1] == 'Y' && colors[4][0][1] == 'Y' && colors[5][1][2] == 'Y' &&
               colors[5][2][1] == 'Y') {
        RTurn(3);
        RTurn(5);
        RTurn(4);
        LTurn(5);
        LTurn(4);
        LTurn(3);
    } else if (colors[1][0][1] == 'Y' && colors[3][0][1] == 'Y' && colors[5][1][0] == 'Y' &&
               colors[5][1][2] == 'Y') {
        RTurn(1);
        RTurn(2);
        RTurn(5);
        LTurn(2);
        LTurn(5);
        LTurn(1);
    } else if (colors[2][0][1] == 'Y' && colors[4][0][1] == 'Y' && colors[5][0][1] == 'Y' &&
               colors[5][2][1] == 'Y') {
        RTurn(2);
        RTurn(3);
        RTurn(5);
        LTurn(3);
        LTurn(5);
        LTurn(2);
    } else if (colors[1][0][1] == 'Y' && colors[2][0][1] == 'Y' && colors[3][0][1] == 'Y' &&
               colors[4][1][0] == 'Y') {
        RTurn(1);
        RTurn(5);
        RTurn(2);
        LTurn(5);
        LTurn(2);
        LTurn(1);
        RTurn(2);
        RTurn(3);
        RTurn(5);
        LTurn(3);
        LTurn(5);
        LTurn(2);
    }
    if (colors[5][0][1] != 'Y' || colors[5][1][0] != 'Y' || colors[5][1][2] != 'Y' ||
        colors[5][2][1] != 'Y') {
        std::cout << "Error in function thirdLayer";
        return;
    }
    out();
}

void Rubik::checkYellowX() {
    if (colors[2][0][1] == 'B') {
        RTurn(5);
        LTurn(4);
        T180(5);
        RTurn(4);
        RTurn(5);
        LTurn(4);
        RTurn(5);
        RTurn(4);
    } else if (colors[4][0][1] == 'B') {
        RTurn(5);
        LTurn(3);
        T180(5);
        RTurn(3);
        RTurn(5);
        LTurn(3);
        RTurn(5);
        RTurn(3);
    } else if (colors[3][0][1] == 'B') {
        RTurn(5);
        LTurn(2);
        T180(5);
        RTurn(2);
        RTurn(5);
        LTurn(2);
        RTurn(5);
        RTurn(2);
        RTurn(5);
        LTurn(3);
        T180(5);
        RTurn(3);
        RTurn(5);
        LTurn(3);
        RTurn(5);
        RTurn(3);
        RTurn(5);
        LTurn(2);
        T180(5);
        RTurn(2);
        RTurn(5);
        LTurn(2);
        RTurn(5);
        RTurn(2);
    }
    if (colors[3][0][1] == 'O') {
        RTurn(5);
        LTurn(1);
        T180(5);
        RTurn(1);
        RTurn(5);
        LTurn(1);
        RTurn(5);
        RTurn(1);
    } else if (colors[4][0][1] == 'O') {
        RTurn(5);
        LTurn(3);
        T180(5);
        RTurn(3);
        RTurn(5);
        LTurn(3);
        RTurn(5);
        RTurn(3);
        RTurn(5);
        LTurn(4);
        T180(5);
        RTurn(4);
        RTurn(5);
        LTurn(4);
        RTurn(5);
        RTurn(4);
        RTurn(5);
        LTurn(3);
        T180(5);
        RTurn(3);
        RTurn(5);
        LTurn(3);
        RTurn(5);
        RTurn(3);
    }
    if (colors[4][0][1] == 'G') {
        RTurn(5);
        LTurn(2);
        T180(5);
        RTurn(2);
        RTurn(5);
        LTurn(2);
        RTurn(5);
        RTurn(2);
    }
    out();
}

void Rubik::checkCorners() {
    while (true) {
        if ((colors[1][0][0] == 'B' && colors[5][2][0] == 'Y' && colors[4][0][2] == 'O') ||
            (colors[1][0][0] == 'B' && colors[5][2][0] == 'O' && colors[4][0][2] == 'Y') ||
            (colors[1][0][0] == 'O' && colors[5][2][0] == 'Y' && colors[4][0][2] == 'B') ||
            (colors[1][0][0] == 'O' && colors[5][2][0] == 'B' && colors[4][0][2] == 'Y') ||
            (colors[1][0][0] == 'Y' && colors[5][2][0] == 'O' && colors[4][0][2] == 'B') ||
            (colors[1][0][0] == 'Y' && colors[5][2][0] == 'B' && colors[4][0][2] == 'O')) {
            LTurn(1);
            LTurn(4);
            RTurn(1);
            LTurn(2);
            LTurn(1);
            RTurn(4);
            RTurn(1);
            RTurn(2);
        } else if ((colors[3][0][0] == 'B' && colors[5][0][2] == 'Y' && colors[2][0][2] == 'O') ||
                   (colors[3][0][0] == 'B' && colors[5][0][2] == 'O' && colors[2][0][2] == 'Y') ||
                   (colors[3][0][0] == 'O' && colors[5][0][2] == 'Y' && colors[2][0][2] == 'B') ||
                   (colors[3][0][0] == 'O' && colors[5][0][2] == 'B' && colors[2][0][2] == 'Y') ||
                   (colors[3][0][0] == 'Y' && colors[5][0][2] == 'O' && colors[2][0][2] == 'B') ||
                   (colors[3][0][0] == 'Y' && colors[5][0][2] == 'B' && colors[2][0][2] == 'O')) {
            LTurn(2);
            LTurn(1);
            LTurn(4);
            RTurn(1);
            RTurn(2);
            LTurn(1);
            RTurn(4);
            RTurn(1);
        } else if ((colors[4][0][0] == 'B' && colors[3][0][2] == 'Y' && colors[5][0][0] == 'O') ||
                   (colors[4][0][0] == 'B' && colors[3][0][2] == 'O' && colors[5][0][0] == 'Y') ||
                   (colors[4][0][0] == 'O' && colors[3][0][2] == 'Y' && colors[5][0][0] == 'B') ||
                   (colors[4][0][0] == 'O' && colors[3][0][2] == 'B' && colors[5][0][0] == 'Y') ||
                   (colors[4][0][0] == 'Y' && colors[3][0][2] == 'O' && colors[5][0][0] == 'B') ||
                   (colors[4][0][0] == 'Y' && colors[3][0][2] == 'B' && colors[5][0][0] == 'O')) {
            LTurn(1);
            LTurn(4);
            LTurn(3);
            RTurn(4);
            RTurn(1);
            LTurn(4);
            RTurn(3);
            RTurn(4);
        } else break;
    }
    while (true) {
        if ((colors[1][0][0] == 'G' && colors[5][2][0] == 'Y' && colors[4][0][2] == 'O') ||
            (colors[1][0][0] == 'G' && colors[5][2][0] == 'O' && colors[4][0][2] == 'Y') ||
            (colors[1][0][0] == 'O' && colors[5][2][0] == 'Y' && colors[4][0][2] == 'G') ||
            (colors[1][0][0] == 'O' && colors[5][2][0] == 'G' && colors[4][0][2] == 'Y') ||
            (colors[1][0][0] == 'Y' && colors[5][2][0] == 'O' && colors[4][0][2] == 'G') ||
            (colors[1][0][0] == 'Y' && colors[5][2][0] == 'G' && colors[4][0][2] == 'O')) {
            LTurn(3);
            LTurn(2);
            RTurn(3);
            LTurn(4);
            LTurn(3);
            RTurn(2);
            RTurn(3);
            RTurn(4);
        } else if ((colors[4][0][0] == 'G' && colors[3][0][2] == 'Y' && colors[5][0][0] == 'O') ||
                   (colors[4][0][0] == 'G' && colors[3][0][2] == 'O' && colors[5][0][0] == 'Y') ||
                   (colors[4][0][0] == 'O' && colors[3][0][2] == 'Y' && colors[5][0][0] == 'G') ||
                   (colors[4][0][0] == 'O' && colors[3][0][2] == 'G' && colors[5][0][0] == 'Y') ||
                   (colors[4][0][0] == 'Y' && colors[3][0][2] == 'O' && colors[5][0][0] == 'G') ||
                   (colors[4][0][0] == 'Y' && colors[3][0][2] == 'G' && colors[5][0][0] == 'O')) {
            LTurn(4);
            LTurn(3);
            LTurn(2);
            RTurn(3);
            RTurn(4);
            LTurn(3);
            RTurn(2);
            RTurn(3);
        } else break;
    }
    out();
}


void Rubik::turnCorners() {
    while (true) {
        if (colors[2][0][0] == 'Y') {
            LTurn(1);
            RTurn(2);
            RTurn(1);
            LTurn(2);
            LTurn(1);
            RTurn(2);
            RTurn(1);
            LTurn(2);
        } else if (colors[1][0][2] == 'Y') {
            RTurn(2);
            LTurn(1);
            LTurn(2);
            RTurn(1);
            RTurn(2);
            LTurn(1);
            LTurn(2);
            RTurn(1);
        }

        if (colors[5][2][2] == 'Y' && colors[1][0][2] == 'B' && colors[2][0][0] == 'O' &&
            colors[5][0][2] == 'Y' && colors[2][0][2] == 'O' && colors[3][0][0] == 'G' &&
            colors[5][0][0] == 'Y' && colors[3][0][2] == 'G' && colors[4][0][0] == 'R' &&
            colors[5][2][0] == 'Y' && colors[4][0][2] == 'R' && colors[1][0][0] == 'B') {
            break;
        }
        RTurn(5);
    }
    out();
}

void Rubik::out() {
    for (auto &i : state)
        std::cout << i << ' ';
    std::cout << '\n';
    state.clear();
}

void Rubik::currentState() {
    for (auto &k : colors) {
        for (auto &i : k) {
            for (auto &j : i)
                std::cout << j << ' ';
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}
