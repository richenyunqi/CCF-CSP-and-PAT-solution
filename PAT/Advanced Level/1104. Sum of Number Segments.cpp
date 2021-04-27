#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    double s = 0.0, ai;
    for (gg i = 0; i < ni; ++i) {
        cin >> ai;
        s += (i + 1) * (ni - i) * ai;
    }
    cout << fixed << setprecision(2) << s;
    return 0;
}
