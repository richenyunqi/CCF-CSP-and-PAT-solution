#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1005;
gg ni, mi;
vector<vector<gg>> graph(MAX);
vector<vector<bool>> know(MAX, vector<bool>(MAX));
vector<bool> visit(MAX);
void dfs(gg v, gg s) {
    visit[v] = true;
    know[s][v] = know[v][s] = true;
    for (gg i : graph[v]) {
        if (not visit[i]) {
            dfs(i, s);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni >> mi;
    while (mi--) {
        gg ai, bi;
        cin >> ai >> bi;
        graph[ai].push_back(bi);
    }
    for (gg i = 1; i <= ni; ++i) {
        fill(visit.begin() + 1, visit.begin() + ni + 1, false);
        dfs(i, i);
    }
    gg ans = 0;
    for (gg i = 1; i <= ni; ++i) {
        if (count(know[i].begin() + 1, know[i].begin() + ni + 1, true) == ni) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}