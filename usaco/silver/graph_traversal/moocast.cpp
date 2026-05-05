#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int val, vector<pair<int, int>>& v) {
    queue<int> q;
    vector<bool> seen((int)v.size(),false);
    q.push(0);
    seen[0] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int x=0;x<v.size();x++) {
            if (!seen[x]) {
                ll dx = v[x].first - v[curr].first;
                ll dy = v[x].second - v[curr].second;
                if (dx*dx + dy*dy <= val) {
                    seen[x] = true;
                    q.push(x);
                }
            }
        }
    }
    for (bool val : seen) {
        if (!val) return false;
    }
    return true;
}
int main() {
    int n;
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> n;
    vector<pair<int, int>> v;
    for (int _=0;_<n;_++) {
        int x,y;
        fin >> x >> y;
        v.push_back({x,y});
    }
    ll l = 0;
    ll r = 1250000000;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r)/2;
        if (check(mid, v)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    fout << ans << endl;
}