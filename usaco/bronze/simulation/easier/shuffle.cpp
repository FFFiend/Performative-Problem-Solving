
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    fin >> n;
    vector<int> mapping;
    vector<int> idMap;
    mapping.resize(n+1,0);
    idMap.resize(n+1, 0);
    int counter = 1;
    for (int x=1;x<=n;x++) {
        int f;
        fin >> f;
        mapping[x] = f;
    }
    // reverse mapping stored.
    // now cycle through the i'ds
    for (int x=1;x<=n;x++) {
        int id;
        fin >> id;
        idMap[x] = id;
    }
    // 3 shuffle iteration
    while (counter <= 3) {
        vector<int> newArray;
        newArray.resize(n+1, 0);
        for (int x=1;x<=n;x++) {
            // what does x map to
            int mp = mapping[x];
            // now mp -> x
            newArray[x] = idMap[mp];
        }
        for (int x=1;x<=n;x++) {
            idMap[x] = newArray[x];
        }
        counter += 1;
    }
    for (int x=1;x<=n;x++) {
        fout << idMap[x] << endl;
    }
}