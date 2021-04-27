#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ki, ti, ai;
    cin >> ni >> mi;
    vector<array<gg, 2>> edges(mi);
    for (auto& e : edges) {
        cin >> e[0] >> e[1];
    }
    cin >> ki;
    while (ki--) {
        cin >> ti;
        unordered_set<gg> us;
        while (ti--) {
            cin >> ai;
            us.insert(ai);
        }
        for (auto& e : edges) {
            if (not us.count(e[0]) and not us.count(e[1])) {
                cout << "No\n";
                goto loop;
            }
        }
        cout << "Yes\n";
    loop:;
    }
    return 0;
}
