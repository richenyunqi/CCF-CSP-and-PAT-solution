#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg> prime;
void getPrime(gg n = gg(1e5)) {
    vector<bool> f(n + 5);
    for (gg i = 2; i <= n; ++i)
        if (not f[i]) {
            prime.push_back(i);
            for (gg j = i + i; j <= n; j += i)
                f[j] = true;
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ans = 0;
    cin >> ni;
    getPrime(ni);
    for (gg i = 1; i < prime.size(); ++i) {
        if (prime[i] - prime[i - 1] == 2) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
