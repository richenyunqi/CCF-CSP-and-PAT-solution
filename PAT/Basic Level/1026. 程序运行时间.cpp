#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ai, bi;
    cin >> ai >> bi;
    ai = round((bi - ai) / 100.0);
    cout << setfill('0') << setw(2) << ai / 3600 << ":" << setw(2)
         << ai / 60 % 60 << ":" << setw(2) << ai % 60;
    return 0;
}
