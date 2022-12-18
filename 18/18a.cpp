#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int const N = 50;

bool B[N][N][N];

int main() {
    ifstream fin("../18/18.txt");

    clock_t timer = clock();

    int res = 0;
    auto check = [&](int x, int y, int z) -> void {
        if (0 <= x && x < N && 0 <= y && y < N && 0 <= z && z < N && B[x][y][z]) res--;
        else res++;
    };
    while (!fin.eof()) {
        string line;
        getline(fin, line);
        int x = stoi(line);
        line = line.substr(line.find(',') + 1);
        int y = stoi(line);
        line = line.substr(line.find(',') + 1);
        int z = stoi(line);
        assert(0 <= x && x < N && 0 <= y && y < N && 0 <= z && z < N);
        check(x + 1, y, z);
        check(x - 1, y, z);
        check(x, y + 1, z);
        check(x, y - 1, z);
        check(x, y, z + 1);
        check(x, y, z - 1);
        B[x][y][z] = true;
    }

    cout << res << '\n';

    cout << fixed << setprecision(6) << double(clock() - timer) / CLOCKS_PER_SEC << '\n';
}