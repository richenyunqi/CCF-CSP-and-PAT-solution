#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    gg s = 0;
    double ai;
    for (gg i = 0; i < ni; ++i) {
        cin >> ai;
        s += (gg)(ai * 1000) * (i + 1) * (ni - i);
    }
    cout << fixed << setprecision(2) << (s / 1000.0);
    return 0;
}
