#include <bits/stdc++.h>
using namespace std;
using gg = long long;
using Record = pair<gg, string>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki;
    cin >> ni >> ki;
    string id, status;
    gg h, m, s;
    char c;
    unordered_map<string, vector<Record>> allRecords;
    for (gg i = 0; i < ni; ++i) {
        cin >> id >> h >> c >> m >> c >> s >> status;
        allRecords[id].push_back({h * 60 * 60 + m * 60 + s, status});
    }
    gg maxTime = 0;
    set<string> ids;
    vector<Record> validRecords;
    for (auto& record : allRecords) {
        id = record.first;
        auto& r = record.second;
        sort(r.begin(), r.end());
        gg t = 0;
        for (gg i = 1; i < r.size(); ++i) {
            if (r[i].second == "out" and r[i - 1].second == "in") {
                validRecords.push_back(r[i - 1]);
                validRecords.push_back(r[i]);
                t += r[i].first - r[i - 1].first;
            }
        }
        if (t > maxTime) {
            ids.clear();
            ids.insert(id);
            maxTime = t;
        } else if (t == maxTime) {
            ids.insert(id);
        }
    }
    sort(validRecords.begin(), validRecords.end());
    gg ans = 0, i = 0;
    while (ki--) {
        cin >> h >> c >> m >> c >> s;
        gg t = h * 60 * 60 + m * 60 + s;
        while (i < validRecords.size() and validRecords[i].first <= t) {
            validRecords[i].second == "in" ? ++ans : --ans;
            ++i;
        }
        cout << ans << "\n";
    }
    for (auto id : ids) {
        cout << id << " ";
    }
    cout << setfill('0') << setw(2) << maxTime / 3600 << ":" << setw(2)
         << maxTime % 3600 / 60 << ":" << setw(2) << maxTime % 60;
    return 0;
}
