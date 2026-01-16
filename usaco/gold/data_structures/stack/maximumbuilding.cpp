#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> histograms(n,vector<int>(m,0));
    for (int x=0;x<n;x++) {
        for (int y=0;y<m;y++) {
            char f;
            cin >> f;
            grid[x][y] = f;
        }
    }
    for (int x=0;x<n;x++) {
        for (int y=0;y<m;y++) {
            if (grid[x][y] == '*') histograms[x][y] = 0;
            else histograms[x][y] = 1;
            if (x-1>=0 && grid[x][y] == '.') histograms[x][y] += histograms[x-1][y];
        }
    }
    long long ans = 0;
    for (int row=0;row<n;row++) {
        vector<int> curr = histograms[row];
        vector<int> lSmaller(m,-1);
        vector<int> rSmaller(m,m);
        stack<int> st1;
        stack<int> st2;
        for (int x=0;x<m;x++) {
            while (!st1.empty() && curr[st1.top()] > curr[x]) {
                rSmaller[st1.top()] = x;
                st1.pop();
            }
            st1.push(x);
        }

        for (int x=m-1;x>=0;x--) {
            while (!st2.empty() && curr[st2.top()] >= curr[x]) {
                lSmaller[st2.top()] = x;
                st2.pop();
            }
            st2.push(x);
        }

        for (int x=0;x<m;x++) {
            ans = max(ans, (long long)curr[x] * (rSmaller[x] - lSmaller[x] -1));
        }
    }
    cout << ans << endl;
    return 0;
}