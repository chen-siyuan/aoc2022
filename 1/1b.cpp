#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../1/1.txt");
    string line;
    multiset<ll> M;
    ll curr = 0LL;
    while (getline(fin, line)) {
        if (line.empty()) {
            M.insert(curr);
            curr = 0LL;
            continue;
        }
        curr += stoi(line);
    }
    M.insert(curr);
    cout << *M.rbegin() + *next(M.rbegin()) + *next(next(M.rbegin())) << '\n';
}