#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    vector<vector<array<gg, 2>>> points(2);
    gg xi, yi, ai, bi, ci;
    string typei;
    while (ni--) {
        cin >> xi >> yi >> typei;
        points[typei[0] - 'A'].push_back({xi, yi});
    }
    while (mi--) {
        cin >> ai >> bi >> ci;
        for (auto& p : points) {
            for (gg i = 1; i < p.size(); ++i) {
                if ((ai + bi * p[i][0] + ci * p[i][1] > 0) ^ (ai + bi * p[0][0] + ci * p[0][1] > 0)) {
                    cout << "No\n";
                    goto loop;
                }
            }
        }
        cout << "Yes\n";
    loop:;
    }
    return 0;
}
