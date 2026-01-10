#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n,0);
    vector<int> lSmaller(n,-1);
    vector<int> rSmaller(n,n);
    stack<int> st;
    stack<int> st2;
    vector<int> windowSizes(n+1,0);
    for (int x=0;x<n;x++) cin >> vec[x];
    for (int x=0;x<n;x++) {
        while (!st.empty() && vec[st.top()] > vec[x]) {
            // found nearest smaller
            rSmaller[st.top()] = x;
            st.pop();
        }
        st.push(x);
    }
    for (int x=n-1;x>=0;x--) {
        while (!st2.empty() && vec[st2.top()] >= vec[x]) {
            lSmaller[st2.top()] = x;
            st2.pop();
        }
        st2.push(x);
    }
    // smaller and larger values.
    // map arr[x] to the window size 
    for (int x=0;x<n;x++) {
        int currWindowSize = rSmaller[x] - lSmaller[x] - 1;
        windowSizes[currWindowSize] = max(windowSizes[currWindowSize], vec[x]);
    }

    // min for widnow size k will also be the minimum for a window size of k-1, k-2,...1
    for (int x=n-1;x>=1;x--) {
        windowSizes[x] = max(windowSizes[x], windowSizes[x+1]);
    }
    for (int x=1;x<=n;x++) cout << windowSizes[x] << " ";
}