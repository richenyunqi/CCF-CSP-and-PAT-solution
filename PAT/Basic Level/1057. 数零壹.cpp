#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string si;
    getline(cin, si);
    gg sum = accumulate(si.begin(), si.end(), 0, [](gg a, char c) {
        return a + (isalpha(c) ? tolower(c) - 'a' + 1 : 0);
    });
    bitset<32> b(sum);
    cout << (sum == 0 ? 0 : (gg)log2(sum) + 1 - b.count()) << ' ' << b.count();
    return 0;
}
