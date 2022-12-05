#include <bits/stdc++.h>

using namespace std;

int main() {
    int const N = 9;
    deque<int> A[N];

    string line;
    for (int i = 0; i < 8; i++) {
        getline(cin, line);
        for (int j = 0; j < N; j++) {
            if (line[1 + j * 4] != ' ') {
                A[j].push_front(line[1 + j * 4] - 'A');
            }
        }
    }

    for (auto const &i: A) {
        cout << char('A' + i.back());
    }
    cout << '\n';

    while (getline(cin, line)) {
        int k, x, y;
        if (line.size() == 18) {
            k = line[5] - '0';
            x = line[12] - '1';
            y = line[17] - '1';
        } else if (line.size() == 19) {
            k = (line[5] - '0') * 10 + (line[6] - '0');
            x = line[13] - '1';
            y = line[18] - '1';
        } else {
            continue;
        }
        stack<int> S;
        for (int i = 0; i < k; i++) {
            S.push(A[x].back());
            A[x].pop_back();
        }
        for (int i = 0; i < k; i++) {
            A[y].push_back(S.top());
            S.pop();
        }
    }
    for (auto const &i: A) {
        cout << char('A' + i.back());
    }
    cout << '\n';
}