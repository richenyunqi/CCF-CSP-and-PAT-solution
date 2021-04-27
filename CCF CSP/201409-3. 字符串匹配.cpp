#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    string si;
    cin >> si;
    cin >> mi >> ni;
    regex r(si, mi == 0 ? regex::icase : regex::ECMAScript);
    while (cin >> si) {
        if (regex_search(si, r)) {
            cout << si << "\n";
        }
    }
    return 0;
}
