#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ctr = 0;
void dfs(int w, int curr, vector<bool>& vis, vector<vector<pair<int,int>>>& g, vector<set<int>>& ccMap) {
    ccMap[ctr].insert(curr);
    for (int x=0;x<g[curr].size();x++) {
        pair<int,int> p = g[curr][x];
        if (p.second >= w && !vis[p.first]) {
            vis[p.first] = true;
            dfs(w, p.first, vis, g, ccMap);
        }
    }
}
int main() {
    int n,m;
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    map<int, int> idxMap;
    fin >> n >> m;
    for (int x=1;x<=n;x++) {
        int node;
        fin >> node;
        idxMap[node] = x;
    }
    vector<vector<pair<int,int>>> g(n+1);
    int max_width = 0;
    for (int x=0;x<m;x++) {
        int a,b,w;
        fin >> a >> b >> w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
        max_width = max(max_width, w);
    }
    bool sorted = true;
    for (int x = 1; x <= n; x++) {
        if (idxMap[x] != x) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        fout << -1 << endl;
        return 0;
    }
    int l = 1;
    int r = max_width + 1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        bool valid = true;
        vector<bool> vis(n+1, false);
        vector<set<int>> ccMap(n+1);
        ctr = 0;
        for (int node=1;node<=n;node++) {
            if (!vis[node]) {
                vis[node] = true;
                dfs(mid, node, vis, g, ccMap);
                ctr += 1;
            }
        }
        for (int x=0;x<ccMap.size();x++) {
            set<int> valueSet = ccMap[x];
            for (const auto& elem : valueSet) {
                if (!valueSet.count(idxMap[elem])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    fout << ans << endl;
}