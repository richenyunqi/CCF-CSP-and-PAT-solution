#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ai;
    cin >> ni;
    unordered_map<gg, gg> um;
    while (ni--) {
        cin >> ai;
        cout << ++um[ai] << " ";
    }
    return 0;
}