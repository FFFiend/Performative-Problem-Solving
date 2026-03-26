#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,c;
        long long k;
        cin >> n >> c >> k;
        map<long long, int> mp;
        long long ans = c;
        for (int x=0;x<n;x++) {
            int v;
            cin >> v;
            mp[v] += 1;
        }
        while (true) {
            auto it = mp.lower_bound(ans);
            if (it != mp.end() && it->first == ans) {
                ans += it->first;
                it->second--;
                if (it->second==0) mp.erase(it);
            } else if (it == mp.begin()) {
                break;
            } else {
                --it;
                long long diff = ans-it->first;
                if (k >= diff) {
                    k -= diff;
                    ans += it->first + diff;
                    it -> second--;
                    if (it->second==0) mp.erase(it);
                }
                else{
                    ans += it->first+k;
                    k = 0;
                    it -> second--;
                    if (it->second==0) mp.erase(it);
                }
            }
        }
        cout << ans << endl;
    }
}