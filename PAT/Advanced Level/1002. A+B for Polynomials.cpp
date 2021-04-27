#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<gg, double, greater<gg>> um;  //按键从高到低排序
    gg ki, ai;
    double bi;
    cin >> ki;
    while (ki--) {
        cin >> ai >> bi;
        um[ai] += bi;
    }
    cin >> ki;
    while (ki--) {
        cin >> ai >> bi;
        um[ai] += bi;
        if (um[ai] == 0) {  //删除系数为零的项
            um.erase(ai);
        }
    }
    if (um.empty()) {  //如果所有项系数均为0，只输出一个零即可
        cout << "0";
        return 0;
    }
    cout << fixed << setprecision(1);  //浮点数保留一位小数
    cout << um.size();
    for (auto& i : um) {
        cout << " " << i.first << " " << i.second;
    }
    return 0;
}
