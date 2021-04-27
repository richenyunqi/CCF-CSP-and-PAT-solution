#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, sum = 0;
    cin >> ni;
    vector<gg> v(ni + 1);  //注意v[0]=0
    for (gg i = 1; i <= ni; ++i) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin());  //求前缀和
    cin >> mi;
    while (mi--) {
        gg ai, bi;
        cin >> ai >> bi;
        gg t = v[max(ai, bi) - 1] - v[min(ai, bi) - 1];
        cout << min(t, v.back() - t) << "\n";
    }
    return 0;
}