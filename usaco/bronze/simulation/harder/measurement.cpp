#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
    int n;
    fin >> n;
    vector<pair<int, pair<string, int>>> updates;
    map<string, int> cmap;
    for (int x=0;x<n;x++) {
        int p;
        string s;
        int diff;
        fin >> p >> s >> diff;
        cmap[s] = 7;
        updates.push_back({p,{s,diff}});
    }
    sort(updates.begin(), updates.end());
    int ans = 0;
    for (int x=0;x<n;x++) {
        pair<int, pair<string, int>> currUpdate = updates[x];
        int maxB = 0;
        for (auto &p: cmap) {
            maxB = max(maxB, p.second);
        }
        set<string> oldState;
        for (auto &p: cmap) {
            if (p.second == maxB) oldState.insert(p.first);
        }
        cmap[currUpdate.second.first] += currUpdate.second.second;

        int maxA = 0;
        for (auto &p: cmap) {
            maxA = max(maxA, p.second);
        }
        set<string> newState;
        for (auto &p: cmap) {
            if (p.second == maxA) newState.insert(p.first);
        }
        ans += (oldState != newState);
    }
    fout << ans << endl;
}