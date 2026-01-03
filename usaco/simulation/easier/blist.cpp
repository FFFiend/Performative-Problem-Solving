#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int n;
    fin >> n;
    vector<int> arr;
    int ans = 0;
    arr.resize(1001,0);
    for (int x=0;x<n;x++) {
        int start, end, buckets;
        fin >> start >> end >> buckets;
        while (start <= end) {
            arr[start] += buckets;
            start += 1;
        }
    }
    for (int x=1;x<=1000;x++) {
        ans = max(ans, arr[x]);
    }
    fout << ans << endl;
}