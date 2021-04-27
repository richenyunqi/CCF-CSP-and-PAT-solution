#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki;
    cin >> ni >> ki;
    vector<vector<gg>> course(ki + 1);
    vector<string> names;
    for (gg i = 0; i < ni; ++i) {
        string si;
        gg ci, ai;
        cin >> si >> ci;
        names.push_back(si);
        while (ci--) {
            cin >> ai;
            course[ai].push_back(i);
        }
    }
    for (gg i = 1; i <= ki; ++i) {
        cout << i << " " << course[i].size() << "\n";
        sort(course[i].begin(), course[i].end(),
             [&names](gg a, gg b) { return names[a] < names[b]; });
        for (auto& s : course[i]) {
            cout << names[s] << "\n";
        }
    }
    return 0;
}