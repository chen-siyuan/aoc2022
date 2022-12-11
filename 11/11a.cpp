#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("../11/11.txt");

    struct Monkey {
        deque<int> items;
        function<int(int)> operation;
        function<int(int)> test;
    };

    int n = 8, m = 20;

    vector<Monkey> monkeys(n);
    monkeys[0].items = {{73, 77}};
    monkeys[0].operation = [&](int x) -> int { return x * 5; };
    monkeys[0].test = [&](int x) -> int { return x % 11 == 0 ? 6 : 5; };
    monkeys[1].items = {57, 88, 80};
    monkeys[1].operation = [&](int x) -> int { return x + 5; };
    monkeys[1].test = [&](int x) -> int { return x % 19 == 0 ? 6 : 0; };
    monkeys[2].items = {61, 81, 84, 69, 77, 88};
    monkeys[2].operation = [&](int x) -> int { return x * 19; };
    monkeys[2].test = [&](int x) -> int { return x % 5 == 0 ? 3 : 1; };
    monkeys[3].items = {78, 89, 71, 60, 81, 84, 87, 75};
    monkeys[3].operation = [&](int x) -> int { return x + 7; };
    monkeys[3].test = [&](int x) -> int { return x % 3 == 0 ? 1 : 0; };
    monkeys[4].items = {60, 76, 90, 63, 86, 87, 89};
    monkeys[4].operation = [&](int x) -> int { return x + 2; };
    monkeys[4].test = [&](int x) -> int { return x % 13 == 0 ? 2 : 7; };
    monkeys[5].items = {88};
    monkeys[5].operation = [&](int x) -> int { return x + 1; };
    monkeys[5].test = [&](int x) -> int { return x % 17 == 0 ? 4 : 7; };
    monkeys[6].items = {84, 98, 78, 85};
    monkeys[6].operation = [&](int x) -> int { return x * x; };
    monkeys[6].test = [&](int x) -> int { return x % 7 == 0 ? 5 : 4; };
    monkeys[7].items = {98, 89, 78, 73, 71};
    monkeys[7].operation = [&](int x) -> int { return x + 4; };
    monkeys[7].test = [&](int x) -> int { return x % 2 == 0 ? 3 : 2; };

    vector<int> counts(n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            while (!monkeys[j].items.empty()) {
                int item = monkeys[j].items.front();
                monkeys[j].items.pop_front();
                item = monkeys[j].operation(item);
                item /= 3;
                monkeys[monkeys[j].test(item)].items.push_back(item);
                counts[j]++;
            }
        }
    }

    sort(counts.begin(), counts.end(), greater<>());
    cout << counts[0] * counts[1] << '\n';
}