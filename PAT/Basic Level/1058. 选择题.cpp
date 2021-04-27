#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Problem {
    gg score, num;  //题目分数、错误人数
    string choice;  //正确选项
    Problem(gg s) : score(s), num(0), choice("") {}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<Problem> problems;
    gg n, m, a, b, c;
    cin >> n >> m;
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        problems.push_back(Problem(a));
        while (c--) {  //读取每个选项
            cin >> s;
            problems.back().choice += s;
        }
    }
    for (int i = 0; i < n; ++i) {
        gg score = 0;
        for (int j = 0; j < m; ++j) {
            cin >> s;  //读取题目的选项个数(没有用，略过就好)
            string t;
            do {  //读取学生全部选项
                cin >> s;
                t.push_back(s[0]);
            } while (s.back() != ')');
            if (t == problems[j].choice) {  //和正确选项相同，得分
                score += problems[j].score;
            } else {  //错误选项，递增该题错误次数
                ++problems[j].num;
            }
        }
        cout << score << '\n';  //输出学生分数
    }
    gg Max =
        max_element(problems.begin(), problems.end(),
                    [](Problem& p1, Problem& p2) { return p1.num < p2.num; })
            ->num;  //获取最大的题目错误次数
    if (Max == 0) {  //没有错误的题目
        cout << "Too simple";
    } else {
        cout << Max;
        //按编号递增顺序输出所有错误次数最多的题目
        for (auto i = 0; i < problems.size(); ++i) {
            if (problems[i].num == Max) {
                cout << ' ' << i + 1;
            }
        }
    }
    return 0;
}
