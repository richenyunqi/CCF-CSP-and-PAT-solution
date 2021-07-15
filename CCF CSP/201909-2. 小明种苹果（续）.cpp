#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, t = 0, d = 0, e = 0;
    cin >> ni;
    vector<bool> f(ni);  //存储果树是否有苹果掉落
    for (gg i = 0; i < ni; ++i) {
        gg ai, bi;
        cin >> mi >> ai;
        while (--mi) {
            cin >> bi;
            if (bi <= 0) {  //进行疏果操作
                ai += bi;
            } else {
                if (ai > bi)  //有苹果掉落
                    f[i] = true;
                ai = bi;
            }
        }
        t += ai;  //存储最终的总苹果数
    }
    d = count(f.begin(), f.end(), true);  //计算有多少棵果树有苹果掉落
    for (gg i = 0; i < ni; ++i) {  //统计连续3棵苹果树有苹果掉落的组数
        if (f[i] and f[(i + 1) % ni] and f[(i + 2) % ni])
            ++e;
    }
    cout << t << " " << d << " " << e;
    return 0;
}
