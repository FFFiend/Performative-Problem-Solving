#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    int n, m;
    fin >> n >> m;
    map<int, vector<int>> patchToCows;
    map<int, set<int>> cowExclusions;
    for (int cow=1;cow<=m;cow++) {
        int patch1, patch2;
        fin >> patch1 >> patch2;
        patchToCows[patch1].push_back(cow);
        patchToCows[patch2].push_back(cow);
    }
    for (int pasture=1;pasture<=n;pasture++) {
        int grassType = 1;
        vector<int> cowsForPasture = patchToCows[pasture];
        set<int> unionSet;
        for (int x=0;x<cowsForPasture.size();x++) {
            int currCow = cowsForPasture[x];
            for (int c : cowExclusions[currCow]) unionSet.insert(c);
        }
        while (grassType <= 4) {
            if (!unionSet.count(grassType)) {
                break;
            }
            grassType += 1;
        }
        for (int x=0;x<cowsForPasture.size();x++) {
            int currCow = cowsForPasture[x];
            cowExclusions[currCow].insert(grassType);
        }
        fout << grassType;
    }

}