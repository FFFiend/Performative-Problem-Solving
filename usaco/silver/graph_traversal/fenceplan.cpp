#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int par[100001];
pair<pair<int,int>, pair<int,int>> mp[100001];

int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}

void _union(int x, int y) {
    int xPar = find(x);
    int yPar = find(y);
    if (xPar == yPar) return;
    par[yPar] = xPar;
    mp[xPar].first.first = min(mp[xPar].first.first, mp[yPar].first.first);
    mp[xPar].first.second = min(mp[xPar].first.second,mp[yPar].first.second);
    mp[xPar].second.first = max(mp[xPar].second.first, mp[yPar].second.first);
    mp[xPar].second.second = max(mp[xPar].second.second, mp[yPar].second.second);
}
int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");
    int n,m;
    fin >> n >> m;
    map<int, pair<int, int>> cords;
    for (int x=1;x<=n;x++) {
        int a,b;
        fin >> a >> b;
        cords[x] = {a,b};
        par[x] = x;
        mp[x] = {{a,b},{a,b}};
    }
    for (int y=0;y<m;y++) {
        int a,b;
        fin >> a >> b;
        _union(a,b);
    }
    long long ans = LLONG_MAX;
    for (int x=1;x<=n;x++) {
        if (par[x] != x) continue;
        auto& [p1,p2] = mp[x];
        ans = min(ans, 2LL * ((long long)(p2.first - p1.first) + (long long)(p2.second - p1.second)));
    }
    fout << ans << endl;
}