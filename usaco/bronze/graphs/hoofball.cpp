#include <fstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");
    int n;
    fin >> n;
    if (n == 1) {
        fout << 1 << endl;
        return 0;
    }
    vector<int>vec(n,0);
    vector<int>indeg(n,0);
    vector<int>md(n,1e9);
    set<pair<int, int>> edges;
    for (int x=0;x<n;x++) fin >> vec[x];
    sort(vec.begin(), vec.end());
    for (int x=0;x<n;x++) {
        int idx;
        if (x == 0) idx = 1;
        else if (x==n-1) idx = n-2;
        else if (vec[x] - vec[x-1] <= vec[x+1] - vec[x]) idx = x-1;
        else idx = x+1;
        edges.insert({x,idx});
        indeg[idx] += 1;
    }
    int ans = 0;
    for (int x=0;x<n;x++) ans += (indeg[x] == 0);
    for (int x=0;x<n;x++) {
        int y = x-1;
        if (edges.count({x,y}) && edges.count({y,x}) && indeg[x]==1 && indeg[y]==1) {
            ans += 1;
        }
    }
    fout << ans;
}