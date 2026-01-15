#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int main() {
	ifstream fin("art2.in");
	ofstream fout("art2.out");
    int n;
    fin >> n;
    vector<int> vec(n,0);
    map<int, int> mp;
    stack<int> st;
    set<int> seen;
    for (int x=0;x<n;x++) {
        fin >> vec[x];
        mp[vec[x]] += 1;
    }
    int ans = 1;
    for (int x=0;x<n;x++) {
        if (vec[x] == 0) {
            if (!st.empty()) {
                fout << -1 << endl;
                return 0;
            }
            continue;
        }
        mp[vec[x]] -= 1;
        if (!seen.count(vec[x])) {
            st.push(vec[x]);
            ans = max(ans, (int)st.size());
            seen.insert(vec[x]);
        } 
        if (mp[vec[x]] == 0 && seen.count(vec[x])) {
            // last occurrence of the current color
            if (!st.empty() && st.top() != vec[x]) {
                fout << -1 << endl;
                return 0;
            }
            if (!st.empty()) {
                seen.erase(vec[x]);
                st.pop();
            }
        }

    }
    fout << ans << endl;
    return 0;
}