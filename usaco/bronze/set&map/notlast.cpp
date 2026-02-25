#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    int n;
    unordered_map<string, int> m;
    m["Bessie"] = 0;
    m["Elsie"] = 0;
    m["Daisy"] = 0;
    m["Gertie"] = 0;
    m["Annabelle"] = 0;
    m["Maggie"] = 0;
    m["Henrietta"] = 0;
    fin >> n;
    for (int x=0;x<n;x++) {
        string name;
        int v;
        fin >> name >> v;
        m[name] += v;
    }
    vector<pair<int, string>> vec;
    for (const auto& pair : m) {
        vec.push_back({pair.second, pair.first});
    }
    sort(vec.begin(), vec.end());
    int sec = vec[0].first;
    string ans;
    int ct = 0;
    for (int x=0;x<vec.size();x++) {
        if (vec[x].first > sec) {
            sec = vec[x].first;
            ans = vec[x].second;
            break;
        }
    }
    for (int x=0;x<vec.size();x++) {
        if (vec[x].first == sec) ct += 1;
    }
    if (ct == 1) fout << ans << endl;
    else fout << "Tie" << endl;
}