#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, pi;
    cin >> ni;
    vector<gg> v(20, 5);
    while (ni--) {
        cin >> pi;
        //查找有没有剩余座位大于等于pi的排
        auto i = find_if(v.begin(), v.end(), [pi](int a) { return a >= pi; });
        if (i != v.end()) {  //有
            gg start = (i - v.begin()) * 5 + 6 - (*i);  //剩余座位起始编号
            *i -= pi;  //该排减去pi个空闲座位
            for (gg j = 0; j < pi; ++j) {  //输出pi个连续座位编号
                cout << start + j << " ";
            }
            cout << "\n";
            continue;
        }
        //以下代码处理没有剩余座位大于等于pi的排的情况
        for (gg j = 0; pi > 0; ++j) {  //遍历所有的排
            //输出该排空闲座位编号，直至输出pi个座位
            for (gg start = j * 5 + 6 - v[j]; v[j] > 0; --v[j], ++start, --pi) {
                cout << start << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}