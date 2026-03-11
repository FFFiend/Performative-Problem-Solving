#include <bits/stdc++.h>

using namespace std;

void dfs(int &ctr, int thresh, map<int, vector<pair<int,int>>>&g,vector<bool>&vis, int node) {
    for (pair<int,int> p : g[node]) {
        if (p.second >= thresh && !vis[p.first]) {
            vis[p.first] = true;
            ctr += 1;
            dfs(ctr, thresh,g,vis,p.first);
        }
    }
}
int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    int n,queries;
    fin >> n >> queries;
    map<int, vector<pair<int,int>>> g;
    for (int x=0;x<n-1;x++) {
        int p,q,r;
        fin >> p >> q >> r;
        g[p].push_back({q,r});
        g[q].push_back({p,r});
    }
    for (int x=0;x<queries;x++) {
        int k,node;
        fin >> k >> node;
        int ctr=0;
        vector<bool>vis(n+1,false);
        vis[node] = true;
        dfs(ctr,k,g,vis,node);
        fout << ctr << endl;
    }
}