#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<gg, gg> um;  //记录配偶ID
    gg ni, ai, bi;
    cin >> ni;
    while (ni--) {
        cin >> ai >> bi;
        um[ai] = bi;
        um[bi] = ai;
    }
    cin >> ni;
    set<gg> s;  //记录是否出现在派对上并排序
    while (ni--) {
        cin >> ai;
        if (not um.count(ai) or not s.count(um[ai])) {
            s.insert(ai);
        } else {
            s.erase(um[ai]);
        }
    }
    cout << s.size() << '\n' << setfill('0');
    for (auto i = s.begin(); i != s.end(); ++i) {
        cout << (i == s.begin() ? "" : " ") << setw(5) << *i;
    }
    return 0;
}
