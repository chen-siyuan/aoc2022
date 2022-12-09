#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int const DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ifstream fin("../9/9.txt");

    int xh = 0, yh = 0, xt = 0, yt = 0;

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
            xh += DIRS[dir][0];
            yh += DIRS[dir][1];

            if (!(abs(xh - xt) <= 1 && abs(yh - yt) <= 1)) {
                if (xh == xt && abs(yh - yt) == 2)
                    yt = (yh + yt) / 2;
                else if (yh == yt && abs(xh - xt) == 2)
                    xt = (xh + xt) / 2;
                else {
                    if (xh > xt) xt += 1;
                    else xt -= 1;
                    if (yh > yt) yt += 1;
                    else yt -= 1;
                }
            }
            S.emplace(xt, yt);
        }
    }

    cout << S.size() << '\n';
}