#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1005;
struct Edge {
    gg u, v, cost;
    Edge(gg up, gg vp, gg cp) : u(up), v(vp), cost(cp) {}
};
vector<Edge> edges;
vector<gg> ufs(MAX);
gg findRoot(gg x) { return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]); }
gg Kruskal() {
    iota(ufs.begin(), ufs.end(), 0);
    gg sumCost = 0;
    sort(edges.begin(), edges.end(),
         [](const Edge& e1, const Edge& e2) { return e1.cost < e2.cost; });
    for (auto& e : edges) {
        gg ua = findRoot(e.u), ub = findRoot(e.v);
        if (ua != ub) {
            sumCost += e.cost;
            ufs[ua] = ub;
        }
    }
    return sumCost;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    while (mi--) {
        gg ai, bi, ci;
        cin >> ai >> bi >> ci;
        edges.push_back(Edge(ai, bi, ci));
    }
    cout << Kruskal();
    return 0;
}