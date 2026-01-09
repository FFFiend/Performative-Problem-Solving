#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int start, end;
    fin >> start >> end;
    int flip = 0;
    int t = 1;
    int ans = 0;
    int currCoord = start;
    int old = start;
    while (true) {
        int mult = 1;
        if (flip == 1) mult = -1;
        currCoord = start + mult * t;
        ans = (ans + abs(old - currCoord));
        if ((start < end && currCoord >= end) || start == end || (start > end && currCoord <= end)) {
            ans -= abs(currCoord - end);
            break;
        }
        old = currCoord;
        flip = (flip + 1)%2;
        t *= 2;
    }
    fout << ans << endl;
}