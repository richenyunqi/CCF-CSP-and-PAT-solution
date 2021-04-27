#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ni, ti, num = 0;  // num负责统计满足条件的像素个数
    cin >> mi >> ni >> ti;
    gg p[ni][mi];
    unordered_map<gg, gg> um;  //记录每个像素出现的次数
    for (gg i = 0; i < ni; ++i) {
        for (gg j = 0; j < mi; ++j) {
            cin >> p[i][j];
            ++um[p[i][j]];
        }
    }
    array<gg, 3> ans{};
    for (gg i = 0; i < ni; ++i) {
        for (gg j = 0; j < mi; ++j) {
            if (um[p[i][j]] > 1)  //该像素值出现多于一次，跳过
                continue;
            for (gg k1 = -1; k1 <= 1; ++k1) {  //遍历周围8个像素
                for (gg k2 = -1; k2 <= 1; ++k2) {
                    gg p1 = i + k1, p2 = j + k2;
                    //是周围的点且像素差不大于t，该点不满足条件
                    if (p1 >= 0 and p1 < ni and p2 >= 0 and p2 < mi and
                        (p1 != i or p2 != j) and
                        abs(p[i][j] - p[p1][p2]) <= ti) {
                        goto loop;
                    }
                }
            }
            ans = {j + 1, i + 1, p[i][j]};
            ++num;
        loop:;
        }
    }
    num == 0 ?
        cout << "Not Exist" :
        num > 1 ? cout << "Not Unique" :
                  cout << '(' << ans[0] << ", " << ans[1] << "): " << ans[2];
    return 0;
}