#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string line;
    multiset<ll> M;
    ll curr = 0LL;
    while (getline(cin, line)) {
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