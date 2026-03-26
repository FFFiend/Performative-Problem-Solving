#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int ans[n];
        for (int x=0;x<n;x++) cin >> arr[x];
        for (int x=0;x<n;x++) {
            int sm = 0;
            int lg = 0;
            for (int y=x+1;y<n;y++) {
                if (arr[y] > arr[x]) lg += 1;
                if (arr[y] < arr[x]) sm += 1;
            }
            ans[x] = max(lg,sm);
        }
        for (int x=0;x<n;x++) cout << ans[x] << " ";
        cout << endl;
    }
}