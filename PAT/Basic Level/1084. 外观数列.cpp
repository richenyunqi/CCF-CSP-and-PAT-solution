#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string si;
    gg ni;
    cin >> si >> ni;
    while (--ni) {
        string t;
        for (gg i = 0, j; i < si.size(); i = j) {
            j = si.find_first_not_of(si[i], i + 1);
            if (j == -1)
                j = si.size();
            t += string(1, si[i]) + to_string(j - i);
        }
        si = t;
    }
    cout << si;
    return 0;
}
