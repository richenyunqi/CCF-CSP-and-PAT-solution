// 将输入数据统一转换到最小单位，进行指定运算后，再将得到的结果转换到所要输出的格式
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg g1, s1, k1, g2, s2, k2;
    char c;  //读取小数点
    cin >> g1 >> c >> s1 >> c >> k1 >> g2 >> c >> s2 >> c >> k2;
    //将输入数据统一转换到最小单位
    gg t1 = (g1 * 17 + s1) * 29 + k1, t2 = (g2 * 17 + s2) * 29 + k2;
    t2 -= t1;
    cout << t2 / 29 / 17 << '.' << abs(t2) / 29 % 17 << '.' << abs(t2) % 29;
    return 0;
}
// 从最小单位开始进行指定运算，向上级单位产生进位或借位，得出最终结果。
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct T {
    gg g, s, k;
    bool operator<(const T& t) const {
        return tie(g, s, k) < tie(t.g, t.s, t.k);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    T t1, t2;
    char c;  //读取小数点
    cin >> t1.g >> c >> t1.s >> c >> t1.k >> t2.g >> c >> t2.s >> c >> t2.k;
    if (t2 < t1) {
        cout << '-';
        swap(t1, t2);
    }
    if (t2.k < t1.k) {  //向高位借位
        t2.k = t2.k + 29;
        --t2.s;
    }
    if (t2.s < t1.s) {  //向高位借位
        t2.s = t2.s + 17;
        --t2.g;
    }
    cout << t2.g - t1.g << '.' << t2.s - t1.s << '.' << t2.k - t1.k;
    return 0;
}
