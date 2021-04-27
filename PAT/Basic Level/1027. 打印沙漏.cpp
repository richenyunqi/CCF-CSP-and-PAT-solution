//二维数组输出方式
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    char ci;
    cin >> ni >> ci;
    //获取漏斗上半部分行数k，总行数row
    gg k = (gg)sqrt((ni + 1) / 2 * 1.0), row = 2 * k - 1;
    //定义二维数组并将元素都初始化为空格字符
    vector<vector<char>> ans(row, vector<char>(row, ' '));
    //填充二维数组
    for (gg i = 0; i < k; ++i)
        for (gg j = k - 1 - i; j < k + i; ++j)
            ans[k - 1 - i][j] = ans[k - 1 + i][j] = ci;
    //输出二维数组
    for (gg i = 0; i < row; ++i) {
        bool output = true;
        for (gg j = 0; j < row; ++j) {
            if (ans[i][j] == ' ' and !output)
                break;
            if (ans[i][j] != ' ') {
                output = false;
            }
            cout << ans[i][j];
        }
        cout << '\n';
    }
    //输出剩余字符个数
    cout << ni - 2 * k * k + 1;
    return 0;
}
//直接输出方式
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    char ci;
    cin >> ni >> ci;
    //获取漏斗上半部分行数mid，总行数row
    gg k = (gg)sqrt((ni + 1) / 2 * 1.0), row = 2 * k - 1;
    //输出上半部分
    gg space = 0;
    for (gg i = row; i >= 1; i -= 2) {
        for (gg j = 0; j < space; ++j)
            cout << ' ';
        ++space;
        for (gg j = 0; j < i; ++j)
            cout << ci;
        cout << '\n';
    }
    --space;
    //输出下半部分
    for (gg i = 3; i <= row; i += 2) {
        --space;
        for (gg j = 0; j < space; ++j)
            cout << ' ';
        for (gg j = 0; j < i; ++j)
            cout << ci;
        cout << '\n';
    }
    //输出剩余字符个数
    cout << ni - 2 * k * k + 1;
    return 0;
}
