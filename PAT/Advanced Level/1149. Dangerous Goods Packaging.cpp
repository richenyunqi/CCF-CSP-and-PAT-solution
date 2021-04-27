#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ki, ai, bi;
    cin >> ni >> mi;
    //存储不相容的物品对
    unordered_map<gg, unordered_set<gg>> um;
    while (ni--) {
        cin >> ai >> bi;
        um[ai].insert(bi);
        um[bi].insert(ai);
    }
    while (mi--) {
        cin >> ki;
        unordered_set<gg> us;
        while (ki--) {
            cin >> ai;
            us.insert(ai);
        }
        for (auto i : us) {  //遍历货物清单
            if (um.count(i)) {  //有不相容的物品
                for (auto j : um[i]) {  //遍历不相容的物品
                    if (us.count(j)) {  //不相容的物品在该箱中
                        cout << "No\n";
                        goto loop;
                    }
                }
            }
        }
        cout << "Yes\n";
    loop:;
    }
    return 0;
}
