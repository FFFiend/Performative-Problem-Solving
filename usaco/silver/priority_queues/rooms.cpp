#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> vec;
    for (int x=0;x<n;x++) {
        int a,b;
        cin >> a >> b;
        vec.push_back({{a,b},x});
    }
    // store end time, 
    int rc = 0;
    vector<int> rooms(n+1,1);
    // end point, roomidx
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    sort(vec.begin(),vec.end());
    for (int x=0;x<n;x++) {
        if (pq.empty() || pq.top().first >= vec[x].first.first) {
            rc += 1;
            rooms[vec[x].second] = rc;
            pq.push({vec[x].first.second, rc});
        } else {
            rooms[vec[x].second] = pq.top().second;
            pq.pop();
            pq.push({vec[x].first.second, rooms[vec[x].second]});
        }
    }
    cout << rc << endl;
    for (int x=0;x<n;x++) cout << rooms[x] << " ";
}