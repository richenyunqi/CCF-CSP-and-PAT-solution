#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    set<gg> s;
    cin >> ni;
    while (ni--) {
        gg sum = 0, ai;
        cin >> ai;
        do {
            sum += ai % 10;
            ai /= 10;
        } while (ai != 0);
        s.insert(sum);
    }
    cout << s.size() << '\n';
    for (auto i = s.begin(); i != s.end(); ++i) {
        cout << (i == s.begin() ? "" : " ") << *i;
    }
    return 0;
}
