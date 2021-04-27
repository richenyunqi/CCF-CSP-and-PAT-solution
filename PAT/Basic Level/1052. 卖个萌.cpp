#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<vector<string>, 3> e{};  //存储表情符号
    for (auto& v : e) {
        string line;
        getline(cin, line);  //读取一行字符串
        // i负责查找'['的下标，j负责查找']'的下标
        for (auto i = line.find('['); i != -1;) {
            auto j = line.find(']', i);
            v.push_back(line.substr(i + 1, j - i - 1));
            i = line.find('[', j);
        }
    }
    gg ki, ai;
    cin >> ki;
    while (ki--) {
        string out;  //存储要输出的表情字符串
        bool f = true;  //表示下标是否存在非法情况
        for (auto i = 0; i < 5; ++i) {
            cin >> ai;
            // v负责获取a是手眼口中哪个表情数组的下标
            const auto& v = i == 2 ? e[2] : (i == 0 or i == 4) ? e[0] : e[1];
            if (ai - 1 >= v.size()) {  //下标非法
                f = false;
            } else {
                out += v[ai - 1] + (i == 0 ? "(" : i == 3 ? ")" : "");
            }
        }
        f ? cout << out << '\n' : cout << "Are you kidding me? @\\/@\n";
    }
    return 0;
}
