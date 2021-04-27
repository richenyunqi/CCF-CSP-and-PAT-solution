#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 505;
vector<vector<gg>> graph(505);
vector<bool> visit(505);
void dfs(gg v) {
    visit[v] = true;
    for (gg i : graph[v]) {
        if (not visit[i]) {
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    while (mi--) {
        gg ai, bi;
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }
    dfs(1);
    gg vis = count(visit.begin() + 1, visit.begin() + ni + 1, false),
       num = count_if(graph.begin() + 1, graph.begin() + ni + 1,
                      [](vector<gg>&a) { return a.size() % 2 == 1; });
    for (gg i = 1; i <= ni; ++i) {
        cout << graph[i].size() << (i == ni ? "\n" : " ");
    }
    cout << (vis != 0 or (num != 0 and num != 2) ?
                 "Non-Eulerian" :
                 num == 0 ? "Eulerian" : "Semi-Eulerian");
    return 0;
}