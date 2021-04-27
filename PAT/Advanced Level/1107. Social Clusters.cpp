#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1e3 + 5;
vector<gg> ufs(MAX), num(MAX);
void init() { iota(ufs.begin(), ufs.end(), 0); }
gg findRoot(gg x) { return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]); }
void unionSets(gg a, gg b) { ufs[findRoot(a)] = findRoot(b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki, ai;
    char c;
    cin >> ni;
    unordered_map<gg, gg> hobby;
    init();
    for (gg i = 1; i <= ni; ++i) {
        cin >> ki >> c;
        while (ki--) {
            cin >> ai;
            if (hobby.count(ai)) {
                unionSets(hobby[ai], i);
            } else {
                hobby[ai] = i;
            }
        }
    }
    for (gg i = 1; i <= ni; ++i) {
        num[findRoot(i)]++;
    }
    sort(num.begin(), num.begin() + ni + 2, greater<gg>());
    gg n = find(num.begin(), num.begin() + ni + 2, 0) - num.begin();
    cout << n << "\n";
    for (gg i = 0; i < n; ++i) {
        cout << (i == 0 ? "" : " ") << num[i];
    }
    return 0;
}
