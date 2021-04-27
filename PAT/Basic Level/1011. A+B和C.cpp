#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ti, ai, bi, ci;
    cin >> ti;
    for (gg i = 1; i <= ti; ++i) {
        cin >> ai >> bi >> ci;
        cout << "Case #" << i << ": " << (ai + bi > ci ? "true" : "false")
             << "\n";
    }
    return 0;
}
