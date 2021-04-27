#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ai;
    gg cur = 0, ans = 0;
    cin >> ni;
    while (ni--) {
        cin >> ai;
        if (ai > cur) {
            ans += (ai - cur) * 6;
        } else if (ai < cur) {
            ans += (cur - ai) * 4;
        }
        cur = ai;
        ans += 5;
    }
    cout << ans;
    return 0;
}
