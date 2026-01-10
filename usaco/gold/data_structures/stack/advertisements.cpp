#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n,0);
    for (int x=0;x<n;x++) cin >> vec[x];
    vector<int> lSmaller(n,-1);
    vector<int> rSmaller(n,n);
    long long ans = 0;

    // nearest smaller to the left

    // nearest smaller to the right
    stack<int> st;
    for (int x=0;x<n;x++) {
        while (!st.empty() && vec[st.top()] > vec[x]) {
            // found nearest smaller
            rSmaller[st.top()] = x;
            st.pop();
        }
        st.push(x);
    }
    stack<int> st2;
    for (int x=n-1;x>=0;x--) {
        while (!st2.empty() && vec[st2.top()] >= vec[x]) {
            lSmaller[st2.top()] = x;
            st2.pop();
        }
        st2.push(x);
    }
    // nearest smaller to the left
    for (int x=0;x<n;x++) {
        ans = max(ans, (long long)vec[x] * (rSmaller[x] - lSmaller[x] - 1));
    }
    cout << ans << endl;
    return 0;
}
