#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setfill('0');
    gg ni;
    cin >> ni;
    do {
        string s = to_string(ni);
        while (s.size() < 4)
            s.push_back('0');
        sort(s.begin(), s.end());
        gg a = stoll(s);
        sort(s.begin(), s.end(), greater<char>());
        gg b = stoll(s);
        ni = b - a;
        cout << setw(4) << b << " - " << setw(4) << a << " = " << setw(4) << ni
             << '\n';
    } while (ni != 0 and ni != 6174);
    return 0;
}
