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

    int res = 0;
    for (auto const &[s, n]: G) {
        int k = dfs(s);
        if (k <= 100000) {
            res += k;
        }
    }
    cout << res << '\n';
}