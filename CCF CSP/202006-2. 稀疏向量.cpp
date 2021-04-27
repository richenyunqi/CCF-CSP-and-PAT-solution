#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ai, bi, xi, yi, ans = 0;
    cin >> ni >> ai >> bi;
    unordered_map<gg, gg> um;
    while (ai--) {
        cin >> xi >> yi;
        um[xi] = yi;
    }
    while (bi--) {
        cin >> xi >> yi;
        ans += um[xi] * yi;
    }
    cout << ans;
    return 0;
}