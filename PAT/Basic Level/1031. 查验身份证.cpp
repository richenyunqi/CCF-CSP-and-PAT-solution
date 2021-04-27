#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    string si;
    gg weight[] = {7, 9, 10, 5,  8, 4, 2, 1, 6,
                   3, 7, 9,  10, 5, 8, 4, 2};  //前17位权重
    string m = "10X98765432";  //模11取余后的字符
    bool pass = true;
    while (ni--) {
        cin >> si;
        bool f = true;  //记录当前身份证是否有问题
        gg sum = 0;
        for (int i = 0; i < 17 and f; ++i) {
            if (not isdigit(si[i])) {
                f = false;
            } else {
                sum += (si[i] - '0') * weight[i];
            }
        }
        if (m[sum % 11] != si.back() or not f) {
            cout << si << '\n';
            pass = false;
        }
    }
    if (pass)
        cout << "All passed";
    return 0;
}
