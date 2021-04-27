#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setfill('0');
    gg ni, mi, ai, bi, ri, ki;
    cin >> mi >> ni >> ai >> bi >> ri;
    for (auto i = 0; i < mi; ++i) {
        for (auto j = 0; j < ni; ++j) {
            cin >> ki;
            ki = ki >= ai and ki <= bi ? ri : ki;
            cout << setw(3) << ki << (j == ni - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
