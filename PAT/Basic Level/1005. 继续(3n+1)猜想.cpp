#include <bits/stdc++.h>
using namespace std;
using gg = long long;  //类型别名
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ai;
    unordered_set<gg> us;  //存储被覆盖的数
    cin >> ni;
    vector<gg> v;
    while (ni--) {
        cin >> ai;
        v.push_back(ai);
        while (ai != 1) {
            if (ai % 2 == 1)
                ai = ai * 3 + 1;
            ai /= 2;
            us.insert(ai);
        }
    }
    sort(v.begin(), v.end(), greater<gg>());  //从大到小排序
    bool first = true;  //标志是否是第一个输出的数字，控制输出空格
    for (auto i : v) {
        if (not us.count(i)) {  // i是关键数
            cout << (first ? "" : " ") << i;
            first = false;
        }
    }
    return 0;
}
