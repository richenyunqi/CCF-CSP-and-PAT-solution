#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string input = "";
    cin >> input;
    gg n1 = (input.size() + 2) / 3;
    gg n2 = input.size() + 2 - 2 * n1;
    //前n1-1行，需要输出首尾两个字符，且每行字符数为n2
    for (int i = 0; i < n1 - 1; ++i) {
        cout << input[i];
        for (int j = 0; j < n2 - 2; ++j)
            cout << " ";
        cout << input[input.size() - i - 1] << "\n";
    }
    //最后一行将没有输出的n2个字符一次性输出
    cout << input.substr(n1 - 1, n2);
    return 0;
}
