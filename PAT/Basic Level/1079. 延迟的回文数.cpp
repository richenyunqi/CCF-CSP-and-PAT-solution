#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string Plus(const string& a, const string& b) {
    string ans;
    gg carry = 0;  //进位
    for (gg i = a.size() - 1, j = b.size() - 1; i >= 0 or j >= 0 or carry != 0; --i, --j) {
        gg p1 = i >= 0 ? a[i] - '0' : 0, p2 = j >= 0 ? b[j] - '0' : 0;
        gg k = p1 + p2 + carry;
        ans.push_back(k % 10 + '0');
        carry = k / 10;
    }
    reverse(ans.begin(), ans.end());  //要进行翻转
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a;
    for (gg i = 0; i < 10; ++i) {
        if (equal(a.begin(), a.end(), a.rbegin())) {  //是回文数
            cout << a << " is a palindromic number.\n";
            return 0;
        }
        b = a;
        reverse(b.begin(), b.end());
        string c = Plus(a, b);
        cout << a << " + " << b << " = " << c << "\n";
        a = c;
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}
