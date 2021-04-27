#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<char, gg> um;  //存储字符和对应的基数
string s1, s2;
gg tag, radix;
gg rToDec(const string& r, gg R) {  //将R进制数转换成十进制数
    gg d = 0;
    for (auto i : r)
        d = d * R + um[i];
    return d;
}
gg binarySearchF(gg left, gg right, gg n) {  //二分查找函数
    while (left < right) {
        gg mid = (left + right) / 2;
        auto k = rToDec(s2, mid);
        if (k >= n or k < 0)  // k<0，发生了数据溢出，这时也满足>=n的条件
            right = mid;
        else
            left = mid + 1;
    }
    auto k = rToDec(s2, left);
    return left > right or not(k >= n or k < 0) ? -1 : left;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s1 >> s2 >> tag >> radix;
    if (tag == 2)  //让s1作为指定了进制的数，s2作为要查找进制的数
        swap(s1, s2);
    for (gg i = 0; i < 36; ++i) {  //存储字符和对应的基数
        um.insert({i < 10 ? i + '0' : i - 10 + 'a', i});
    }
    gg n = rToDec(s1, radix);
    //找到s2中对应基数最大的字符，从而确定查找下限
    auto m = max_element(s2.begin(), s2.end(),
                         [](char c1, char c2) { return um[c1] < um[c2]; });
    gg left = um[*m] + 1;  //查找下限
    auto ans = binarySearchF(left, n + 1, n);
    //查找失败或查找到的第一个>=n的数不等于n，要输出Impossible
    ans == -1 or rToDec(s2, ans) != n ? cout << "Impossible" : cout << ans;
    return 0;
}
