#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Person {
    string name;
    gg y, m, d;
    Person(gg yy, gg mm, gg dd, string n = "") : y(yy), m(mm), d(dd), name(n) {}
    bool operator<(const Person& p) const {
        return tie(y, m, d) < tie(p.y, p.m, p.d);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, num = 0;
    cin >> ni;
    Person old(2014, 9, 6), young(1814, 9, 6), b1 = old, b2 = young, t(0, 0, 0);
    while (ni--) {
        char c;
        cin >> t.name >> t.y >> c >> t.m >> c >> t.d;
        if (b1 < t or t < b2)  //注意这里不能使用>，因为我们没有重载>运算符
            continue;
        old = min(old, t);
        young = max(young, t);
        ++num;
    }
    if (num == 0)  //有效生日为0，进行特判
        cout << "0";
    else
        cout << num << ' ' << old.name << ' ' << young.name;
    return 0;
}
