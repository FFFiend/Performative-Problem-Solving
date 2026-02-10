#include <bits/stdc++.h>

using namespace std;

// theorem: for a fixed u and for any v in V, 
// if reachable(u,v) and reachable(v,u) then 
// reachable(x,y) for all x,y in V

void dfs(set<int>& seenset, int curr, int par, map<int, vector<int>>& g) {
    for (int nbr : g[curr]) {
        if (nbr == par) {
            continue;
        }
        if (!seenset.count(nbr)) {
            seenset.insert(nbr);
            dfs(seenset, nbr, curr, g);
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    map<int, vector<int>> G;
    map<int, vector<int>> inverseG;
    set<int> seen;
    set<int> seenInverse;
    int start = 1;
    for (int x=0;x<m;x++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        inverseG[b].push_back(a);
    }
    seen.insert(start);
    seenInverse.insert(start);
    dfs(seen, start, start, G);
    dfs(seenInverse, start, start, inverseG);
    if (!((int)seen.size()==n && (int)seenInverse.size()==n)) {
        for (int x=1;x<=n;x++) {
            if (!seen.count(x) || !seenInverse.count(x)) {
                cout << "NO" << endl;
                if (!seen.count(x)) cout << start << " " << x;
                else cout << x << " " << start;
                return 0;
            }
        }
    }
    else {
        cout << "YES" << endl;
        return 0;
    }
}
