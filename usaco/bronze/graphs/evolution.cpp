#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ifstream fin("evolution.in");
    ofstream fout("evolution.out");
    set<string> traits;
    vector<vector<string>> paths;
    int n;
    fin >> n; 
    for (int x=0;x<n;x++) {
        int p;
        fin >> p;
        vector<string> currpath;
        for (int y=0;y<p;y++) {
            string tr;
            fin >> tr;
            traits.insert(tr);
            currpath.push_back(tr);
        }
        paths.push_back(currpath);
    }
    for (const auto& t1: traits) {
        for (const auto& t2: traits) {
            if (t1 != t2) {
                bool onlyA = false;
                bool onlyB = false;
                bool both = false;
                for (int x=0;x<paths.size();x++) {
                    vector<string> currpath = paths[x];
                    bool tA = false;
                    bool tB = false;
                    for (int y=0;y<currpath.size();y++) {
                        if (currpath[y] == t1) tA = true;
                        if (currpath[y] == t2) tB = true;
                    }
                    if (!tB && tA) onlyA = true;
                    if (!tA && tB) onlyB = true;
                    if (tA && tB) both = true;
                    if (onlyA && onlyB && both) {
                        fout << "no";
                        return 0;
                    }
                }
            }
        }
    }
    fout << "yes" << endl;
}