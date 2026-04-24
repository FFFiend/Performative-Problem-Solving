#include <bits/stdc++.h>
using namespace std;

int par[100001];
int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}
bool _u(int x, int y) {
    int xp = find(x);
    int yp = find(y);
    if (xp == yp) return true;
    par[yp] = xp;
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n==1) {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> g(n+1);
        long long ans = 2e18;
        for (int x=0;x<100001;x++) {
            par[x] = x;
        }
        for (int x=0;x<m;x++) {
            int a, b;
            cin >> a >> b;
            _u(a,b);
        }
        vector<vector<int>> v(n+1);
        for (int x=1;x<=n;x++) {
            int idx = find(x);
            v[idx].push_back(x);
        }
        vector<int> oneCC = v[find(1)];
        vector<int> nCC = v[find(n)];
        if (find(1) == find(n)) {
            cout << 0 << endl;
            continue;
        }
        for (int x=1;x<=n;x++) {
            if (v[x].empty()) continue;
            long long temp1 = 2e18;
            long long temp2 = 2e18;
            for (int node : v[x]) {
                auto it = lower_bound(oneCC.begin(), oneCC.end(), node);
                if (it != oneCC.end()) {
                    long long d = (long long)(*it - node) * (*it - node);
                    temp1 = min(temp1, d);
                }
                if (it != oneCC.begin()) {
                    --it;
                    long long d = (long long)(*it - node) * (*it - node);
                    temp1 = min(temp1, d);
                }

                auto it2 = lower_bound(nCC.begin(), nCC.end(), node);
                if (it2 != nCC.end()) {
                    long long d = (long long)(*it2 - node) * (*it2 - node);
                    temp2 = min(temp2, d);
                }
                if (it2 != nCC.begin()) {
                    --it2;
                    long long d = (long long)(*it2 - node) * (*it2 - node);
                    temp2 = min(temp2, d);
                }
            }
            ans = min(ans, temp1+temp2);
        }
        cout << ans << endl;
    }
}