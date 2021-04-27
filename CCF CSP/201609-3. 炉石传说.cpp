#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<vector<array<gg, 2>>> player{{{30, 0}}, {{30, 0}}};
    gg cur = 0;
    while (ni--) {
        string si;
        gg ai, bi, ci;
        cin >> si;
        if (si == "summon") {
            cin >> ai >> bi >> ci;
            player[cur].insert(player[cur].begin() + ai, {ci, bi});
        } else if (si == "attack") {
            cin >> ai >> bi;
            player[cur][ai][0] -= player[cur ^ 1][bi][1];
            player[cur ^ 1][bi][0] -= player[cur][ai][1];
            if (player[cur][ai][0] <= 0 and ai > 0) {
                player[cur].erase(player[cur].begin() + ai);
            }
            if (player[cur ^ 1][bi][0] <= 0 and bi > 0) {
                player[cur ^ 1].erase(player[cur ^ 1].begin() + bi);
            }
        } else {
            cur ^= 1;
        }
    }
    cout << (player[0][0][0] > 0 and player[1][0][0] > 0 ?
                 0 :
                 player[0][0][0] > 0 ? 1 : -1)
         << "\n";
    for (auto& i : player) {
        cout << i[0][0] << "\n" << i.size() - 1;
        for (gg j = 1; j < i.size(); ++j) {
            cout << " " << i[j][0];
        }
        cout << "\n";
    }
    return 0;
}