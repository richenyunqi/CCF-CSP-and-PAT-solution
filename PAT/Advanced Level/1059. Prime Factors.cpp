#include <bits/stdc++.h>
using namespace std;
using gg = long long;
map<gg, gg> factor;  //质因子按升序排序，这里要使用map
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
void getFactor(gg n) {
    getPrime();
    for (gg i : prime) {
        while (n % i == 0) {
            ++factor[i];
            n /= i;
        }
        if (n == 1)
            break;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    if (ni == 1) {  // N==1时要进行特判断
        cout << "1=1";
        return 0;
    }
    getFactor(ni);
    cout << ni << "=";
    for (auto i = factor.begin(); i != factor.end(); ++i) {
        cout << (i == factor.begin() ? "" : "*") << i->first;
        if (i->second > 1) {
            cout << "^" << i->second;
        }
    }
    return 0;
}
