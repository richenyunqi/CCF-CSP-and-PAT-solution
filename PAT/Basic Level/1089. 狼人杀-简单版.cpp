#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<gg> input(ni + 1);
    for (gg i = 1; i <= ni; ++i) {
        cin >> input[i];
    }
    for (gg i = 1; i <= ni; ++i) {  // i号玩家是狼人
        for (gg j = i + 1; j <= ni; ++j) {  // j号玩家是狼人
            gg lier = 0, wolflier = 0;
            for (gg k = 1; k <= ni; ++k) {
                if (input[k] > 0 xor (abs(input[k]) != i and
                                      abs(input[k]) != j)) {  // k号玩家在撒谎
                    ++lier;
                    if (k == i or k == j) {  //狼人在撒谎
                        ++wolflier;
                    }
                }
            }
            if (lier == 2 and wolflier == 1) {  //找到了一组解
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}