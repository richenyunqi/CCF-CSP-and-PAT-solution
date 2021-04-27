#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ci, ei;
    bool space = false;
    while (cin >> ci >> ei) {
        ci *= ei;
        --ei;
        if (ci != 0) {
            cout << (space ? " " : "") << ci << " " << ei;
            space = true;
        }
    }
    if (not space)
        cout << "0 0";
    return 0;
}
