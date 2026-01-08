#include <fstream>
#include <vector>
#include <set>

using namespace std;

void consumeSet(set<char> *indSet, set<pair<char, char>> *teamSet, set<char> *childSet) {
    if ((*childSet).size() == 1) {
        (*indSet).insert((*childSet).begin(), (*childSet).end());
    } else if ((*childSet).size() == 2) {
        pair<char, char> team;
        int ctr = 0;
        while (!(*childSet).empty()) {
            auto smaller = (*childSet).begin();
            char curr = *smaller;
            if (ctr == 0) team.first = curr;
            else team.second = curr;
            ctr += 1;
            (*childSet).erase(smaller);
        }
        (*teamSet).insert(team);
    }
}

int main() {
	ifstream fin("tttt.in");
	ofstream fout("tttt.out");
    set<char> individualWinners;
    set<pair<char, char>> pairWinners;
    vector<string> grid(3);
    for (int x=0;x<3;x++) fin >> grid[x];

    for (int x=0;x<3;x++) {
        set<char> rowSet;
        for (int y=0;y<3;y++) {
            rowSet.insert(grid[x].at(y));
        }
        consumeSet(&individualWinners, &pairWinners, &rowSet);
    }
    for (int x=0;x<3;x++) {
        set<char> colSet;
        for (int y=0;y<3;y++) {
            colSet.insert(grid[y].at(x));
        }
        consumeSet(&individualWinners, &pairWinners, &colSet);
    }
    int x = 0;
    int y = 0;
    set<char> diagSet1;
    while (x < 3 && y < 3) {
        diagSet1.insert(grid[x].at(y));
        x += 1;
        y += 1;
    }
    consumeSet(&individualWinners, &pairWinners, &diagSet1);
    x = 2;
    y = 0;
    set<char> diagSet2;
    while (x >= 0 && y < 3) {
        diagSet2.insert(grid[x].at(y));
        x -= 1;
        y += 1;
    }
    consumeSet(&individualWinners, &pairWinners, &diagSet2);
    fout << (int)individualWinners.size() << endl;
    fout << (int)pairWinners.size() << endl;
}