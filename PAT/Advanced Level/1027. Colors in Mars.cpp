#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t = "0123456789ABC";
    cout << "#";
    for (gg i = 0; i < 3; ++i) {
        gg ai;
        cin >> ai;
        cout << t[ai / 13] << t[ai % 13];
    }
    return 0;
}
