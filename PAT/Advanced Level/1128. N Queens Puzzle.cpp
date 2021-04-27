#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki;
    cin >> ki;
    while (ki--) {
        cin >> ni;
        vector<gg> v(ni);
        for (gg& i : v) {
            cin >> i;
        }
        for (gg i = 0; i < v.size(); ++i) {
            for (gg j = i + 1; j < v.size(); ++j) {
                if (v[j] == v[i] or abs(j - i) == abs(v[j] - v[i])) {
                    cout << "NO\n";
                    goto loop;
                }
            }
        }
        cout << "YES\n";
    loop:;
    }
    return 0;
}
