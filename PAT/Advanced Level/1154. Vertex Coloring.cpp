#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ki;
    cin >> ni >> mi;
    vector<array<gg, 2>> edges(mi);
    for (auto& e : edges) {
        cin >> e[0] >> e[1];
    }
    cin >> ki;
    vector<gg> colors(ni);
    while (ki--) {
        unordered_set<gg> us;
        for (gg i = 0; i < ni; ++i) {
            cin >> colors[i];
            us.insert(colors[i]);
        }
        for (auto& e : edges) {
            if (colors[e[0]] == colors[e[1]]) {
                cout << "No\n";
                goto loop;
            }
        }
        cout << us.size() << "-coloring\n";
    loop:;
    }
    return 0;
}
