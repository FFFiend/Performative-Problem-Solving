#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<set<int>> banned(n+1);
    for (int x=0;x<m;x++) {
        int a,b;
        cin >> a >> b;
        banned[a].insert(b);
        banned[b].insert(a);
    }
    set<int> rm;
    for (int x=1;x<=n;x++) {
        rm.insert(x);
    }
    int ctr = 0;
    vector<int> par(n+1,0);
    vector<int> reps(n+1,0);
    for (int node=1;node<=n;node++) {
        if (!rm.count(node)) continue;
        ctr += 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int cx = q.front();
            q.pop();
            rm.erase(cx);
            par[cx] = ctr;
            vector<int> cands;
            // iterate over rm and check if val is in banned[cx]
            for (const int& nbr : rm) {
                if (!banned[cx].count(nbr)) {
                    cands.push_back(nbr);
                }
            }
            for (int v: cands) {
                rm.erase(v);
                q.push(v);
            }
        }
    }
    for (int x=1;x<=n;x++) {
        reps[par[x]] += 1;
    }
    sort(reps.begin(), reps.end());
    cout << ctr << endl;
    for (int x=0;x<reps.size();x++) {
        if (reps[x] == 0) continue;
        cout << reps[x] << " ";
    }
}