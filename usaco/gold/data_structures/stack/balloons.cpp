#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<pair<double, double>> st;
    for (int x=0;x<n;x++) {
        double xpos, maxRadius;
        cin >> xpos >> maxRadius;
        cout << fixed << setprecision(3);

        while (!st.empty()) {
            double maxAllowableRadius = (xpos-st.top().first) * (xpos-st.top().first) / (4*st.top().second);
            if (maxAllowableRadius <= maxRadius) {
                maxRadius = maxAllowableRadius;
            }

            // covers previous balloon
            if (maxRadius >= st.top().second) {
                st.pop();
            } else {
                break;
            }
        }
        cout << maxRadius << endl;
        st.push({xpos, maxRadius});
    }
}