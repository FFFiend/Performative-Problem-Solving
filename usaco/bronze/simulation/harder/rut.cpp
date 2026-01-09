#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> east;
    vector<pair<int, int>> north;
    map<int, pair<int, int>> mp;
    set<pair<int, int>> stopped;
    map<pair<int, int>, int> cminMap;
    for (int x=0;x<n;x++) {
        char dir;
        int a,b;
        cin >> dir >> a >> b;
        if (dir == 'N') {
            north.push_back({a,b});
        } else {
            east.push_back({a,b});
        }
        mp[x] = {a,b};
        cminMap[{a,b}] = 1e9;
    }
    sort(north.begin(), north.end());
    sort(east.begin(), east.end());
    for (int x=0;x<north.size();x++) {
        int x1 = north[x].first;
        int y1 = north[x].second;
        for (int y=0;y<east.size();y++) {
            int x2 = east[y].first;
            int y2 = east[y].second;
            if (x2 <= x1 && y1 <= y2) {
                int incX = x1;
                int incY = y2;
                int northDiff = abs(x1 - incX) + abs(y1 - incY);
                int eastDiff = abs(x2 - incX) + abs(y2 - incY);
                if (northDiff > eastDiff) {
                    cminMap[{x1,y1}] = min(cminMap[{x1,y1}], northDiff);
                    stopped.insert({x1,y1});
                }
            }
        }
    }
    for (int x=0;x<east.size();x++) {
        int x1 = east[x].first;
        int y1 = east[x].second;
        for (int y=0;y<north.size();y++) {
            int x2 = north[y].first;
            int y2 = north[y].second;
            if (stopped.count({x2,y2})) continue;
            if (x2 >= x1 && y1 >= y2) {
                int incX = x2;
                int incY = y1;
                int eastDiff = abs(x1 - incX) + abs(y1 - incY);
                int northDiff = abs(x2 - incX) + abs(y2 - incY);
                if (eastDiff > northDiff) {
                    cminMap[{x1,y1}] = min(cminMap[{x1,y1}], eastDiff);
                }
            }
            if (x1 == 11 && y1 == 2) cout << cminMap[{x1,y1}] << endl;
        }
    }
    for (int x=0;x<n;x++) {
        if (cminMap[mp[x]] > 1e9) cout << "Infinity" << endl;
        else cout << cminMap[mp[x]] << endl;
    }
}