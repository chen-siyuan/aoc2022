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
    ifstream fin("../6/6.txt");
    string line;
    fin >> line;
    int n = line.size();
    unordered_map<char, int, CustomHash> M;
    M[line[0]]++;
    M[line[1]]++;
    M[line[2]]++;
    for (int i = 3; i < n; i++) {
        M[line[i]]++;
        if (M.size() == 4) {
            cout << i + 1 << '\n';
            return 0;
        }
        M[line[i - 3]]--;
        if (M[line[i - 3]] == 0) {
            M.erase(M.find(line[i - 3]));
        }
    }
}