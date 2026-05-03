#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Flight {
    long long departure_time, dest_airport, arrival_time;
};

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<Flight>> g(N+1);

    for (int x=0;x<M;x++) {
        long long c,r,d,s;
        cin >> c >> r >> d >> s;
        g[c].push_back({r,d,s});
    }
    for (int x=1;x<=N;x++) {
        sort(g[x].begin(), g[x].end(), [](const Flight& a, const Flight& b) {
            return a.departure_time < b.departure_time;
        });
    }
    vector<ll>layovers(N+1,-1);
    for (int x=1;x<=N;x++) cin >> layovers[x];
    vector<ll> dist(N+1, LLONG_MAX);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while (!pq.empty()) {
        ll cdist = pq.top().first;
        int current_airport = pq.top().second;
        pq.pop();
        if (cdist > dist[current_airport]) continue;
        bool skip_layover = (current_airport == 1 && cdist == 0);
        int l = 0;
        int r = g[current_airport].size()-1;
        int flightIdx = g[current_airport].size();
        while (l<=r) {
            int mid = (l+r)/2;
            if (g[current_airport][mid].departure_time >= layovers[current_airport] + cdist) {
                flightIdx = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        if (skip_layover) {
            flightIdx = 0;
        }
        for (int x=flightIdx;x<g[current_airport].size();x++) {
            Flight flight = g[current_airport][x];
            if (skip_layover || flight.departure_time >= layovers[current_airport] + cdist) {
                if (dist[flight.dest_airport] > flight.arrival_time) {
                    dist[flight.dest_airport] = flight.arrival_time;
                    pq.push({flight.arrival_time, flight.dest_airport});
                }
            }
        }
    }

    for (int x=1;x<=N;x++) {
        if (dist[x] == LLONG_MAX) cout << -1 << endl;
        else cout << dist[x] << endl;
    }
}