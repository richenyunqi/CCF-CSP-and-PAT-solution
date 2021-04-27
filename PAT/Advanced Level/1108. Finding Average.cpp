#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, num = 0;
    cin >> ni;
    string si;
    double sum = 0;
    regex r("[+-]?\\d+(\\.\\d{0,2})?");
    while (ni--) {
        cin >> si;
        if (not regex_match(si, r) or stod(si) > 1000 or stod(si) < -1000) {
            cout << "ERROR: " << si << " is not a legal number\n";
        } else {
            ++num;
            sum += stod(si);
        }
    }
    cout << fixed << setprecision(2);
    if (num == 0) {
        cout << "The average of 0 numbers is Undefined";
    } else if (num == 1) {
        cout << "The average of 1 number is " << sum;
    } else {
        cout << "The average of " << num << " numbers is " << sum / num;
    }
    return 0;
}