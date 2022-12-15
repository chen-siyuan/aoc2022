#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../14/14.txt");

    int const DIMENSION = 1000;
    vector B(DIMENSION, vector<bool>(DIMENSION));

    string line;
    while (getline(fin, line)) {
        int px = stoi(line);
        line = line.substr(line.find(',') + 1);
        int py = stoi(line);
        while (true) {
            string::size_type pos = line.find(" -> ");
            if (pos == string::npos)
                break;
            line = line.substr(pos + 4);
            int cx = stoi(line);
            line = line.substr(line.find(',') + 1);
            int cy = stoi(line);
            for (int i = min(px, cx); i <= max(px, cx); i++)
                for (int j = min(py, cy); j <= max(py, cy); j++) {
                    assert(0 <= i && i < DIMENSION);
                    assert(0 <= j && j < DIMENSION);
                    B[i][j] = true;
                }
            px = cx;
            py = cy;
        }
    }

    int my = 0;
    for (int i = 0; i < DIMENSION; i++)
        for (int j = 0; j < DIMENSION; j++)
            if (B[i][j])
                my = max(my, j);
    for (int i = 0; i < DIMENSION; i++)
        B[i][my + 2] = true;

    int cnt = 0;
    while (true) {
        int x = 500;
        int y = 0;
        if (B[x][y])
            break;
        while (true) {
            if (!B[x][y + 1]) {
                y++;
                continue;
            }
            if (!B[x - 1][y + 1]) {
                x--;
                y++;
                continue;
            }
            if (!B[x + 1][y + 1]) {
                x++;
                y++;
                continue;
            }
            B[x][y] = true;
            cnt++;
            break;
        }
    }
    cout << cnt << '\n';
}