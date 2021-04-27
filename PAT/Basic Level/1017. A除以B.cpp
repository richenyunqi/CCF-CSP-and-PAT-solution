#include <bits/stdc++.h>
using namespace std;
using gg = long long;
//默认a为非负整数，b为正整数
pair<string, gg> DivMod(const string& a, gg b) {
    string ans;  //商
    gg mod = 0;  //余数
    for (char c : a) {
        mod = c - '0' + mod * 10;
        ans.push_back(mod / b + '0');
        mod %= b;
    }
    ans.erase(0, ans.find_first_not_of('0'));
    return {ans.empty() ? "0" : ans, mod};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    gg b;
    cin >> a >> b;
    auto ans = DivMod(a, b);
    cout << ans.first << " " << ans.second;
    return 0;
}
