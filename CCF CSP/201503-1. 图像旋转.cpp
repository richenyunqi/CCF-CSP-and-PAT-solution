#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    vector<vector<gg>> ai(ni, vector<gg>(mi));
    for (auto& i : ai) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    for (gg j = mi - 1; j >= 0; --j) {
        for (gg i = 0; i < ni; ++i) {
            cout << ai[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}