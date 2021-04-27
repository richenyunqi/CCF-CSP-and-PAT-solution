#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg> decToR(gg n, gg R) {
    vector<gg> ans;
    do {
        ans.push_back(n % R);
        n /= R;
    } while (n != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, bi;
    cin >> ni >> bi;
    auto v = decToR(ni, bi);
    cout << (equal(v.begin(), v.end(), v.rbegin()) ? "Yes" : "No") << "\n";
    for (int i = 0; i < v.size(); ++i) {
        cout << (i == 0 ? "" : " ") << v[i];
    }
    return 0;
}
