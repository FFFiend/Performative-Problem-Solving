#include <bits/stdc++.h>

using namespace std;

void solve() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c,0));
    vector<vector<int>> consec(r, vector<int>(c,0));
    long long total = 0;
    for (int x=0;x<r;x++) {
        for (int y=0;y<c;y++) {
            cin >> grid[x][y];
        }
    }
    for (int x=0;x<r;x++) {
        int prev = -1;
        int tmp = 0;
        for (int y=0;y<c;y++) {
            if (grid[x][y] == prev) {
                tmp += 1;
            }
            else {
                prev = grid[x][y];
                tmp = 1;
            }
            consec[x][y] = tmp;
        }
    }
    for (int y=0;y<c;y++) {
        stack<pair<int, int>> st;
        int curr = 0;
        int prev = grid[r-1][y];
        for (int x=r-1;x>=0;x--) {
            if (grid[x][y] != prev) {
                prev = grid[x][y];
                curr = 0;
                st = stack<pair<int,int>>();
            }
            int pops = 0;
            while (!st.empty() && st.top().first > consec[x][y]) {
                // curr -= (row at stack top + 1) * (widthdiff);
                curr -= (st.top().second + 1) * (st.top().first - consec[x][y]);
                pops += st.top().second + 1;
                st.pop();
            }
            st.push({consec[x][y], pops});
            curr += consec[x][y];
            total += curr;
        }
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}