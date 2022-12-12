#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int const DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ifstream fin("../12/12.txt");

    int sx, sy, ex, ey;
    vector<string> M;

    string line;
    while (getline(fin, line))
        M.push_back(line);

    int n = M.size(), m = M[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 'S') {
                sx = i;
                sy = j;
                M[i][j] = 'a';
            }
            if (M[i][j] == 'E') {
                ex = i;
                ey = j;
                M[i][j] = 'z';
            }
        }

    queue<pair<pair<int, int>, int>> Q;
    Q.push({{sx, sy}, 0});

    vector<vector<bool>> V(n, vector<bool>(m));

    while (true) {
        auto [pos, dist] = Q.front();
        Q.pop();

        if (V[pos.first][pos.second])
            continue;
        V[pos.first][pos.second] = true;

        if (pos.first == ex && pos.second == ey) {
            cout << dist << '\n';
            return 0;
        }

        for (auto [dx, dy]: DIRS) {
            int nx = pos.first + dx, ny = pos.second + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && M[nx][ny] <= M[pos.first][pos.second] + 1) {
                Q.push({{nx, ny}, dist + 1});
            }
        }
    }
}