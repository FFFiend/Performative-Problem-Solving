#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    int a,b;
    fin >> a >> b;
    vector<int>chicks(a,0);
    vector<pair<int,int>> ints;
    for(int x=0;x<a;x++) fin >> chicks[x];
    for (int y=0;y<b;y++) {
        int p,q;
        fin >> p >> q;
        ints.push_back({p,q});
    }
    sort(chicks.begin(), chicks.end());
    sort(ints.begin(), ints.end());
    int placed = 0;
    int idx = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    // right idea w brute force but overcomplicated and got WA
    // with SET answer unnecessarily.
    // simple endpoints min heap in NlogN time.
    for (int x=0;x<a;x++) {
        while (idx < ints.size() && ints[idx].first <= chicks[x]) {
            pq.push(ints[idx].second);
            idx += 1;
        }
        while (!pq.empty() && pq.top() < chicks[x]) {
            pq.pop();
        }
        if (!pq.empty()) {
            pq.pop();
            placed += 1;
        }

    }
    fout << placed << endl;
}