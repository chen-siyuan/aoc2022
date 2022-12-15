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

    ll X = 4000000LL, Y = 4000000LL;

    for (ll x = 0; x <= X; x++) {
        vector<pair<ll, ll>> P = {{0LL, Y}};
        for (auto [sx, sy, bx, by]: data) {
            ll val = abs(bx - sx) + abs(by - sy) - abs(x - sx) + 1;
            ll upper = sy - val, lower = sy + val;
            if (upper >= 4000000LL)
                continue;
            if (lower <= 0LL)
                continue;
            vector<pair<ll, ll>> N;
            for (auto [l, r]: P) {
                if (r <= upper || l >= lower) {
                    N.emplace_back(l, r);
                    continue;
                }
                if (l <= upper)
                    N.emplace_back(l, upper);
                if (r >= lower)
                    N.emplace_back(lower, r);
            }
            P = N;
        }
        if (!P.empty()) {
            assert(P.size() == 1);
            assert(P[0].first == P[0].second);
            cout << x * 4000000LL + P[0].first << '\n';
        }
    }
}