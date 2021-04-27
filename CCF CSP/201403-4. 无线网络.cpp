#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using coord = array<gg, 2>;  //用维度为2的一维数组存储坐标
gg n, m, k, r;
vector<coord> routers(205);  //存储路由器的坐标
vector<gg> ans;  //存储最终结果
inline bool canReach(const coord& r1, const coord& r2) { return hypot(r1[0] - r2[0], r1[1] - r2[1]) <= r * 1.0; }
int main() {
    cin >> n >> m >> k >> r;
    for (int i = 0; i < n + m; ++i) {
        cin >> routers[i][0] >> routers[i][1];
    }
    queue<array<gg, 3>> q;  // array<gg, 3>分别存储routers下标,经过的路由器个数,经过的增设路由器个数
    vector<bitset<105>> inQueue(205);
    q.push({0, 0, 0});
    inQueue[0][0] = true;
    while (not q.empty()) {
        auto i = q.front();
        q.pop();
        if (i[0] == 1)
            ans.push_back(i[1]);
        const auto& v = routers[i[0]];
        for (int j = 0; j < n + m; ++j) {
            int t = i[2] + (j < n ? 0 : 1);  //到达j号路由器经过的增设路由器数
            if (not inQueue[j][t] and canReach(routers[j], v) and t <= k) {
                q.push({j, i[1] + 1, t});
                inQueue[j][t] = true;
            }
        }
    }
    cout << *min_element(ans.begin(), ans.end()) - 1;
    return 0;
}