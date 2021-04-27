#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, t = 0, k = 0, p = -1;
    cin >> ni >> mi;
    for (gg i = 1; i <= ni; ++i) {  //遍历所有苹果树
        gg ai, b = 0, ci;
        cin >> ai;  //疏果之前的苹果个数
        t += ai;
        for (gg j = 0; j < mi; ++j) {  //遍历每一轮的疏果个数
            cin >> ci;
            b += ci;  //累加疏果总数
        }
        t += b;
        if (abs(b) > p) {  //当前苹果树的疏果总数比p大，更新p和k
            k = i;
            p = abs(b);
        }
    }
    cout << t << " " << k << " " << p;
    return 0;
}
