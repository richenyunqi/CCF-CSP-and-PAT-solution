#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg red, yellow, green, ni, ki, ti, ans = 0;
    cin >> red >> yellow >> green >> ni;
    while (cin >> ki >> ti) {
        if (ki == 0 or ki == 1) {
            ans += ti;
        } else if (ki == 2) {
            ans += ti + red;
        }
    }
    cout << ans;
    return 0;
}
