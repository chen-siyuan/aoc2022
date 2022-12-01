#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string line;
    ll mx = 0LL;
    ll curr = 0LL;
    while (getline(cin, line)) {
        if (line.empty()) {
            mx = max(mx, curr);
            curr = 0LL;
            continue;
        }
        curr += stoi(line);
    }
    mx = max(mx, curr);
    cout << mx << '\n';
}