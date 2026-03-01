#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    k = min(k,n-1);
    int arr[n];
    int ans[n];
    for (int x=0;x<n;x++) cin >> arr[x];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x=0;x<=k;x++) pq.push(arr[x]);
    for (int x=0;x<n;x++) {
        ans[x] = pq.top();
        pq.pop();
        if (x+k+1 < n) pq.push(arr[x+k+1]);
    }
    for (int x=0;x<n;x++) cout << ans[x] << " ";
}