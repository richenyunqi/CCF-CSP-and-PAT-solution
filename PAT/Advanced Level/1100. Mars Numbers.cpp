#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //数字到火星文低位的映射
    array<string, 13> low = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                             "jly",  "aug", "sep", "oct", "nov", "dec"};
    //数字到火星文高位的映射
    array<string, 13> high = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                              "hei",  "elo", "syy", "lok", "mer", "jou"};
    unordered_map<string, gg> temp;  //火星文到数字的映射
    for (gg i = 0; i < 13; ++i) {
        temp[low[i]] = i;
        temp[high[i]] = i * 13;
    }
    gg ni;
    cin >> ni;
    cin.get();  //吸收空格字符
    string digit = "";
    while (ni--) {
        getline(cin, digit);
        if (isdigit(digit[0])) {  //如果是数字
            gg k = stoi(digit);
            if (k / 13 != 0)  //高位不为0，输出高位
                cout << high[k / 13];
            if (k / 13 != 0 and k % 13 != 0)  //高位低位均不为0，输出空格
                cout << ' ';
            //高位为0或者高位不为0但低位为0时，输出低位
            if (k / 13 == 0 or k % 13 != 0)
                cout << low[k % 13];
            cout << '\n';  //换行
        } else {  //是火星文
            gg k = 0;
            stringstream stream(digit);
            while (stream >> digit)  //按空格键分割字符串
                k += temp[digit];
            cout << k << '\n';
        }
    }
    return 0;
}
