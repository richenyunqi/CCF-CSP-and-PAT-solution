#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ans = 0;
    cin >> ni;
    for (; ni != 1; ++ans) {
        if (ni % 2 == 1) {
            ni = 3 * ni + 1;
        }
        ni /= 2;
    }
    cout << ans;
    return 0;
}