#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<gg, (gg)1e5 + 5> h{};
    gg n;
    cin >> n;
    while (n--) {
        gg a, b;
        cin >> a >> b;
        h[a] += b;
    }
    auto i = max_element(h.begin(), h.end());
    cout << (i - h.begin()) << ' ' << *i;
    return 0;
}
