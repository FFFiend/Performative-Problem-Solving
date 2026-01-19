#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

vector<string> getPath(string start, map<string, string>*graph) {
    vector<string> path;
    while ((*graph).count(start)) {
        path.push_back(start);
        start = (*graph)[start];
    }
    path.push_back(start);
    return path;
}

string valmap(int x, int flip){
    if (flip == 0) {
        if (x<=1) return "";
        string res = "grand-";
        if (x==2) return res;
        for (int y=3;y<=x;y++) {
            res = "great-" + res;
        }
        return res;
    } else {
        if (x<=2) return "";
        string res = "great-";
        if (x==3) return res;
        for (int y=4;y<=x;y++) {
            res = "great-" + res;
        }
        return res;
    }
}

int main() {
	ifstream fin("family.in");
	ofstream fout("family.out");
    map<string, string> graph;
    int n;
    string A, B;
    fin >> n >> A >> B;
    for (int x=0;x<n;x++) {
        string nb1, nb2;
        fin >> nb1 >> nb2;
        graph[nb2] = nb1;
    }
    vector<string> pathA = getPath(A, &graph);
    vector<string> pathB = getPath(B, &graph);
    set<string> setA(pathA.begin(), pathA.end());
    set<string> setB(pathB.begin(), pathB.end());
    set<string> common;
    set_intersection(setA.begin(), setA.end(),setB.begin(), setB.end(), inserter(common, common.begin()));
    if (common.size() == 0) {
        fout << "NOT RELATED" << endl; 
    }
    // same mother case i.e 
    else if (setA.count(B) || setB.count(A)) {
        // one of them is a direct descendant of the other
        string relationString = "mother";
        if (setA.count(B)) {
            // B is a relation
            int x;
            for (x=0;x<pathA.size();x++) {
                if (pathA[x] == B) break;
            }
            relationString = valmap(x,0) + relationString;
            fout << B << " is the " << relationString << " of " << A;
        } else {
            // A is a relation
            int x;
            for (x=0;x<pathB.size();x++) {
                if (pathB[x] == A) break;
            }
            relationString = valmap(x,0) + relationString;
            fout << A << " is the " << relationString << " of " << B;
        }
    }
    else {
        // aunts are always one edge away.
        int dA;
        for (int x=0;x<pathA.size();x++) {
            if (setB.count(pathA[x])) {
                dA = x;
                break;
            }
        }
        // lca is at pathA[dA];
        string lca = pathA[dA];
        int dB;
        for (int x=0;x<pathB.size();x++) {
            if (pathB[x] == lca) {
                dB = x;
                break;
            }
        }
        // shorter length is older and an aunt.
        // equal length and BOTH 1 is sibling.
        if (dA==1 && dB==1) {
            fout << "SIBLINGS" << endl;
        }
        else if (dA == 1 && dB > 1) {
            // A is the aunt
            string rel = "aunt";
            rel = valmap(dB,1) + rel;
            fout << A << " is the " << rel << " of " << B;
        }
        else if (dB == 1 && dA > 1) {
            // B is the aunt
            string rel = "aunt";
            rel = valmap(dA,1) + rel;
            fout << B << " is the " << rel << " of " << A;
        }
        else {
            fout << "COUSINS" << endl;
        }
    }
}