#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, pi, qi;
    cin >> ni >> mi;
    list<gg> lst;
    for (gg i = 1; i <= ni; ++i) {
        lst.push_back(i);
    }
    while (mi--) {
        cin >> pi >> qi;
        lst.insert(next(lst.erase(find(lst.begin(), lst.end(), pi)), qi), pi);
    }
    for (gg i : lst) {
        cout << i << " ";
    }
    return 0;
}
