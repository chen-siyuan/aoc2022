#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("../3/3.txt");
    int res = 0;
    string line;
    while (getline(fin, line)) {
        int n = line.size();
        assert(n % 2 == 0);
        bool flag = false;
        for (int i = 0; i < n / 2; i++) {
            for (int j = n / 2; j < n; j++) {
                if (!flag && line[i] == line[j]) {
                    res += (('a' <= line[i] && line[i] <= 'z') ? line[i] - 'a' + 1 : line[i] - 'A' + 27);
                    flag = true;
                }
            }
        }
        assert(true);
    }
    cout << res << '\n';
}