#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int m,n,k;
    fin >> m >> n >> k;
    // each row is printed out k*m times.
    vector<vector<char>> board;
    for (int x=0;x<m;x++) {
        // take the row in.
        // each character is printed out k*n times
        vector<char> row;
        for (int y=0;y<n;y++) {
            char curr;
            fin >> curr;
            for (int p=0;p<k;p++) {
                row.push_back(curr);
            }
        }
        for (int q=0;q<k;q++) {
            board.push_back(row);
        }
    }

    // print everything out
    for (int x=0;x<board.size();x++) {
        for (int y=0;y<board[0].size();y++) {
            fout << board[x][y];
        }
        fout << "\n";
    }
    return 0;
}