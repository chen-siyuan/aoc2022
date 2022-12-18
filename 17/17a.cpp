#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../17/17.txt");

    vector<pair<int, int> const> const ROCKS[5] = {
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
            {{1, 0}, {0, 1}, {1, 1}, {2, 1}, {1, 2}},
            {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
            {{0, 0}, {1, 0}, {0, 1}, {1, 1}}
    };
    auto next_rock = [&]() -> vector<pair<int, int> const> const & {
        static int i = 0;
        return ROCKS[i++ % 5];
    };

    string pattern;
    getline(fin, pattern);
    auto next_push = [&]() -> int {
        static int i = 0;
        return pattern[i++ % int(pattern.size())] == '<' ? -1 : 1;
    };

    int const N = 2022;
    vector<array<bool, 7>> chamber(N * 5);
    auto is_empty = [&](int x, int y) -> bool {
        return 0 <= x && x < 7 && 0 <= y && y < N * 5 && !chamber[y][x];
    };

    clock_t timer = clock();

    int height = 0;
    for (int i = 0; i < N; i++) {
        auto rock = next_rock();

        int x = 2, y = height + 3;
        while (true) {
            int push = next_push();
            bool flag = true;
            for (auto [dx, dy]: rock)
                if (!is_empty(x + dx + push, y + dy))
                    flag = false;
            if (flag)
                x += push;
            flag = true;
            for (auto [dx, dy]: rock)
                if (!is_empty(x + dx, y + dy - 1))
                    flag = false;
            if (flag) y--;
            else break;
        }

        for (auto [dx, dy]: rock)
            chamber[y + dy][x + dx] = true;

        while (true) {
            bool flag = true;
            for (int j = 0; j < 7; j++)
                if (!is_empty(j, height))
                    flag = false;
            if (flag)
                break;
            height++;
        }
    }

    cout << height << '\n';

    timer = clock() - timer;
    cout << fixed << setprecision(6) << double(timer) / CLOCKS_PER_SEC << '\n';
}