#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct School {
    string id;  //单位码
    gg num = 0;  //人数
    double total = 0.0;  //总分
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    unordered_map<string, School> um;  //存储学校id和学校信息的映射关系
    while (ni--) {
        string id1, id2;
        double score;
        cin >> id1 >> score >> id2;
        for (char& c : id2)  //讲学校id转换成小写字母
            c = tolower(c);
        um[id2].total += id1[0] == 'T' ?
                             score * 1.5 :
                             id1[0] == 'B' ? score / 1.5 : score * 1.0;
        ++um[id2].num;
        um[id2].id = id2;
    }
    vector<School> schools;
    for (auto& u : um) {
        u.second.total = floor(u.second.total);  //总分向下取整
        schools.push_back(u.second);
    }
    sort(schools.begin(), schools.end(),
         [](const School& s1, const School& s2) {
             return tie(s2.total, s1.num, s1.id) < tie(s1.total, s2.num, s2.id);
         });  //排序
    cout << schools.size() << '\n';
    for (gg i = 0, r = 1; i < schools.size(); ++i) {
        auto& s = schools[i];
        if (i > 0 and s.total != schools[i - 1].total)  //计算排名
            r = i + 1;
        cout << r << ' ' << s.id << ' ' << s.total << ' ' << s.num << '\n';
    }
    return 0;
}
