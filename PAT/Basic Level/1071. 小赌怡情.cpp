#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ti, ki, n1, b, t, n2;
    cin >> ti >> ki;
    while (ki--) {
        cin >> n1 >> b >> t >> n2;
        if (t > ti) {
            cout << "Not enough tokens.  Total = " << ti
                 << ".\n";
        } else {
            if ((b == 0 and n1 > n2) or (b == 1 and n1 < n2)) {
                ti += t;
                cout << "Win " << t << "!  Total = " << ti
                     << ".\n";
            } else {
                ti -= t;
                cout << "Lose " << t << ".  Total = " << ti
                     << ".\n";
                if (ti == 0) {
                    cout << "Game Over.\n";
                    break;
                }
            }
        }
    }
    return 0;
}
