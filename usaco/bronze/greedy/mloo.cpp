#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<long long> vec;
    for (int x=0;x<n;x++) {
        long long inp;
        cin >> inp;
        vec.push_back(inp);
    }
    long long total = k+1;
    long long d = vec[0];
    for (int x=0;x<n;x++) {
        if (vec[x]-d<k+1) {
            total += vec[x]-d;
        } else {
            total += (k+1);
        }
        d = vec[x];
    }
    cout << total << endl;
}
