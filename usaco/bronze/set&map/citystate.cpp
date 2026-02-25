#include <map>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");
    map<pair<string, string>, int> f1;
    int n;
    fin >> n;
    long long ans = 0;
    for (int x=0;x<n;x++) {
        string city, state;
        fin >> city >> state;
        if (f1.count({state, city.substr(0,2)}) && state != city.substr(0,2)) {
            ans += f1[{state, city.substr(0,2)}];
        }
        f1[{city.substr(0,2), state}] += 1;
    }
    fout << ans << endl;
}