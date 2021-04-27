#include <bits/stdc++.h>
using namespace std;
using gg = long long;
//按字符/分割字符串
vector<string> split(string& s) {
    vector<string> ans;
    stringstream ss(s);
    while (getline(ss, s, '/')) {
        ans.push_back(s);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    string si, cur;
    cin >> ni;
    cin.get();  //吸收换行符
    getline(cin, cur);  //读取当前目录
    while (ni--) {
        getline(cin, si);  //读取路径
        //路径为空或不是以/开始，那么该路径是以当前目录开始的
        if (si.empty() or si[0] != '/') {
            si = cur + "/" + si;  //在路径首部添加当前路径
        }
        auto path = split(si);  //按/分割路径
        vector<string> ans;
        for (auto& s : path) {  //遍历分割后的路径中每个目录或文件
            if (s == "." or s.empty() or (s == ".." and ans.empty())) {
                continue;  //遇到.或者空字符串或遇到..但没有父目录，不进行任何操作
            } else if (s == "..") {  //回到父目录，即从ans尾部弹出一个目录
                ans.pop_back();
            } else {  //压入ans中一个目录或文件
                ans.push_back(s);
            }
        }
        string out;
        for (string& i : ans) {  //将各目录或文件用/连接起来
            out += "/" + i;
        }
        cout << (out.empty() ? "/" : out) << "\n";
    }
    return 0;
}