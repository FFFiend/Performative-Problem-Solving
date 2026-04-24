#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> g[n+1];
    vector<long long> pref(n+1, 0);
    vector<bool> vis(n+1, false);
    bool violated = false;
    for (int x=0;x<k;x++) {
        int l, r, s;
        cin >> l >> r >> s;
        g[l-1].push_back({r,s});
        g[r].push_back({l-1,-s});
    }
    function<void(int)> dfs = [&](int node) -> void {
        if (vis[node]) return;
        vis[node] = true;
        for (pair<int,int> cc : g[node]) {
            long long nw = pref[node] + cc.second;
            if (!vis[cc.first]) {
                pref[cc.first] = nw;
                dfs(cc.first);
                if (violated) return;
            } else if (pref[cc.first] != nw) {
                violated = true;
                return;
            }
        }
    };
    for (int x=0;x<=n;x++) {
        if (!vis[x]) {
            dfs(x);
        }
        if (violated) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int x=1;x<=n;x++) cout << pref[x] - pref[x-1] << " ";
    cout << endl;
    return 0;
}