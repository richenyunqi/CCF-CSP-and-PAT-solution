#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ni, u, v;
    cin >> mi >> ni;
    vector<gg> pre(ni);
    for (gg i = 0; i < ni; ++i)
        cin >> pre[i];
    unordered_set<gg> us(pre.begin(), pre.end());
    while (mi--) {
        cin >> u >> v;
        bool f1 = us.count(u), f2 = us.count(v);
        if (not f1 and not f2) {
            cout << "ERROR: " << u << " and " << v << " are not found.\n";
        } else if (not f1 or not f2) {
            cout << "ERROR: " << (not f1 ? u : v) << " is not found.\n";
        } else {
            gg ans = *find_if(pre.begin(), pre.end(),
                              [u, v](gg a) { return (a - u) * (a - v) <= 0; });
            if (ans == u or ans == v) {
                cout << (ans == u ? u : v) << " is an ancestor of "
                     << (ans == u ? v : u) << ".\n";
            } else {
                cout << "LCA of " << u << " and " << v << " is " << ans << ".\n";
            }
        }
    }
    return 0;
}