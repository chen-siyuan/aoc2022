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
        else for (int j = i + 7; j < int(line.size()); j += 4)
            valve.neighbors.push_back(serialize[line.substr(j, 2)]);
    }

    vector dp(1U << m, vector(n, vector(30, -1)));
    function<int(unsigned, int, int, int)> dfs = [&](unsigned mask, int pos, int time, int delta) -> int {
        if (dp[mask][pos][time] != -1)
            return dp[mask][pos][time];
        if (time == 29)
            return dp[mask][pos][time] = delta;
        if (pos < m && (mask & 1U << pos) == 0)
            dp[mask][pos][time] = delta + dfs(mask ^ 1U << pos, pos, time + 1, delta + valves[pos].rate);
        for (auto neighbor: valves[pos].neighbors)
            dp[mask][pos][time] = max(dp[mask][pos][time], delta + dfs(mask, neighbor, time + 1, delta));
        return dp[mask][pos][time];
    };
    cout << dfs(0U, serialize["AA"], 0, 0) << '\n';
}