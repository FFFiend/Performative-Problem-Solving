#include <bits/stdc++.h>

using namespace std;

void dfs(int node, set<int>&vis, int cc, vector<int>&rep, map<int,vector<int>>&g, vector<char>&cVal) {
    rep[node] = cc;
    for (int nbr : g[node]) {
        if (!vis.count(nbr) && cVal[nbr] == cVal[node]) {
            vis.insert(nbr);
            dfs(nbr, vis, cc, rep,g,cVal);
        }
    }
}

int main() {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    int n,m;
    fin >> n >> m;
    map<int,vector<int>> g;
    set<int> vis;
    vector<char> cVal(n+1,' ');
    vector<int> rep(n+1,0);
    for (int x=1;x<=n;x++) fin >> cVal[x];
    for (int x=0;x<n-1;x++) {
        int a,b;
        fin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cc = 0;
    for (int x=1;x<=n;x++) {
        if (!vis.count(x)) {
            cc += 1;
            vis.insert(x);
            dfs(x,vis,cc,rep,g,cVal);
        } 
    }
    for (int q=0;q<m;q++) {
        int start,end;
        char type;
        fin >> start >> end >> type;
        if (rep[start] == rep[end]) {
            if (cVal[start] == type) {
                fout << 1;
            } else {
                fout << 0;
            }
        } else {
            fout << 1;
        }
    }
}