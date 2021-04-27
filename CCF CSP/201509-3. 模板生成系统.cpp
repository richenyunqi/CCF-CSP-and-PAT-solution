#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    string line;
    vector<string> input(ni);
    cin.get();  //吸收换行符
    for (gg i = 0; i < ni; ++i) {  //读取输入
        getline(cin, input[i]);
    }
    unordered_map<string, string> um;
    smatch result;
    regex r("([^ ]+) +\"(.+)\"");
    while (mi--) {
        getline(cin, line);
        if (regex_search(line, result, r)) {  //分割变量名和值
            um[result.str(1)] = result.str(2);
        }
    }
    r = "\\{\\{ (.*?) \\}\\}";
    for (auto& i : input) {
        for (sregex_iterator it(i.begin(), i.end(), r), e; it != e; ++it) {
            cout << it->prefix() << um[it->str(1)];
            if (next(it) == e) {  //到达最后一个匹配位置
                cout << it->suffix() << "\n";
                goto loop;
            }
        }
        cout << i << "\n";
    loop:;
    }
    return 0;
}
