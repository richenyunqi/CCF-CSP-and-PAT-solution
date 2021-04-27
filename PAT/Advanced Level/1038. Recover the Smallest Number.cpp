#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<string> v(ni);
    for (auto& i : v) {  //读取n个数字
        cin >> i;
    }
    //按拼接后形成字典序最小的字符串的比较方式进行排序
    sort(v.begin(), v.end(),
         [](const string& s1, const string& s2) { return s1 + s2 < s2 + s1; });
    string s = accumulate(v.begin(), v.end(), string());  //将所有数字拼接在一起
    //找到第一个不为零的字符
    auto i = find_if(s.begin(), s.end(), [](char c) { return c != '0'; });
    //输出不带前导零的数字
    i == s.end() ? (cout << "0") : (cout << s.substr(i - s.begin()));
    return 0;
}
