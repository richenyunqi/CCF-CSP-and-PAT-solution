#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<bool> h(128);
    for (char c : s1)
        h[tolower(c)] = true;
    for (char c : s2) {
        if (h[tolower(c)] or (isupper(c) and h['+']))
            continue;
        cout << c;
    }
    return 0;
}
