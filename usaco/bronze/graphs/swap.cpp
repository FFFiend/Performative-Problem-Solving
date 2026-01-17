#include <fstream>
#include <vector>

using namespace std;

bool samePermutation(vector<int>* numbers) {
    for (int x=1;x<=(*numbers).size()-1;x++) {
        if ((*numbers)[x] != x) return false;
    }
    return true;
}

int main() {
	ifstream fin("swap.in");
	ofstream fout("swap.out");
    int n,k;
    fin >> n >> k;
    vector<pair<int, int>> ops(2,{0,0});
    vector<int> numbers(n+1, 0);
    for (int x=1;x<=n;x++) numbers[x] = x;
    for (int x=0;x<2;x++) {
        int start, end;
        fin >> start >> end;
        ops[x].first = start;
        ops[x].second = end;
    }
    int period = 0;
    while (true) {
        for (int x=0;x<2;x++) {
            int l = ops[x].first;
            int r = ops[x].second;
            while (l < r) {
                int temp = numbers[l];
                numbers[l] = numbers[r];
                numbers[r] = temp;
                l += 1;
                r -= 1;
            }
        }
        period += 1;
        if (samePermutation(&numbers)) break;
    }
    for (int x=1;x<=n;x++) numbers[x] = x;

    int steps = k%period;
    for (int y=0;y<steps;y++) {
        for (int x=0;x<2;x++) {
            int l = ops[x].first;
            int r = ops[x].second;
            while (l < r) {
                int temp = numbers[l];
                numbers[l] = numbers[r];
                numbers[r] = temp;
                l += 1;
                r -= 1;
            }
        }
    }
    for (int x=1;x<=n;x++) fout << numbers[x] << endl;

}