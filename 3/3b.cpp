#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("../3/3.txt");
    int res = 0;
    string line0, line1, line2;
    while (getline(fin, line0)) {
        getline(fin, line1);
        getline(fin, line2);
        vector<bool> B0(52), B1(52), B2(52);
        for (auto c: line0)
            B0['a' <= c && c <= 'z' ? c - 'a' : c - 'A' + 26] = true;
        for (auto c: line1)
            B1['a' <= c && c <= 'z' ? c - 'a' : c - 'A' + 26] = true;
        for (auto c: line2)
            B2['a' <= c && c <= 'z' ? c - 'a' : c - 'A' + 26] = true;
        for (int i = 0; i < 52; i++)
            if (B0[i] && B1[i] && B2[i])
                res += i + 1;
    }
    cout << res << '\n';
}