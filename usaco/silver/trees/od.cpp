#include <bits/stdc++.h>
using namespace std;

int timer = 1;
int cc[100001];
int vis[100001];
vector<pair<int,int>> ans;
vector<int> graph[100001];
void dfs(int node, int par) {
    vis[node] = timer ++;
    for (int i : graph[node]) {
        if (i == par) {
            continue;
        }
        if (!vis[i]) {
            // visit child first
            dfs(i, node);
            // now check out deg of child
            if (cc[i]%2==0) {
                // even so edge from nod eto 
                ans.push_back({node,i});
                cc[node] += 1;
            } else {
                ans.push_back({i,node});
                cc[i] += 1;
            }
        }
        else if (vis[node] > vis[i]) {
            // back edge from i to node
            ans.push_back({node,i});
            // increment outdeg for i by 1
            cc[node] += 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    // even outdegree 
    for (int x=0;x<m;x++) {
        // m lines
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int x=1;x<=n;x++) {
        if (!vis[x]) dfs(x, 0);
    }
    // if any nodes with out degree odd, return impossible
    for (int x=1;x<=n;x++) {
        if (cc[x]%2==1) {
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
    }
    for (int x=0;x<ans.size();x++) {
        cout << ans[x].first << " " << ans[x].second << "\n";
    }
}