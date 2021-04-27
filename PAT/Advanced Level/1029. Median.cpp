#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<gg> s1(ni);
    for (gg& i : s1) {
        cin >> i;
    }
    cin >> ni;
    vector<gg> s2(ni);
    for (gg& i : s2) {
        cin >> i;
    }
    gg k = (s1.size() + s2.size() + 1) / 2, ans;
    for (gg i = 0, j = 0; k > 0; --k) {
        gg a = i < s1.size() ? s1[i] : INT_MAX,
           b = j < s2.size() ? s2[j] : INT_MAX;
        if (a < b) {
            ans = s1[i++];
        } else {
            ans = s2[j++];
        }
    }
    cout << ans;
    return 0;
}