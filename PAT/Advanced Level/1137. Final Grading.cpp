#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Student {  //学生类，成绩均初始化为-1
    string id;
    // p,m,f,total分别为编程作业分、期中成绩、期末成绩、总评成绩
    gg p = -1, m = -1, f = -1, total = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg pi, mi, ni, grade;
    cin >> pi >> mi >> ni;
    string id;
    unordered_map<string, Student> um;  //存储学生id到学生成绩的映射
    for (int i = 0; i < pi; ++i) {
        cin >> id >> grade;
        if (grade >= 200) {  //只统计编程作业分>=200的学生
            um[id].p = grade;
        }
    }
    for (int i = 0; i < mi + ni; ++i) {
        cin >> id >> grade;
        if (um.count(id)) {  // um中包含该学生id,说明该学生编程作业分>=200
            i < mi ? um[id].m = grade : um[id].f = grade;
        }
    }
    vector<Student> v;
    for (auto& u : um) {  //将编程作业分>=200的学生迁移至vector中
        auto& s = u.second;
        //计算总评成绩
        s.total = round(s.m > s.f ? s.m * 0.4 + s.f * 0.6 : s.f * 1.0);
        if (s.total >= 60) {  //只统计总评成绩>=60的学生
            v.push_back(u.second);
            v.back().id = u.first;
        }
    }
    //按总评成绩从高到低、学号从小到大的顺序排序
    sort(v.begin(), v.end(), [](const Student& s1, const Student& s2) {
        return tie(s2.total, s1.id) < tie(s1.total, s2.id);
    });
    for (auto& s : v) {  //输出
        cout << s.id << ' ' << s.p << ' ' << s.m << ' ' << s.f << ' ' << s.total
             << '\n';
    }
    return 0;
}
