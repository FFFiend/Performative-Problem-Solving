#include <fstream>
#include <stack>
#include <string>
#include <algorithm>


using namespace std;

int main() {
    ifstream fin("censor.in");
	ofstream fout("censor.out");

    string par, sub;
    fin >> par >> sub;
    stack<char> st;

    for (int x=0;x<par.length();x++) {
        // just have the method here fuck it
        st.push(par[x]);
        int i = sub.size()-1;
        stack<char> tempStack;
        while (!st.empty() && i >= 0 && st.top() == sub.at(i)) {
            tempStack.push(st.top());
            i -= 1;
            st.pop();
        }
        if (i >= 0) {
            while (!tempStack.empty()) {
                st.push(tempStack.top());
                tempStack.pop();
            }
        }
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    fout << ans << endl;
    return 0;
}