#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<gg, 10> h{};
    for (gg i = 0; i < 10; ++i)
        cin >> h[i];
    auto k = find_if(h.begin() + 1, h.end(), [](int a) { return a > 0; }) -
             h.begin();
    cout << k;
    --h[k];
    for (gg i = 0; i < 10; ++i) {
        while (h[i]--) {
            cout << i;
        }
    }
    return 0;
}
