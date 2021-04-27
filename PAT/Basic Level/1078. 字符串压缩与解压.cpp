#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string compress(const string& s) {  //压缩
    string r;
    for (gg i = 0, j = 0; i < s.size(); i = j) {
        //找到下标i之后第一个与s[i]不同的字符的下标
        j = s.find_first_not_of(s[i], i);
        if (j == -1)
            j = s.size();
        //压缩当前字符
        r += (j - i == 1 ? "" : to_string(j - i)) +
             string(1, s[i]);
    }
    return r;
}
string decompress(const string& s) {  //解压
    string r;
    for (gg i = 0, j = 0; i < s.size(); i = j + 1) {
        //找到下标i之后第一个非数字字符的下标
        j = s.find_first_not_of("0123456789", i);
        //解析字符s[j]的个数
        gg k = j - i == 0 ? 1 : stoll(s.substr(i, j - i));
        //解压s[j]字符
        r += string(k, s[j]);
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string fi, si;
    getline(cin, fi);
    getline(cin, si);
    cout << (fi == "C" ? compress(si) : decompress(si));
    return 0;
}
