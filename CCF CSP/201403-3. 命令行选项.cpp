#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s;
    vector<gg> type(128);  //值为0表示该字母不是命令行选项
    for (gg i = 0; i < s.size(); ++i) {
        type[s[i]] = 1;  //不带参数选项
        if (i + 1 < s.size() and s[i + 1] == ':') {
            type[s[i]] = 2;  //带参数选项
        }
    }
    gg ni;
    cin >> ni;
    cin.get();  //吸收换行符
    for (gg ii = 1; ii <= ni; ++ii) {
        getline(cin, s);
        map<char, string> ans;
        stringstream ss(s);
        ss >> s;  //命令行工具名
        while (ss >> s) {
            if (s.size() == 2 and s[0] == '-' and type[s[1]] == 1) {
                ans[s[1]] = "";  //不带参数选项，map中对应值为空字符串
            } else if (s.size() == 2 and s[0] == '-' and type[s[1]] == 2 and
                       ss >> t) {
                ans[s[1]] = t;  //带参数选项，map中对应值为t
            } else {  //错误选项，跳出循环
                break;
            }
        }
        cout << "Case " << ii << ":";
        for (auto& i : ans) {
            cout << " -" << i.first;
            if (not i.second.empty()) {
                cout << " " << i.second;
            }
        }
        cout << "\n";
    }
    return 0;
}