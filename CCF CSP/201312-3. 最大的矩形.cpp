#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ans = 0;
    cin >> ni;
    vector<gg> v(ni);
    for (gg& i : v) {
        cin >> i;
    }
    for (gg i = 0; i < ni; ++i) {
        gg m = v[i];  //最小高度
        for (gg j = i; j < ni; ++j) {
            m = min(m, v[j]);
            ans = max(ans, (j - i + 1) * m);
        }
    }
    cout << ans;
    return 0;
}