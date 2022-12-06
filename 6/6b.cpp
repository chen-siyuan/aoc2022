#include <bits/stdc++.h>

using namespace std;

struct CustomHash {
    using ull = unsigned long long;

    size_t operator()(ull x) const {
        static ull const FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x = x + FIXED_RANDOM + 0x9E3779B97F4A7C15ULL;
        x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9ULL;
        x = (x ^ (x >> 27)) * 0x94D049BB133111EBULL;
        return x ^ (x >> 31);
    }
};

int main() {
    string line;
    cin >> line;
    int n = line.size();
    unordered_map<char, int, CustomHash> M;
    for (int i = 0; i < 13; i++) {
        M[line[i]]++;
    }
    for (int i = 13; i < n; i++) {
        M[line[i]]++;
        if (M.size() == 14) {
            cout << i + 1 << '\n';
            return 0;
        }
        M[line[i - 13]]--;
        if (M[line[i - 13]] == 0) {
            M.erase(M.find(line[i - 13]));
        }
    }
}