#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int rc,gc,bc;
        cin >> rc >> gc >> bc;
        vector<pair<int,char>> arr = {{rc,'R'},{gc,'G'},{bc,'B'}};
        vector<char> ans;
        while (true) {
            sort(arr.rbegin(), arr.rend());
            if (ans.empty()) {
                arr[0].first -= 1;
                ans.push_back(arr[0].second);
                continue;
            }
            int rx,gx,bx;
            for (int x=0;x<3;x++) {
                if (arr[x].second == 'R') rx = x;
                if (arr[x].second == 'G') gx = x;
                if (arr[x].second == 'B') bx = x;
            }
            set<char> banSet;
            if ((int)ans.size()-1>=0) banSet.insert(ans[ans.size()-1]);
            if ((int)ans.size()-3>=0) banSet.insert(ans[ans.size()-3]);
            vector<pair<int, char>> remaining;
            for (int x=0;x<3;x++) {
                if (!banSet.count(arr[x].second) && arr[x].first > 0) {
                    remaining.push_back(arr[x]);
                }
            }
            // if no remaining, stop
            if (remaining.empty()) break;
            // at least 1
            sort(remaining.rbegin(), remaining.rend());
            if (remaining.size() == 2 
                && remaining[0].first == remaining[1].first 
                && ans.size() >= 2) {
                // place th eone at ans.size()-2 idx
                char placedChar = ans[ans.size()-2];
                if (placedChar == remaining[0].second) {
                    if (remaining[0].second == 'R') {
                        arr[rx].first -= 1;
                        ans.push_back('R');
                    } else if (remaining[0].second == 'G') {
                        arr[gx].first -= 1;
                        ans.push_back('G');
                    } else {
                        arr[bx].first -= 1;
                        ans.push_back('B');
                    }
                } else {
                    if (remaining[1].second == 'R') {
                        arr[rx].first -= 1;
                        ans.push_back('R');
                    } else if (remaining[1].second == 'G') {
                        arr[gx].first -= 1;
                        ans.push_back('G');
                    } else {
                        arr[bx].first -= 1;
                        ans.push_back('B');
                    }
                }
            } else {
                if (remaining[0].second == 'R') {
                    arr[rx].first -= 1;
                    ans.push_back('R');
                } else if (remaining[0].second == 'G') {
                    arr[gx].first -= 1;
                    ans.push_back('G');
                } else {
                    arr[bx].first -= 1;
                    ans.push_back('B');
                }
            }
        }
        for (char c : ans) cout << c;
        cout << endl;
    }
}