#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    int n;
    int ans = 0;
    fin >> n;
    vector<int> indeg(n,0);
    for (int x=0;x<n-1;x++) {
        int a,b;
        fin >> a >> b;
        a -= 1;
        b -= 1;
        indeg[a] += 1;
        indeg[b] += 1;
        ans = max(ans, max(indeg[a],indeg[b]));
    }
    fout << ans + 1;
}