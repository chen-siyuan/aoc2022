#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../17/17.txt");

    string line;
    while (getline(fin, line)) {
    }

    clock_t timer = clock();
    timer = clock() - timer;
    cout << fixed << setprecision(6) << double(timer) / CLOCKS_PER_SEC << '\n';
}