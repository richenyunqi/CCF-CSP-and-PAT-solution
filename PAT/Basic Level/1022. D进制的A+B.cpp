#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg> decToR(gg n, gg R) {
    vector<gg> ans;  //存储R进制数
    do {
        ans.push_back(n % R);  //取余
        n /= R;  //除基
    } while (n != 0);  // n==0时跳出循环
    reverse(ans.begin(), ans.end());  //翻转整个数组
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ai, bi, di;
    cin >> ai >> bi >> di;
    ai += bi;
    for (auto i : decToR(ai, di))
        cout << i;
    return 0;
}
