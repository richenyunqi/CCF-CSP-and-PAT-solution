#include <bits/stdc++.h>
using namespace std;
using gg = long long;
bool isPrime(gg n) {
    for (gg i = 2; i <= (gg)sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki;
    string si;
    cin >> ni;
    unordered_map<string, string> um;
    for (gg i = 1; i <= ni; ++i) {
        cin >> si;
        um[si] = i == 1 ? "Mystery Award" : isPrime(i) ? "Minion" : "Chocolate";
    }
    cin >> ki;
    while (ki--) {
        cin >> si;
        cout << si << ": " << (um.count(si) ? um[si] : "Are you kidding?")
             << "\n";
        if (um.count(si)) {
            um[si] = "Checked";
        }
    }
    return 0;
}
