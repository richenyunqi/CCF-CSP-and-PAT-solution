//二分查找
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    vector<gg> v(ni + 1);  //注意v[0]=0
    for (gg i = 1; i <= ni; ++i) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin());  //求前缀和
    gg sum = INT_MAX;
    vector<array<gg, 2>> ans;
    for (gg i = 0; i < v.size(); ++i) {
        gg j = lower_bound(v.begin(), v.end(), v[i] + mi) - v.begin();
        if (j == v.size()) {  //查找不到总和大于等于M的连续数字
            continue;
        }
        gg s = v[j] - v[i];
        if (sum > s) {
            sum = s;
            ans = {{i + 1, j}};
        } else if (s == sum) {
            ans.push_back({i + 1, j});
        }
    }
    for (auto& i : ans) {
        cout << i[0] << "-" << i[1] << "\n";
    }
    return 0;
}
// two pointers
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    vector<gg> v(ni);
    for (gg& i : v) {
        cin >> i;
    }
    gg s = 0, sum = INT_MAX;
    vector<array<gg, 2>> ans;
    for (gg i = 0, j = 0; i < ni and j <= ni;) {
        if (s >= mi) {
            if (sum > s) {
                sum = s;
                ans = {{i + 1, j}};
            } else if (s == sum) {
                ans.push_back({i + 1, j});
            }
            s -= v[i++];
        } else {
            s += v[j++];
        }
    }
    for (auto& i : ans) {
        cout << i[0] << "-" << i[1] << "\n";
    }
    return 0;
}