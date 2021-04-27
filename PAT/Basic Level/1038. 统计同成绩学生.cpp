#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<gg, 105> h{};
    gg n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        ++h[a];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        cout << (i == 0 ? "" : " ") << h[a];
    }
    return 0;
}
