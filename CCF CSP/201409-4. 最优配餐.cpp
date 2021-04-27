#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using agg2 = array<gg, 2>;
const gg MAX = 1005;
//相应graph元素值<0、==0、>0分别表示不能通过位置、能通过位置、客户位置
vector<vector<gg>> graph(MAX, vector<gg>(MAX));
vector<vector<bool>> inQueue(MAX, vector<bool>(MAX));
vector<agg2> dire{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};  //四个方向
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ki, di, ai, bi, ci;
    cin >> ni >> mi >> ki >> di;
    queue<agg2> q;
    while (mi--) {
        cin >> ai >> bi;
        q.push({ai, bi});  //将源点入队
        inQueue[ai][bi] = true;
    }
    while (ki--) {
        cin >> ai >> bi >> ci;
        graph[ai][bi] += ci;  //同一个位置可以有多个客户，使用+=，而不是直接赋值
    }
    while (di--) {
        cin >> ai >> bi;
        graph[ai][bi] = -1;  //不能通过的位置置-1
    }
    gg ans = 0;
    for (gg d = 0; not q.empty(); ++d) {
        gg s = q.size();
        for (gg i = 0; i < s; ++i) {
            auto v = q.front();
            q.pop();
            if (graph[v[0]][v[1]] > 0) {
                ans += d * graph[v[0]][v[1]];
            }
            for (auto& i : dire) {
                gg nx = v[0] + i[0], ny = v[1] + i[1];  //下一个到达的位置
                if (nx > 0 and nx <= ni and ny > 0 and ny <= ni and
                    graph[nx][ny] != -1 and not inQueue[nx][ny]) {
                    q.push({nx, ny});
                    inQueue[nx][ny] = true;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
