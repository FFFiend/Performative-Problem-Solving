#include <set>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");
    int n;
    fin >> n;
    vector<vector<int>> grid(n, vector<int>(n,0));
    for (int x=0;x<n;x++) {
        string row;
        fin >> row;
        for(int y=0;y<n;y++) {
            if (row[y] == '0') grid[x][y] = 0;
            else grid[x][y] = 1;
        }
    }
    int count = 0;
    for (int r=n-1;r>=0;r--) {
        for (int c=n-1;c>=0;c--) {
            if (grid[r][c] == 1) {
                count += 1;
                // convert everything from curr coord to 0,0
                for (int x=0;x<=r;x++) {
                    for (int y=0;y<=c;y++) {
                        grid[x][y] = (grid[x][y] + 1)%2;
                    }
                }
            }
        }
    }
    fout << count << endl;
}
