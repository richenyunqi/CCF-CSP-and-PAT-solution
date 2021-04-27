#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    regex r("([+-])([1-9]).([0-9]+)E([+-])([0-9]+)");
    string si;
    cin >> si;
    smatch result;
    regex_match(si, result, r);
    if (result.str(1) == "-") {  //输入是负数要输出负号
        cout << result[1];
    }
    gg n = stoll(result.str(5));  //获取指数的值
    if (result.str(4) == "-") {  //小数点要左移n位，要在小数点后补n-1个0
        cout << "0." << string(n - 1, '0') << result[2] << result[3];
    } else if (n < result.length(3)) {
        //小数点右移的位数不超过3号子串长度，将3号子串用小数点分隔开进行输出
        cout << result[2] << result.str(3).substr(0, n) << "."
             << result.str(3).substr(n);
    } else if (n == result.length(3)) {
        //小数点右移的位数等于3号子字符串长度，小数点无需输出
        cout << result[2] << result[3];
    } else {
        //小数点右移的位数超过3号子串长度，在3号子串后补0
        cout << result[2] << result[3] << string(n - result.length(3), '0');
    }
    return 0;
}