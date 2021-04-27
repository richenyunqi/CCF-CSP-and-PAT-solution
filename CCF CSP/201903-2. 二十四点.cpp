#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    string si;
    queue<gg> num;
    queue<char> op;
    while (ni--) {
        cin >> si;
        num.push(si[0] - '0');  //把第一个操作数压入队列
        for (gg i = 1; i < si.size(); i += 2) {  //遍历整个字符串
            if (si[i] == '+' or si[i] == '-') {  //将加减法的操作数和符号入队
                op.push(si[i]);
                num.push(si[i + 1] - '0');
            } else if (si[i] == 'x') {  //是乘法，计算乘法结果
                num.back() *= (si[i + 1] - '0');
            } else {  //是除法，计算乘法结果
                num.back() /= (si[i + 1] - '0');
            }
        }
        gg t = num.front();  //第一个加减法操作数
        num.pop();
        while (!op.empty()) {  //同时遍历两个队列，求出加减运算的结果
            char c = op.front();
            op.pop();
            t = (c == '+') ? t + num.front() : t - num.front();
            num.pop();
        }
        cout << (t == 24 ? "Yes" : "No") << "\n";
    }
    return 0;
}
