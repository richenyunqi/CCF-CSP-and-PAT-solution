#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    vector<pair<regex, string>> rules;
    string si, pi;
    for (gg i = 0; i < ni; ++i) {
        cin >> si >> pi;
        si = regex_replace(si, regex("<int>"), "(\\d+)");
        si = regex_replace(si, regex("<str>"), "([^/]+)");
        si = regex_replace(si, regex("<path>"), "(.+)");
        rules.push_back({regex(si), pi});
    }
    smatch result;
    while (mi--) {
        cin >> si;
        for (auto& i : rules) {
            if (regex_match(si, result, i.first)) {
                cout << i.second;
                for (gg j = 1; j < result.size(); ++j) {
                    regex_match(result.str(j), regex("\\d+")) ?
                        cout << " " << stoll(result.str(j)) :
                        cout << " " << result[j];
                }
                cout << "\n";
                goto loop;
            }
        }
        cout << "404\n";
    loop:;
    }
    return 0;
}