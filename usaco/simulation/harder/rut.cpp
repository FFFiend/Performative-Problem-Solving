#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<char, pair<int, int>>> vec;
    for (int x=0;x<n;x++) {
        char dir;
        int a,b;
        cin >> dir >> a >> b;
        vec.push_back({dir, {a,b}});
    }
    // remove ones that never intersect with any others.

    // simulate for the rest. => brute force..
    // any way to find the intersection point?
}