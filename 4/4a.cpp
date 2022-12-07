#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("../4/4.txt");
    int cnt = 0;
    string line;
    while (getline(fin, line)) {
        int l1, r1, l2, r2;
        int tmp;

        tmp = line.find('-');
        l1 = stoi(line.substr(0, tmp));
        line = line.substr(tmp + 1);

        tmp = line.find(',');
        r1 = stoi(line.substr(0, tmp));
        line = line.substr(tmp + 1);

        tmp = line.find('-');
        l2 = stoi(line.substr(0, tmp));
        line = line.substr(tmp + 1);

        r2 = stoi(line);

        if ((l1 <= l2 && r1 >= r2) || (l1 >= l2 && r1 <= r2)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}