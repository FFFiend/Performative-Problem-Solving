#include <fstream>
#include <vector>
#include <climits>
#include <map>
#include <deque>

using namespace std;

int main() {
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");
    deque<pair<char, int>> deq;
    int n;
    fin >> n;
    map<pair<int, int>, int> mp;
    for (int x=0;x<n;x++) {
        char dir;
        int steps;
        fin >> dir >> steps;
        deq.push_back({dir, steps});
    }
    int time = 1;
    pair<int, int> currPair = {0,0};
    mp[currPair] = 0;
    int answer = 1e9;
    while (!deq.empty()) {
        pair<char, int> np = deq.front();
        deq.pop_front();
        int steps = np.second;
        int ctr = 0;
        while (ctr < steps) {
            if (np.first == 'N') {
                currPair.second -= 1;
            }
            if (np.first == 'E') {
                currPair.first += 1;
            }
            if (np.first == 'S') {
                currPair.second += 1;
            }
            if (np.first == 'W') {
                currPair.first -= 1;
            }
            if (mp.count(currPair)) {
                answer = min(answer, time - mp[currPair]);
            }
            ctr += 1;
            mp[currPair] = time;
            time += 1;
        }
    }
    if (answer == 1e9) fout << -1 << endl;
    else {
        fout << answer << endl;
    }
    return 0;
}