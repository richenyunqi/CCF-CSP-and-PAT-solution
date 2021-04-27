#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<array<gg, 2>> s;
    gg ni, a, b, c, d;
    cin >> ni;
    while (ni--) {
        cin >> a >> b >> c >> d;
        for (gg i = a; i < c; ++i) {
            for (gg j = b; j < d; ++j) {
                s.insert({i, j});
            }
        }
    }
    cout << s.size();
    return 0;
}
