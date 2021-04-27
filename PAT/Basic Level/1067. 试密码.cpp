#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string ci, in;
    gg ni;
    cin >> ci >> ni;  //读取密码和输入次数
    cin.get();  //吸收换行符
    while (getline(cin, in) and in != "#") {
        if (in == ci) {  //密码正确
            cout << "Welcome in\n";
            break;
        }
        cout << "Wrong password: " << in << '\n';
        if (--ni == 0) {  //输入次数达到上限
            cout << "Account locked\n";
            break;
        }
    }
    return 0;
}