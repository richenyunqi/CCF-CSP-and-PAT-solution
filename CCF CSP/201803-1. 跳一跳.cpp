#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // ai存储输入数据，ans为最终得分，num为连跳方块中心次数
    gg ai = 1, ans = 0, num = 0;
    while (cin >> ai and ai != 0) {
        if (ai == 1) {
            ans += ai;  //加上1分
            num = 0;  //连跳方块中心次数归零
        } else if (ai == 2) {
            ans += 2 * (++num);  //递增连跳方块中心次数，得分为该次数乘2
        }
    }
    cout << ans;
    return 0;
}
