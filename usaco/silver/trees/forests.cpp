#include <bits/stdc++.h>

using namespace std;

vector<int>par;

int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}
void _union(int x, int y) {
    int pX = find(x);
    int pY = find(y);
    if (pX == pY) return;
    par[pX] = pY;
}
int main() {
    int n;
    cin >> n;
    par.resize(n+1,0);
    for (int x=1;x<=n;x++)  par[x] = x;
    for (int x=1;x<=n;x++) {
        int connect;
        cin >> connect;
        _union(x,connect);
    }
    set<int> vis;
    for (int x=1;x<=n;x++) vis.insert(find(x));
    cout << (int)vis.size() << endl;
}