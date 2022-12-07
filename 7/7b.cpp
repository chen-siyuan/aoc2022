#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    vector<string> children;
};

int main() {
    ifstream fin("../7/7.txt");
    unordered_map<string, Node> G;
    stack<string> S;
    string curr = "";

    string line;
    while (getline(fin, line)) {
        if (line[0] == '$') {
            if (line[2] == 'c') {
                line = line.substr(5);
                if (line == "..") {
                    curr = S.top();
                    S.pop();
                } else {
                    S.push(curr);
                    curr += " ";
                    curr += line;
                }
            }
        } else if (line[0] == 'd') G[curr].children.push_back(curr + " " + line.substr(4));
        else G[curr].data += stoi(line);
    }

    unordered_map<string, int> M;
    function<int(string const &)> dfs = [&](string const &s) -> int {
        auto it = M.find(s);
        if (it != M.end()) {
            return it->second;
        }
        Node const &n = G[s];
        int k = n.data;
        for (auto const &child: n.children)
            k += dfs(child);
        M[s] = k;
        return k;
    };

    int tot = dfs(" /") - 40000000;
    assert(tot > 0);
    int record = INT_MAX;
    for (auto const &[k, v]: M)
        if (v >= tot)
            record = min(record, v);
    cout << record << '\n';
}