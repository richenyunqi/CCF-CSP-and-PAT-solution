#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<gg> v(ni);
    for (gg& i : v) {
        cin >> i;
    }
    cout << (v[0] + v[1]) / 2;
    for (gg i = 1; i < ni - 1; ++i) {
        cout << " " << (v[i - 1] + v[i] + v[i + 1]) / 3;
    }
    cout << " " << (v[ni - 1] + v[ni - 2]) / 2;
    return 0;
}
