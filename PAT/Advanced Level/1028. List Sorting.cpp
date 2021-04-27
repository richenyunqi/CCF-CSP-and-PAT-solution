#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Student {
    string id, name;
    gg grade;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ci;
    cin >> ni >> ci;
    vector<Student> v(ni);
    for (gg i = 0; i < ni; ++i) {
        cin >> v[i].id >> v[i].name >> v[i].grade;
    }
    vector<function<bool(const Student&, const Student&)>> f = {
        [](const Student& s1, const Student& s2) { return s1.id < s2.id; },
        [](const Student& s1, const Student& s2) {
            return tie(s1.name, s1.id) < tie(s2.name, s2.id);
        },
        [](const Student& s1, const Student& s2) {
            return tie(s1.grade, s1.id) < tie(s2.grade, s2.id);
        }};
    sort(v.begin(), v.end(), f[ci - 1]);
    for (auto& i : v) {
        cout << i.id << " " << i.name << " " << i.grade << "\n";
    }
    return 0;
}
