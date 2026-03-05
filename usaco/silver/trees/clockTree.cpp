#include <bits/stdc++.h>

using namespace std;

void dfs(set<int>&vis, set<int>&bSet, set<int>&rSet, int color, map<int, vector<int>>&g, int curr) {
    vis.insert(curr);
    if (color == 0) {
        bSet.insert(curr);
    } else {
        rSet.insert(curr);
    }
    for (int node : g[curr]) {
        if (vis.count(node)) continue;
        dfs(vis, bSet, rSet, color == 0 ? 1 : 0, g, node);
    }
}
int main() {
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");
    int n;
    fin >> n;
    vector<int> valAtNode(n+1,0);
    map<int, vector<int>>g;
    set<int>vis;
    for (int x=1;x<=n;x++) fin >> valAtNode[x];
    for (int x=0;x<n-1;x++) {
        int s,e;
        fin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    set<int> bSet;
    set<int> rSet;
    int bSum = 0;
    int rSum = 0;
    dfs(vis, bSet, rSet, 0, g,1);
    for (int node : bSet) {
        bSum += valAtNode[node];
    }
    for (int node : rSet) {
        rSum += valAtNode[node];
    }
    if ((bSum%12) == (rSum%12)) {
        fout << n;
    }
    else if (bSum%12 == (1+rSum)%12 || rSum%12 == (bSum+1)%12) {
        fout << (bSum%12 == (rSum+1)%12 ? bSet.size() : rSet.size());
    } else {
        fout << 0;
    }
}