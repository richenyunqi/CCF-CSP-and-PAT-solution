#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int sum = accumulate(s.begin(), s.end(), 0,
                         [](int a, char c) { return a + c - '0'; });
    s = to_string(sum);
    array<string, 10> p{"ling", "yi",  "er", "san", "si",
                        "wu",   "liu", "qi", "ba",  "jiu"};
    for (int i = 0; i < s.size(); ++i) {
        cout << (i > 0 ? " " : "") << p[s[i] - '0'];
    }
    return 0;
}
