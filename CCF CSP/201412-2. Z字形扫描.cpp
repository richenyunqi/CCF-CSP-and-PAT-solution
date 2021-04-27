//模拟
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<vector<gg>> ai(ni, vector<gg>(ni));
    for (auto& i : ai) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    vector<array<gg, 2>> d1 = {{-1, 1}, {1, -1}},  //右上、左下
        d2 = {{0, 1}, {1, 0}};  //右、下
    gg index = 0, x = 0, y = 0;  // index指示目前移动方向的索引，x、y为横纵坐标
    auto outOfBorder = [ni](gg x, gg y) {  //坐标是否越界
        return x < 0 or x >= ni or y < 0 or y >= ni;
    };
    for (gg i = 0; i < ni * ni; ++i) {  //遍历n*n个数字
        cout << ai[x][y] << " ";  //输出当前数字
        //在当前方向上已无法移动
        if (outOfBorder(x + d1[index][0], y + d1[index][1])) {
            auto d = d2[index];  //确定向右还是向下移动一格
            if (outOfBorder(x + d[0], y + d[1])) {
                d = d2[index xor 1];
            }
            x += d[0], y += d[1], index ^= 1;  //更新坐标和移动方向
        } else {  //在当前方向上可以继续移动，那就继续移动
            x += d1[index][0], y += d1[index][1];
        }
    }
    return 0;
}
//扫描线
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<vector<gg>> ai(ni, vector<gg>(ni));
    for (auto& i : ai) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    for (gg i = 0; i < 2 * ni - 1; ++i) {  // 2n-1条扫描线
        array<gg, 2> c =  //初始位置
            i < ni ? array<gg, 2>{i, 0} : array<gg, 2>{ni - 1, i - ni + 1};
        vector<gg> v;  //存储扫描线上的所有数字
        while (c[0] >= 0 and c[0] < ni and c[1] >= 0 and c[1] < ni) {
            v.push_back(ai[c[0]][c[1]]);
            --c[0], ++c[1];
        }
        if (i % 2 == 0) {
            for (gg j : v) {
                cout << j << " ";
            }
        } else {
            for (auto j = v.rbegin(); j != v.rend(); ++j) {
                cout << *j << " ";
            }
        }
    }
    return 0;
}
