#include <bits/stdc++.h>
using namespace std;

// incorrectly assumed that indegree 1 was a sufficient condition.
// bridge finding: breaking 1 edge separates 1 CC into 2.
// lookup how to do this faster i.e Tarjans.
void dfs(set<int>&seen, int curr, vector<vector<bool>>& graph, int p) {
    for (int x=0;x<p;x++) {
        if (graph[curr][x] == true && !seen.count(x)) {
            seen.insert(x);
            dfs(seen, x, graph, p);
        }
    }
}
int main() {
    while (true) {
        int p,c;
        cin >> p >> c;
        if (p==0 && c==0) return 0;
        vector<vector<bool>> g(p,vector<bool>(p,false));
        vector<pair<int, int>> pairs;
        for (int x=0;x<c;x++) {
            int a,b;
            cin >> a >> b;
            g[a][b] = true;
            g[b][a] = true;
            pairs.push_back({a,b});
        }
        bool check = true;
        for (pair<int, int> px: pairs) {
            g[px.first][px.second] = false;
            g[px.second][px.first] = false;
            set<int> cset;
            dfs(cset, 0, g, p);
            if ((int)cset.size() != p) {
                cout << "Yes" << endl;
                check = false;
                break;
            }
            g[px.first][px.second] = true;
            g[px.second][px.first] = true;
        }
        if (check) cout << "No" << endl;
    }
}