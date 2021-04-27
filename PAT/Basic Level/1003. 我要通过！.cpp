#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    while (ni--) {
        string si;
        cin >> si;
        unordered_map<char, gg> um;
        for (char c : si) {
            ++um[c];
        }
        gg p = si.find('P'), t = si.find('T');
        if (um.size() == 3 and um['P'] == 1 and um['T'] == 1 and
            um.count('A') > 0 and p < t - 1 and
            p * (t - p - 1) == si.size() - t - 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
