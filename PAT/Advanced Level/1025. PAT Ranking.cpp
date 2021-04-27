#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Testee {
    string id;
    gg score, num;
    array<gg, 2> rank;
    Testee(string i, gg s, gg n) : id(i), score(s), num(n) {}
};
vector<Testee> ts;
void setRank(gg b, gg e, gg index) {
    sort(
        ts.begin() + b, ts.begin() + e,
        [](const Testee& t1, const Testee& t2) { return t1.score > t2.score; });
    gg r = 1;
    for (gg i = b; i < e; ++i) {
        if (i == b or ts[i].score != ts[i - 1].score) {
            r = i - b + 1;
        }
        ts[i].rank[index] = r;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki;
    cin >> ni;
    for (gg i = 1; i <= ni; ++i) {
        cin >> ki;
        string id;
        gg score, n = ts.size();
        while (ki--) {
            cin >> id >> score;
            ts.push_back(Testee(id, score, i));
        }
        setRank(n, ts.size(), 0);
    }
    setRank(0, ts.size(), 1);
    sort(ts.begin(), ts.end(), [](const Testee& t1, const Testee& t2) {
        return tie(t1.rank[1], t1.id) < tie(t2.rank[1], t2.id);
    });
    cout << ts.size() << "\n";
    for (auto& i : ts) {
        cout << i.id << " " << i.rank[1] << " " << i.num << " " << i.rank[0]
             << "\n";
    }
    return 0;
}
