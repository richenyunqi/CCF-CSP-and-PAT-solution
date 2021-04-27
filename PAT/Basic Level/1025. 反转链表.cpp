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
    vector<gg> lst;
    while (start != -1) {
        lst.push_back(start);
        start = input[start][1];
    }
    for (gg i = ki; i <= lst.size(); i += ki) {
        reverse(lst.begin() + i - ki, lst.begin() + i);
    }
    cout << setfill('0');
    for (gg i = 0; i < lst.size() - 1; ++i) {
        cout << setw(5) << lst[i] << " " << input[lst[i]][0] << " " << setw(5)
             << lst[i + 1] << "\n";
    }
    cout << setw(5) << lst.back() << " " << input[lst.back()][0] << " -1\n";
    return 0;
}
