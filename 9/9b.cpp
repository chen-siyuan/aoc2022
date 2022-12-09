#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int const DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ifstream fin("../9/9.txt");

    struct Pos {
        int x, y;
    };
    vector<Pos> P(10);
    set<pair<int, int>> S;

    string line;
    while (getline(fin, line)) {
        int dir;
        switch (line[0]) {
            case 'R':
                dir = 0;
                break;
            case 'U':
                dir = 1;
                break;
            case 'L':
                dir = 2;
                break;
            case 'D':
                dir = 3;
                break;
        }
        line = line.substr(2);
        int cnt = stoi(line);
        for (int i = 0; i < cnt; i++) {
            P[0].x += DIRS[dir][0];
            P[0].y += DIRS[dir][1];

            for (int j = 1; j < 10; j++) {
                if (!(abs(P[j - 1].x - P[j].x) <= 1 && abs(P[j - 1].y - P[j].y) <= 1)) {
                    if (P[j - 1].x == P[j].x && abs(P[j - 1].y - P[j].y) == 2)
                        P[j].y = (P[j - 1].y + P[j].y) / 2;
                    else if (P[j - 1].y == P[j].y && abs(P[j - 1].x - P[j].x) == 2)
                        P[j].x = (P[j - 1].x + P[j].x) / 2;
                    else {
                        if (P[j - 1].x > P[j].x) P[j].x += 1;
                        else P[j].x -= 1;
                        if (P[j - 1].y > P[j].y) P[j].y += 1;
                        else P[j].y -= 1;
                    }
                }
            }

            S.emplace(P[9].x, P[9].y);
        }
    }

    cout << S.size() << '\n';
}