#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, zi;
    cin >> ni;
    while (ni--) {
        cin >> zi;
        string s = to_string(zi);
        gg a = stoll(s.substr(0, s.size() / 2)),
           b = stoll(s.substr(s.size() / 2));
        cout << (a * b != 0 and zi % (a * b) == 0 ? "Yes" : "No") << "\n";
    }
    return 0;
}
