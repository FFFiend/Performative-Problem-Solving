#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int main() {
    int n,u;
    cin >> n >> u;
    vector<vector<char>> vec(n, vector<char>(n,'0'));
    vector<vector<pair<int, int>>> counts(n/2, vector<pair<int, int>>(n/2, {0, 0}));
    vector<pair<int, int>> updates;
    for (int x=0;x<n;x++) {
        for (int y=0;y<n;y++) {
            char c;
            cin >> c;
            vec[x][y] = c;
        }
    }
    for (int x=0;x<u;x++) {
        int dx,dy;
        cin >> dx >> dy;
        updates.push_back({dx-1,dy-1});
    }
    int ans = 0;
    for (int x=0;x<n/2;x++) {
        for (int y=0;y<n/2;y++) {
            int dc = 0;
            int hc = 0;
            int r1 = x, c1 = y;       
            int r2 = x, c2 = n-1-y;       
            int r3 = n-1-x, c3 = y;           
            int r4 = n-1-x, c4 = n-1-y;       
            if (vec[r1][c1] == '.') dc++; else hc++;
            if (vec[r2][c2] == '.') dc++; else hc++;
            if (vec[r3][c3] == '.') dc++; else hc++;
            if (vec[r4][c4] == '.') dc++; else hc++;
            ans += min(dc, hc);
            counts[x][y] = {dc,hc};
        }
    }
    // initial answer has board state AFTER all updates (i.e in reverse)
    // minimum is always either 1 or 2.
    cout << ans << endl;
    for (int i=0;i<updates.size();i++) {

        pair<int, int> px= updates[i];

        int nx = min(px.first, n-1-px.first);
        int ny = min(px.second, n-1-px.second);

        pair<int, int> ct = counts[nx][ny];

        ans -= min(ct.first, ct.second);
        if (vec[px.first][px.second] == '#') { 
            vec[px.first][px.second] = '.'; 
            ct.second -= 1;
            ct.first += 1;
        }
        else { 
            vec[px.first][px.second] = '#'; 
            ct.second += 1;
            ct.first -= 1;
        }
        ans += min(ct.first, ct.second);
        counts[nx][ny] = ct;
        cout << ans << endl;
    }
}
