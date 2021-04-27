#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Edge {  //边的类，存储两个端点u,v和边的权值cost
    gg u, v, cost;
    Edge(gg up, gg vp, gg cp) : u(up), v(vp), cost(cp) {}
};
vector<Edge> edges;  //存储所有的边
vector<gg> ufs(1e5 + 5);  //并查集
gg findRoot(gg x) { return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]); }
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
    iota(ufs.begin(), ufs.end(), 0);
    gg cost = 0;  //存储最长边的长度
    sort(edges.begin(), edges.end(),
         [](const Edge& e1, const Edge& e2) { return e1.cost < e2.cost; });
    for (gg i = 0; i < edges.size() and findRoot(1) != findRoot(ni); ++i) {
        gg ua = findRoot(edges[i].u), ub = findRoot(edges[i].v);
        if (ua != ub) {
            cost = max(cost, edges[i].cost);  //更新最长边
            ufs[ua] = ub;
        }
    }
    cout << cost;
    return 0;
}