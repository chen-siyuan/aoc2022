#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../10/10.txt");

    int cycle = 0, x = 1;

    vector<string> output(6, string(40, '.'));

    string line;
    while (getline(fin, line)) {
        if (abs(x - cycle % 40) <= 1)
            output[cycle / 40][cycle % 40] = '#';
        cycle++;
        if (line[0] != 'n') {
            line = line.substr(5);
            if (abs(x - cycle % 40) <= 1)
                output[cycle / 40][cycle % 40] = '#';
            cycle++;
            x += stoi(line);
        }
    }

    for (auto const &s: output)
        cout << s << '\n';
}