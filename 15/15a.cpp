#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../15/15.txt");

    struct Data {
        ll sx, sy, bx, by;
    };
    vector<Data> data;
    string line;
    while (getline(fin, line)) {
        ll sx, sy, bx, by;
        line = line.substr(line.find('=') + 1);
        sx = stoi(line);
        line = line.substr(line.find('=') + 1);
        sy = stoi(line);
        line = line.substr(line.find('=') + 1);
        bx = stoi(line);
        line = line.substr(line.find('=') + 1);
        by = stoi(line);
        data.push_back({sx, sy, bx, by});
    }

    int cnt = 0;
    ll X = 6000000LL, y = 2000000LL;
    for (ll x = -X; x <= X; x++) {
        bool occupied = false;
        bool scanned = false;
        for (auto [sx, sy, bx, by]: data) {
            if (bx == x && by == y) {
                occupied = true;
                break;
            }
            if (abs(x - sx) + abs(y - sy) <= abs(bx - sx) + abs(by - sy)) {
                scanned = true;
                break;
            }
        }
        if (occupied)
            continue;
        if (scanned)
            cnt++;
    }
    cout << cnt << '\n';
}