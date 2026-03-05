#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int n,g;
    fin >> n >> g;
    vector<pair<int, pair<int, long long>>> queries;
    map<long long, int> dMap;
    dMap[0] = 1000000000;
    map<int, long long> idMap;
    int days = 0;
    for (int x=0;x<n;x++) {
        int day, _id;
        long long delta;
        fin >> day >> _id >> delta;
        queries.push_back({day,{_id, delta}});
    }
    sort(queries.begin(), queries.end());
    for (int x=0;x<n;x++) {
        int id = queries[x].second.first;
        long long delta = queries[x].second.second;
        auto it = dMap.rbegin();
        long long prevLeadingQuantity = it->first;
        int prevCount = it->second;
        bool prevLeader = (idMap[id] == prevLeadingQuantity);
        

        dMap[idMap[id]] -= 1;
        if (dMap[idMap[id]] == 0) dMap.erase(idMap[id]);
        idMap[id] += delta;
        dMap[idMap[id]] += 1;

        auto it2 = dMap.rbegin();
        int newCount = it2->second;
        long long currLeadingQuantity = it2->first;
        bool currLeader = (idMap[id] == currLeadingQuantity);

        if (prevLeader) {
            if (currLeader && newCount == prevCount) {
                continue;
            }
            days += 1;
        } else if (currLeader) {
            days += 1;
        }
        
    }
    fout << days << endl;
}