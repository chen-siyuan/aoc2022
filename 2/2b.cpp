#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("../2/2.txt");
    int payout[3][3] = {
            {3, 4, 8},
            {1, 5, 9},
            {2, 6, 7},
    };
    int res = 0;
    string line;
    while (getline(fin, line)) {
        int op = line[0] - 'A';
        int us = line[2] - 'X';
        res += payout[op][us];
    }
    cout << res << '\n';
}