#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1e4 + 5;
vector<gg> ufs(MAX), num(MAX);
void init() { iota(ufs.begin(), ufs.end(), 0); }
gg findRoot(gg x) { return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]); }
void unionSets(gg a, gg b) { ufs[findRoot(a)] = findRoot(b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki, ai, bi, treeNum = 0, birdNum = 0;
    cin >> ni;
    init();
    while (ni--) {
        cin >> ki >> ai;
        birdNum = max(birdNum, ai);
        while (--ki) {
            cin >> bi;
            unionSets(ai, bi);
            birdNum = max(birdNum, bi);
        }
    }
    for (gg i = 1; i <= birdNum; ++i) {
        if (i == ufs[i]) {
            ++treeNum;
        }
    }
    cout << treeNum << " " << birdNum << "\n";
    cin >> ki;
    while (ki--) {
        cin >> ai >> bi;
        cout << (findRoot(ai) == findRoot(bi) ? "Yes" : "No") << "\n";
    }
    return 0;
}
