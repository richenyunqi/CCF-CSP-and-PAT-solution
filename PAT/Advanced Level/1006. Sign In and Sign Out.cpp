#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Person {
    string name, in, out;
    Person(string n = "", string i = "99:99:99", string o = "00:00:00") :
        name(n), in(i), out(o) {}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Person in, out, temp;
    gg mi;
    cin >> mi;
    while (mi--) {
        cin >> temp.name >> temp.in >> temp.out;
        if (temp.in < in.in) {
            in = temp;
        }
        if (temp.out > out.out) {
            out = temp;
        }
    }
    cout << in.name << " " << out.name;
    return 0;
}
