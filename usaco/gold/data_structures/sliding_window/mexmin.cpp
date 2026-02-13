#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> vec(n,0);
    for (int x=0;x<n;x++) cin >> vec[x];
    set<int> missing;
    vector<int> freq(n+1,0);
    for (int x=0;x<=n;x++) missing.insert(x);
    int ans = INT_MAX;
    for (int x=0;x<n;x++) {
        freq[vec[x]] += 1;
        if (x < m) {
            missing.erase(vec[x]);
        } else {
            ans = min(ans, *missing.begin());
            missing.erase(vec[x]);
            freq[vec[x-m]] -= 1;
            if (freq[vec[x-m]] == 0) {
                missing.insert(vec[x-m]);
            }
        }
    }
    cout << min(ans, *missing.begin());
}
