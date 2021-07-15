#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg yi, di;
    cin >> yi >> di;
    //存储每个月的天数
    array<gg, 13> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (yi % 400 == 0 or (yi % 100 != 0 and yi % 4 == 0))  //闰年2月有29天
        month[2] = 29;
    gg i = 0;
    while (di > month[++i])
        di -= month[i];
    cout << i << '\n' << di;
    return 0;
}
