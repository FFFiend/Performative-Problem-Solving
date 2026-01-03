#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int n,m;
    fin >> n >> m;
    vector<int> road;
    vector<int> data;
    road.resize(101,0);
    data.resize(101,0);
    int t = 1;
    int ans = 0;
    for (int x=0;x<n;x++) {
        int lim, speed;
        fin >> lim >> speed;
        // road[p] = speed;
        int thresh = t + lim;
        while (t < thresh) {
            road[t] = speed;
            t += 1;
        }
    }
    t = 1;
    for (int x=0;x<m;x++) {
        int lim, speed;
        fin >> lim >> speed;
        // data[p] = speed;
        int thresh = t + lim;
        while (t < thresh) {
            data[t] = speed;
            t += 1;
        }
    }

    for (int x=0;x<road.size();x++) {
        if (road[x] < data[x]) {
            ans = max(ans, data[x]-road[x]);
        }
    }
    fout << ans << endl;
}