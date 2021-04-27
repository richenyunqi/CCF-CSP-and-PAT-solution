#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<array<gg, 2>> input(gg(1e6), {-1, -1});
    gg start, ni, ki;
    cin >> start >> ni >> ki;
    for (gg i = 0; i < ni; ++i) {
        gg address, data, nextA;
        cin >> address >> data >> nextA;
        input[address] = {data, nextA};
    }
    vector<vector<gg>> lst(3);
    while (start != -1) {
        gg flag = input[start][0] < 0 ? 0 : input[start][0] > ki ? 2 : 1;
        lst[flag].push_back(start);
        start = input[start][1];
    }
    lst[0].insert(lst[0].end(), lst[1].begin(), lst[1].end());
    lst[0].insert(lst[0].end(), lst[2].begin(), lst[2].end());
    cout << setfill('0');
    for (gg i = 0; i < lst[0].size() - 1; ++i) {
        cout << setw(5) << lst[0][i] << " " << input[lst[0][i]][0] << " "
             << setw(5) << lst[0][i + 1] << "\n";
    }
    cout << setw(5) << lst[0].back() << " " << input[lst[0].back()][0]
         << " -1\n";
    return 0;
}
