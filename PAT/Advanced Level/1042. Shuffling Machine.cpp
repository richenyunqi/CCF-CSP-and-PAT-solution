#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<gg> ans(54), order(54);
    gg times;
    cin >> times;
    for (int i = 0; i < 54; ++i) {
        cin >> order[i];
    }
    iota(ans.begin(), ans.end(), 0);  //用0-53这54个整数初始化ans
    while (times--) {  //混洗times次
        vector<gg> temp(54);  //存储临时结果
        for (gg i = 0; i < 54; ++i) {
            temp[order[i] - 1] = ans[i];
        }
        ans = temp;  //存入ans中
    }
    string s = "SHCDJ";
    for (int i = 0; i < 54; ++i) {  //输出最终结果
        cout << (i > 0 ? " " : "") << s[ans[i] / 13] << ans[i] % 13 + 1;
    }
    return 0;
}
