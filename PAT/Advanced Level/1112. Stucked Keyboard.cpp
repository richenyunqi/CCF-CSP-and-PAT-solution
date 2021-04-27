#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ki;
    string si;
    cin >> ki >> si;
    array<gg, 128> h{};
    for (gg i = 0; i < si.size();) {
        if (h[si[i]] != -1) {  //无需检测已确定不是坏键的字符
            gg j = si.find_first_not_of(si[i], i + 1);
            if (j == -1) {
                j = si.size();
            }
            h[si[i]] = (j - i) % ki != 0 ? -1 : 1;  //检测重复次数是否为K的倍数
            i = j;
        } else {
            ++i;
        }
    }
    string ans;
    for (gg i = 0; i < si.size();) {
        ans.push_back(si[i]);
        if (h[si[i]] == -1) {
            ++i;
            continue;
        }
        if (h[si[i]] == 1) {  //是坏键且未输出过
            cout << si[i];
            h[si[i]] = 2;
        }
        i += ki;
    }
    cout << "\n" << ans;
    return 0;
}
