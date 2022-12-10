#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../10/10.txt");

    int cycle = 0, sum = 0, x = 1;

    string line;
    while (getline(fin, line)) {
        cycle++;
        if (line[0] == 'n') {
            if (cycle % 40 == 20)
                sum += cycle * x;
        } else {
            line = line.substr(5);
            if (cycle % 40 == 20)
                sum += cycle * x;
            cycle++;
            if (cycle % 40 == 20)
                sum += cycle * x;
            x += stoi(line);
        }
    }
    cout << sum << '\n';
}