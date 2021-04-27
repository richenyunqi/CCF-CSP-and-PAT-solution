#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ni, si;
    cin >> mi >> ni >> si;
    vector<string> v(mi + 1);
    for (int i = 1; i < v.size(); ++i)
        cin >> v[i];
    unordered_set<string> us;  //标志一个人已中过奖
    for (int i = si; i < v.size(); i += ni) {
        while (i < v.size() and us.count(v[i]))  //中过奖则顺取下一位
            ++i;
        if (i < v.size()) {
            cout << v[i] << '\n';
            us.insert(v[i]);
        }
    }
    if (us.empty())  //没有人中过奖
        cout << "Keep going...";
    return 0;
}
