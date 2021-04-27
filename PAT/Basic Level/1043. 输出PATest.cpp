#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string si, out = "PATest";
    unordered_map<char, gg> um;  //记录字符及其出现次数
    cin >> si;
    for (char c : si) {  //统计字符出现的次数
        if (out.find(c) != -1) {  // out中包含字符c
            ++um[c];
        }
    }
    while (not um.empty()) {
        for (char c : out) {
            if (um.count(c)) {  // um关键字中有该字符
                cout << c;
                //每输出一个字符就在um中将该字符个数减1
                //如果字符个数为0，就将该元素从um中删除
                if (--um[c] == 0) {
                    um.erase(c);
                }
            }
        }
    }
    return 0;
}
