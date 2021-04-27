#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    for (gg i = 0; i < ni; ++i) {
        gg g1, a;
        vector<gg> g2;
        cin >> g1;
        for (gg j = 0; j < ni - 1; ++j) {
            cin >> a;
            if (a >= 0 and a <= mi) {  //只统计[0,mi]之内的分数
                g2.push_back(a);
            }
        }
        //找到最高和最低的成绩
        auto m = minmax_element(g2.begin(), g2.end());
        //统计去除最高和最低的成绩后的分数总和
        gg g2a = accumulate(g2.begin(), g2.end(), 0) - *m.first - *m.second;
        //计算最终成绩
        cout << round((g1 + g2a * 1.0 / (g2.size() - 2)) / 2.0) << '\n';
    }
    return 0;
}
