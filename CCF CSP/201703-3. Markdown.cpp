#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<vector<string>> input{{}};
    while (getline(cin, line)) {
        if (line.empty()) {
            input.push_back({});
        } else {
            input.back().push_back(line);
        }
    }
    vector<pair<regex, string>> r{
        {regex("^\\* +(.*)$"), "<li>$1</li>"},  //无序列表
        {regex("_(.*?)_"), "<em>$1</em>"},  //强调
        {regex("\\[(.*?)\\]\\((.*?)\\)"), "<a href=\"$2\">$1</a>"}  //超链接
    };
    for (gg i = 1; i <= 6; ++i) {  // 6种等级标题
        r.push_back({regex("^" + string(i, '#') + " +(.*)$"),
                     "<h" + to_string(i) + ">$1</h" + to_string(i) + ">"});
    }
    for (auto& i : input) {
        if (i.empty()) {  //空区块，略过
            continue;
        }
        // type为0/1/2分别表示无序列表、标题、段落
        gg type = i[0][0] == '*' ? 0 : i[0][0] == '#' ? 1 : 2;
        cout << (type == 0 ? "<ul>\n" : type == 2 ? "<p>" : "");
        for (gg j = 0; j < i.size(); ++j) {
            for (auto& k : r) {
                i[j] = regex_replace(i[j], k.first, k.second);
            }
            cout << i[j] << (j == i.size() - 1 ? "" : "\n");
        }
        cout << (type == 0 ? "\n</ul>" : type == 2 ? "</p>" : "") << "\n";
    }
    return 0;
}