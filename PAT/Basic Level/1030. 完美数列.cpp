//二分查找
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, pi, ans = 0;
    cin >> ni >> pi;
    vector<gg> v(ni);
    for (gg i = 0; i < ni; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (gg i = 0; i < ni; ++i) {
        ans = max(ans,
                  upper_bound(v.begin(), v.end(), v[i] * pi) - v.begin() - i);
    }
    cout << ans;
    return 0;
}
// two pointers
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, pi, ans = 0;
    cin >> ni >> pi;
    vector<gg> v(ni);
    for (gg i = 0; i < ni; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (gg i = 0, j = 0; j < v.size(); ++i) {
        while (j < v.size() and v[j] <= v[i] * pi) {
            ++j;
        }
        ans = max(ans, j - i);
    }
    cout << ans;
    return 0;
}
