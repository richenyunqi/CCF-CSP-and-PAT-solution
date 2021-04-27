#include <bits/stdc++.h>
using namespace std;
using gg = long long;
pair<string, gg> split(const string& s) {
    gg i = s.find(':');
    return make_pair(s.substr(0, i), i == -1 ? -1 : stoll(s.substr(i + 1)));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg pi, ri, ui, qi, ki;
    string s1, s2;
    cin >> pi;
    unordered_map<string, gg> privileges;
    while (pi--) {
        cin >> s1;
        privileges.insert(split(s1));
    }
    cin >> ri;
    unordered_map<string, unordered_map<string, gg>> roles, users;
    while (ri--) {
        cin >> s1 >> ki;
        while (ki--) {
            cin >> s2;
            auto p = split(s2);
            if (not roles[s1].count(p.first)) {
                roles[s1][p.first] = min(p.second, privileges[p.first]);
            } else if (p.second > roles[s1][p.first]) {
                roles[s1][p.first] = min(privileges[p.first], p.second);
            }
        }
    }
    cin >> ui;
    while (ui--) {
        cin >> s1 >> ki;
        while (ki--) {
            cin >> s2;
            for (auto& p : roles[s2]) {
                if (not users[s1].count(p.first)) {
                    users[s1].insert(p);
                } else if (p.second > users[s1][p.first]) {
                    users[s1][p.first] = p.second;
                }
            }
        }
    }
    cin >> qi;
    while (qi--) {
        cin >> s1 >> s2;
        auto p = split(s2);
        if (not users.count(s1) or not users[s1].count(p.first) or
            p.second > users[s1][p.first]) {
            cout << "false\n";
        } else if (users[s1][p.first] != -1 and p.second == -1) {
            cout << users[s1][p.first] << "\n";
        } else {
            cout << "true\n";
        }
    }
    return 0;
}