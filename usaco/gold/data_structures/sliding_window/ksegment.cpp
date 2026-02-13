#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> vec(n,0);
    for (int x=0;x<n;x++) cin >> vec[x];
    unordered_map<int, int> freq;
    int l = 0;
    int p = 1;
    int q = 1;
    for (int x=0;x<n;x++) {
        freq[vec[x]] += 1;
        while ((int)freq.size() > k && l < x) {
            freq[vec[l]] -= 1;
            if (freq[vec[l]] == 0) {
                freq.erase(vec[l]);
            }
            l += 1;
        }
        if (x-l > q-p) {
            q = x+1;
            p = l+1;
        }
    }
    cout << p << " " << q;
}