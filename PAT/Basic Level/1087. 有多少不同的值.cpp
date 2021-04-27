#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    unordered_set<gg> us;
    for (gg i = 1; i <= ni; ++i) {
        us.insert(i / 2 + i / 3 + i / 5);
    }
    cout << us.size();
    return 0;
}
