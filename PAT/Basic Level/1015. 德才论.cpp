#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Student {
    gg id, de, cai, total, level;
    Student(gg i, gg d, gg c, gg le) : id(i), de(d), cai(c), level(le) {
        total = de + cai;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<Student> students;
    gg ni, li, hi, id, de, cai, level;
    cin >> ni >> li >> hi;
    cout << setfill('0');
    while (ni--) {
        cin >> id >> de >> cai;
        if (de < li or cai < li)
            continue;
        if (de >= hi and cai >= hi) {
            level = 1;
        } else if (de >= hi and cai < hi) {
            level = 2;
        } else if (de < hi and cai < hi and de >= cai) {
            level = 3;
        } else {
            level = 4;
        }
        students.push_back(Student(id, de, cai, level));
    }
    sort(students.begin(), students.end(),
         [](const Student& s1, const Student& s2) {
             return tie(s1.level, s2.total, s2.de, s1.id) <
                    tie(s2.level, s1.total, s1.de, s2.id);
         });
    cout << students.size() << '\n';
    for (auto& s : students) {
        cout << setw(8) << s.id << ' ' << s.de << ' ' << s.cai << '\n';
    }
    return 0;
}
