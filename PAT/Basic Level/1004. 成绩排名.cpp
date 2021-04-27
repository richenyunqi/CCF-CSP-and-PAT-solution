#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Student {
    string name, number;
    gg score;
    Student(gg s = 0) : score(s) {}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    Student Max(-1), Min(101), temp;  // Max初始成绩为-1，Min初试成绩为101
    for (gg i = 0; i < ni; ++i) {
        cin >> temp.name >> temp.number >> temp.score;
        if (Max.score < temp.score)
            Max = temp;
        if (Min.score > temp.score)
            Min = temp;
    }
    cout << Max.name << " " << Max.number << "\n"
         << Min.name << " " << Min.number;
    return 0;
}
