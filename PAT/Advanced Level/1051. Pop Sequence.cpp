#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ni, ki;
    cin >> mi >> ni >> ki;
    vector<gg> seq(ni);
    while (ki--) {
        for (gg i = 0; i < ni; ++i) {
            cin >> seq[i];
        }
        gg cur = 1;
        stack<gg> st;
        for (gg i : seq) {
            while (cur <= ni and st.size() < mi and
                   (st.empty() or st.top() < i)) {
                st.push(cur++);
            }
            if (st.empty() or st.top() != i) {
                cout << "NO\n";
                goto loop;
            }
            st.pop();
        }
        cout << "YES\n";
    loop:;
    }
    return 0;
}
