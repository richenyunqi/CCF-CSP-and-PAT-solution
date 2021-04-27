#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    double ans = 0;
    while (ni--) {
        gg ai, bi;
        cin >> ai >> bi;
        ans = max(ans, hypot(ai, bi));
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}
