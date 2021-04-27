#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    vector<vector<gg>> ai(ni, vector<gg>(mi));
    for (gg i = 0; i < ni; ++i) {
        for (gg j = 0; j < mi; ++j) {
            cin >> ai[i][j];  //读取数据
        }
    }
    //处理每行连续超过3次的数字
    for (gg i = 0; i < ni; ++i) {
        // k记录当前连续数字开始列号，num记录连续出现的次数，last记录连续数字的值
        gg k = 0, num = 0, last = 0;
        for (gg j = 0; j <= mi; ++j) {
            if (j == mi or abs(ai[i][j]) != last) {
                if (num >= 3) {  //连续出现超过3次
                    for (gg t = 0; t < num; ++t) {  //需要消除，均变为负数
                        ai[i][k + t] = -abs(ai[i][k + t]);
                    }
                }
                if (j < mi) {
                    last = abs(ai[i][j]);
                    num = 1;
                    k = j;
                }
            } else {  //颜色相同，递增num
                ++num;
            }
        }
    }
    //处理每列连续超过3次的数字
    for (gg j = 0; j < mi; ++j) {
        // k记录当前连续数字开始行号，num记录连续出现的次数，last记录连续数字的值
        gg k = 0, num = 0, last = 0;
        for (gg i = 0; i <= ni; ++i) {
            if (i == ni or abs(ai[i][j]) != last) {
                if (num >= 3) {  //连续出现超过3次
                    for (gg t = 0; t < num; ++t) {  //需要消除，均变为负数
                        ai[k + t][j] = -abs(ai[k + t][j]);
                    }
                }
                if (i < ni) {
                    last = abs(ai[i][j]);
                    num = 1;
                    k = i;
                }
            } else {  //颜色相同，递增num
                ++num;
            }
        }
    }
    for (auto& i : ai) {
        for (auto j : i) {
            cout << max(j, 0ll) << " ";  //负数要输出为0
        }
        cout << "\n";
    }
    return 0;
}