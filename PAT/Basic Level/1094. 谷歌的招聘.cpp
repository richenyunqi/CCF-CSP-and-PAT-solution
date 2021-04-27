#include <bits/stdc++.h>
using namespace std;
using gg = long long;
bool isPrime(gg n) {
    if (n < 2)  // n小于2，一定不是素数
        return false;
    for (gg i = 2; i <= (gg)sqrt(n); ++i)  //遍历2~根号n所有的数
        if (n % i == 0)  // n能被i整除，说明n不是素数
            return false;
    return true;  // n不能被2~n任何数整除，则n是素数
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg li, ki;
    string s;
    cin >> li >> ki >> s;
    for (int i = 0; i < s.size() - ki + 1; ++i) {
        string n = s.substr(i, ki);
        if (isPrime(stoll(n))) {
            cout << n;
            return 0;
        }
    }
    cout << "404";
    return 0;
}
