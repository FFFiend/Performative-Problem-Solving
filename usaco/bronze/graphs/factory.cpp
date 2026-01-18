#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ifstream fin("factory.in");
	ofstream fout("factory.out");
    map<int, vector<int>> g;
    int n;
    fin >> n;
    for (int x=0;x<n;x++) {
        int a,b;
        fin >> a >> b;
        g[b].push_back(a);
    }
    for (int x=1;x<=n;x++) {
        set<int> seen;
        deque<int>q;
        seen.insert(x);
        q.push_back(x);
        while (!q.empty()) {
            int curr = q.front();
            q.pop_front();
            for (int nbr : g[curr]) {
                if (!seen.count(nbr)) {
                    seen.insert(nbr);
                    q.push_back(nbr);
                }
            }
        }
        if (seen.size() == n) {
            fout << x << endl;
            return 0;
        }
    }
    fout << -1 << endl;
}