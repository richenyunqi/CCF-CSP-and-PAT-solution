#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, li, ti;
    cin >> ni >> li >> ti;
    vector<array<int, 2>> balls(ni);
    for (gg i = 0; i < ni; ++i) {
        cin >> balls[i][0];  //记录小球初始位置
        balls[i][1] = 1;  //默认向右运动
    }
    while (ti--) {  //模拟t秒的运动
        unordered_map<gg, gg> um;  //哈希表，记录小球运动到的位置
        for (gg j = 0; j < balls.size(); ++j) {  //遍历所有小球
            auto& i = balls[j];
            i[0] += i[1];  //运动到下一秒的位置
            if (i[0] == 0 or i[0] == li) {  //运动到端点，更改方向
                i[1] = -i[1];
            } else if (um.count(i[0])) {  //与小球碰撞
                i[1] = -i[1];
                balls[um[i[0]]][1] = -balls[um[i[0]]][1];
            }
            um[i[0]] = j;
        }
    }
    for (auto& i : balls) {
        cout << i[0] << " ";
    }
    return 0;
}
