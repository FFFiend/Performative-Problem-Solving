#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> a;
    long long ans = 0;
    int b[100001];
    int c[100001];
    for (int x=0;x<n;x++) {
        int v;
        cin >> v;
        a[v] += 1;
    }
    for (int x=0;x<n;x++) cin >> b[x];
    for (int x=0;x<n;x++) cin >> c[x];
    for (int x=0;x<n;x++) {
        ans += a[b[c[x]-1]];
    }
    cout << ans << endl;
}