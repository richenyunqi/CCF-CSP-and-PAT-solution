#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1050;
using agg2 = array<gg, 2>;
struct Edge {
    gg to, cost;
    Edge(gg t, gg c) : to(t), cost(c) {}
};
vector<vector<Edge>> graph(MAX);
vector<gg> dis(MAX);
gg ni, mi, ki, di;
gg getNum(const string& s) {  //将Gi加油站映射为N+i号结点
    return s[0] == 'G' ? stoll(s.substr(1)) + ni : stoll(s);
}
void Dijkstra(gg s) {
    fill(dis.begin(), dis.end(), INT_MAX);
    priority_queue<agg2, vector<agg2>, greater<agg2>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (dis[p[1]] != p[0]) {
            continue;
        }
        for (auto& e : graph[p[1]]) {
            if (dis[e.to] > p[0] + e.cost) {
                dis[e.to] = p[0] + e.cost;
                pq.push({dis[e.to], e.to});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni >> mi >> ki >> di;
    while (ki--) {
        string s1, s2;
        gg ci;
        cin >> s1 >> s2 >> ci;
        gg k1 = getNum(s1), k2 = getNum(s2);
        graph[k1].push_back(Edge(k2, ci));
        graph[k2].push_back(Edge(k1, ci));
    }
    gg ans = -1, mind = 0;
    double avgd = INT_MAX;
    for (gg i = 1; i <= mi; ++i) {
        Dijkstra(ni + i);
        //计算最近距离、最远距离、平均距离
        gg curmind = *min_element(dis.begin() + 1, dis.begin() + ni + 1),
           curmaxd = *max_element(dis.begin() + 1, dis.begin() + ni + 1);
        double curavgd =
            accumulate(dis.begin() + 1, dis.begin() + ni + 1, 0) * 1.0 / ni;
        //更新相关信息
        if (curmaxd <= di and
            (curmind > mind or (curmind == mind and curavgd < avgd))) {
            ans = i;
            mind = curmind;
            avgd = curavgd;
        }
    }
    if (ans == -1) {
        cout << "No Solution";
    } else {
        cout << "G" << ans << "\n"
             << fixed << setprecision(1) << mind * 1.0 << " " << setprecision(1)
             << avgd;
    }
    return 0;
}
