#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, m = INT_MAX;
    cin >> ni;
    cin.get();
    vector<string> v(ni);
    string ans;
    for (auto& i : v) {
        getline(cin, i);
        reverse(i.begin(), i.end());
        m = min(m, (gg)i.size());
    }
    for (gg i = 0; i < m; ++i) {
        for (auto& j : v) {
            if (j[i] != v[0][i]) {
                goto loop;
            }
        }
        ans.push_back(v[0][i]);
    }
loop:
    reverse(ans.begin(), ans.end());
    cout << (ans.empty() ? "nai" : ans);
    return 0;
}