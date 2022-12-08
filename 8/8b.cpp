#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("../8/8.txt");
    vector<string> A;
    string line;
    while (getline(fin, line)) {
        A.push_back(line);
    }

    int n = A.size();
    int m = A[0].size();

    vector B(n, vector<int>(m));
    int mx = 0, tmp;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int res = 1;

            tmp = j + 1;
            while (tmp < m && A[i][tmp] < A[i][j])
                tmp++;
            if (tmp == m)
                tmp--;
            res *= (tmp - j);

            tmp = j - 1;
            while (tmp >= 0 && A[i][tmp] < A[i][j])
                tmp--;
            if (tmp == -1)
                tmp++;
            res *= (j - tmp);

            tmp = i + 1;
            while (tmp < n && A[tmp][j] < A[i][j])
                tmp++;
            if (tmp == n)
                tmp--;
            res *= (tmp - i);

            tmp = i - 1;
            while (tmp >= 0 && A[tmp][j] < A[i][j])
                tmp--;
            if (tmp == -1)
                tmp++;
            res *= (i - tmp);

            mx = max(mx, res);
        }
    }
    cout << mx << '\n';
}