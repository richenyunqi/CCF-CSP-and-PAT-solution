#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ni, ai;
    cin >> mi >> ni;
    unordered_map<gg, gg> um;
    for (gg i = 0; i < mi * ni; ++i) {
        cin >> ai;
        ++um[ai];
    }
    for (auto& i : um) {
        if (i.second * 2 > mi * ni) {
            cout << i.first;
        }
    }
    return 0;
}
