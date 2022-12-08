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

    int cnt = 0;
    vector B(n, vector<int>(m));
    int record;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            record = -1;
            for (int k = 0; k < i; k++)
                record = max(record, A[k][j] - '0');
            if (record < A[i][j] - '0')
                B[i][j] = true;

            record = -1;
            for (int k = i + 1; k < n; k++)
                record = max(record, A[k][j] - '0');
            if (record < A[i][j] - '0')
                B[i][j] = true;

            record = -1;
            for (int k = 0; k < j; k++)
                record = max(record, A[i][k] - '0');
            if (record < A[i][j] - '0')
                B[i][j] = true;

            record = -1;
            for (int k = j + 1; k < m; k++)
                record = max(record, A[i][k] - '0');
            if (record < A[i][j] - '0')
                B[i][j] = true;

            if (B[i][j])
                cnt++;
        }
    }
    cout << cnt << '\n';
}