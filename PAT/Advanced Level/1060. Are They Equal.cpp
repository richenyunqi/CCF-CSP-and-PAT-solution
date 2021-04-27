#include <bits/stdc++.h>
using namespace std;
using gg = long long;
//返回n位有效数字和指数
pair<string, gg> f(const string& s, gg n) {
    string ans;
    gg i = find_if(s.begin(), s.end(),
                   [](char c) { return isdigit(c) and c != '0'; }) -
           s.begin();  //查找第一位非0数字的位置
    if (i == s.size()) {  //输入的数字都是0，说明这个数字的值就是0
        return {string(n, '0'), 0};
    }
    for (gg j = i; j < s.size(); ++j) {  //将最多n位有效数字放入ans中
        if (ans.size() < n and isdigit(s[j])) {
            ans.push_back(s[j]);
        }
    }
    ans += string(n - ans.size(), '0');  //有效数字不足n位，末位补0
    gg num = s.find('.');  //小数点的位置
    if (num == -1) {
        num = s.size();
    }
    //如果num-i是负数，指数是num-i+1，否则为num-i
    return {ans, num - i > 0 ? num - i : num - i + 1};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    gg ni;
    cin >> ni >> s1 >> s2;
    auto ans1 = f(s1, ni), ans2 = f(s2, ni);
    if (ans1 == ans2) {
        cout << "YES 0." << ans1.first << "*10^" << ans1.second << "\n";
    } else {
        cout << "NO 0." << ans1.first << "*10^" << ans1.second << " 0."
             << ans2.first << "*10^" << ans2.second << "\n";
    }
    return 0;
}