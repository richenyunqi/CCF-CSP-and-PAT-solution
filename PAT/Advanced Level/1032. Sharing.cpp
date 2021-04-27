#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<string, gg>> input(gg(1e6));
    gg start1, start2, ni;
    cin >> start1 >> start2 >> ni;
    for (gg i = 0; i < ni; ++i) {
        gg address, nextA;
        string data;
        cin >> address >> data >> nextA;
        input[address] = {data, nextA};
    }
    unordered_set<gg> us;
    while (start1 != -1) {
        us.insert(start1);
        start1 = input[start1].second;
    }
    while (start2 != -1) {
        if (us.count(start2)) {
            cout << setfill('0') << setw(5) << start2;
            return 0;
        }
        start2 = input[start2].second;
    }
    cout << "-1";
    return 0;
}
