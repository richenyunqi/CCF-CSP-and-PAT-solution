#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double r1, r2, p1, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double a = r1 * cos(p1) * r2 * cos(p2) - r1 * sin(p1) * r2 * sin(p2);
    double b = r1 * sin(p1) * r2 * cos(p2) + r1 * cos(p1) * r2 * sin(p2);
    a = a < 0 and a > -0.005 ? 0 : a;
    b = b < 0 and b > -0.005 ? 0 : b;
    cout << fixed << setprecision(2) << a << showpos << b << 'i';
    return 0;
}
