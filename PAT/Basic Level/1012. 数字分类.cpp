#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ti, help = 1;
    cin >> ni;
    gg ans[5]{}, num[5]{};  // ans记录A[1]~A[5]，num记录数字出现次数
    while (ni--) {
        cin >> ti;
        if (ti % 10 == 0) {  // A[1]
            ans[0] += ti;
            ++num[0];
        } else if (ti % 5 == 1) {  // A[2]
            ans[1] += help * ti;
            help *= -1;
            ++num[1];
        } else if (ti % 5 == 2) {  // A[3]
            ++ans[2];
            ++num[2];
        } else if (ti % 5 == 3) {  // A[4]
            ans[3] += ti;
            ++num[3];
        } else if (ti % 5 == 4 and ti > ans[4]) {  // A[5]
            ans[4] = ti;
            ++num[4];
        }
    }
    for (int i = 0; i < 5; ++i) {
        cout << (i == 0 ? "" : " ");
        if (num[i] == 0) {
            cout << 'N';
        } else {
            cout << fixed << setprecision(i == 3 ? 1 : 0)
                 << (i == 3 ? ans[i] * 1.0 / num[i] : ans[i] * 1.0);
        }
    }
    return 0;
}
