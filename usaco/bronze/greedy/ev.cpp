#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ev = 0;
    int odd = 0;
    for (int x=0;x<n;x++) {
        int inp;
        cin >> inp;
        ev += (inp%2==0);
        odd += (inp%2==1);
    }

    while (odd > ev) {
        odd -= 2;
        ev += 1;
    }
    ev = min(ev, odd+1);
    // evens just merge into odd 
    // 2,4,,6,8           3
    // 2                  21
    cout << ev + odd << endl;
}