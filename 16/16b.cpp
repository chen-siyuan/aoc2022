#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../16/16.txt");

    vector<string> lines;
    {
        string line;
        while (getline(fin, line))
            lines.push_back(line);
    }

    vector<string> names;
    vector<int> rates;
    for (auto const &line: lines) {
        names.push_back(line.substr(line.find(' ') + 1, 2));
        rates.push_back(stoi(line.substr(line.find('=') + 1)));
    }

    int n = int(names.size());
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i1, int i2) -> bool {
        return rates[i1] > rates[i2];
    });

    unordered_map<string, int> serialize;
    for (int i = 0; i < n; i++)
        serialize[names[indices[i]]] = i;

    int m = 0;
    while (rates[indices[m]] != 0)
        m++;

    struct Valve {
        int rate;
        vector<int> neighbors;
    };
    vector<Valve> valves(n);
    for (auto const &line: lines) {
        auto &valve = valves[serialize[line.substr(line.find(' ') + 1, 2)]];
        valve.rate = stoi(line.substr(line.find('=') + 1));
        auto i = line.find("valves ");
        if (i == string::npos)
            valve.neighbors.push_back(serialize[line.substr(int(line.size()) - 2, 2)]);
        else
            for (int j = i + 7; j < int(line.size()); j += 4)
                valve.neighbors.push_back(serialize[line.substr(j, 2)]);
    }

    vector dp(1U << m, vector(n, vector(n, vector(26, -1))));
    function<int(unsigned, int, int, int, int)> dfs = [&](unsigned mask, int pos1, int pos2, int time,
                                                          int delta) -> int {
        if (pos1 > pos2)
            swap(pos1, pos2);
        if (dp[mask][pos1][pos2][time] != -1)
            return dp[mask][pos1][pos2][time];
        if (time == 25)
            return dp[mask][pos1][pos2][time] = delta;
        if (mask + 1 == 1U << m)
            return dp[mask][pos1][pos2][time] = delta * (26 - time);
        bool flag1 = pos1 < m && (mask & 1U << pos1) == 0;
        bool flag2 = pos2 < m && (mask & 1U << pos2) == 0;
        if (flag1 && flag2) {
            if (pos1 == pos2)
                for (auto neighbor: valves[pos1].neighbors)
                    dp[mask][pos1][pos2][time] = max(dp[mask][pos1][pos2][time],
                                                     delta + dfs(mask ^ 1U << pos1, pos1, neighbor, time + 1,
                                                                 delta + valves[pos1].rate));
            else {
                dp[mask][pos1][pos2][time] = max(dp[mask][pos1][pos2][time],
                                                 delta + dfs(mask ^ 1U << pos1 ^ 1U << pos2, pos1, pos2, time + 1,
                                                             delta + valves[pos1].rate + valves[pos2].rate));
                for (auto neighbor: valves[pos2].neighbors)
                    dp[mask][pos1][pos2][time] = max(dp[mask][pos1][pos2][time],
                                                     delta + dfs(mask ^ 1U << pos1, pos1, neighbor, time + 1,
                                                                 delta + valves[pos1].rate));
                for (auto neighbor: valves[pos1].neighbors)
                    dp[mask][pos1][pos2][time] = max(dp[mask][pos1][pos2][time],
                                                     delta + dfs(mask ^ 1U << pos2, neighbor, pos2, time + 1,
                                                                 delta + valves[pos2].rate));
            }
        } else if (flag1) {
            for (auto neighbor: valves[pos2].neighbors)
                dp[mask][pos1][pos2][time] = max(dp[mask][pos1][pos2][time],
                                                 delta + dfs(mask ^ 1U << pos1, pos1, neighbor, time + 1,
                                                             delta + valves[pos1].rate));
        } else if (flag2) {
            for (auto neighbor: valves[pos1].neighbors)
                dp[mask][pos1][pos2][time] = max(dp[mask][pos1][pos2][time],
                                                 delta + dfs(mask ^ 1U << pos2, neighbor, pos2, time + 1,
                                                             delta + valves[pos2].rate));
        }
        for (auto neighbor1: valves[pos1].neighbors)
            for (auto neighbor2: valves[pos2].neighbors)
                dp[mask][pos1][pos2][time] = max(dp[mask][pos1][pos2][time],
                                                 delta + dfs(mask, neighbor1, neighbor2, time + 1, delta));
        return dp[mask][pos1][pos2][time];
    };

    cout << dfs(0U, serialize["AA"], serialize["AA"], 0, 0) << '\n';
}