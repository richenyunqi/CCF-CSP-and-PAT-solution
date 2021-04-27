#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double ci, di, davg;
    gg ni;
    cin >> ci >> di >> davg >> ni;
    vector<array<double, 2>> v(ni);
    for (auto& i : v) {
        cin >> i[1] >> i[0];
    }
    v.push_back({di, 0});
    sort(v.begin(), v.end());
    if (abs(v[0][0]) > 1e-6) {  //第一个加油站距离不是0
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    gg cur = 0;
    double ans = 0, curd = 0;  // curd表示当前油箱油量
    cout << fixed << setprecision(2);
    while (cur < ni) {
        gg t = ni + 1;
        for (gg i = cur + 1; i <= ni and ci * davg + v[cur][0] >= v[i][0];
             ++i) {
            if (v[i][1] < v[cur][1]) {  //找到了比cur加油站油价低的加油站
                t = i;
                break;
            } else if (t == ni + 1 or v[i][1] < v[t][1]) {  //找油价最低的加油站
                t = i;
            }
        }
        if (t == ni + 1) {  //在cur加油站加满油到达不了任何加油站
            cout << "The maximum travel distance = " << v[cur][0] + ci * davg;
            return 0;
        }
        if (v[cur][1] > v[t][1]) {  //加油站t油价比加油站cur便宜
            double p = (v[t][0] - v[cur][0]) / davg;  //到达t站所需的油量
            if (p > curd) {  //到达t站需加油，只加恰好能到达t站的油量
                ans += (p - curd) * v[cur][1];
                curd = 0;
            } else {  //到达t站不需加油，从油箱中减去到达t站所需的油
                curd -= p;
            }
        } else {  // t站油价比cur站高，从cur站加满油
            ans += (ci - curd) * v[cur][1];
            curd = ci - (v[t][0] - v[cur][0]) / davg;
        }
        cur = t;
    }
    cout << ans;
    return 0;
}