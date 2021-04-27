#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1005;
gg ni, mi, ki;
vector<vector<gg>> graph(MAX);
vector<gg> top(MAX), degree(MAX);
bool isTopSort() {
    vector<gg> temp(degree.begin(), degree.begin() + ni + 1);  //拷贝入度
    for (gg i = 0; i < ni; ++i) {
        if (temp[top[i]] != 0) {  //入度不为零，返回false
            return false;
        }
        for (gg j : graph[top[i]]) {  //遍历该结点的邻接顶点
            --temp[j];
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni >> mi;
    while (mi--) {
        gg ai, bi;
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        ++degree[bi];
    }
    cin >> ki;
    vector<gg> ans;
    for (gg i = 0; i < ki; ++i) {
        for (gg j = 0; j < ni; ++j) {
            cin >> top[j];
        }
        if (not isTopSort()) {
            ans.push_back(i);
        }
    }
    for (gg i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
    return 0;
}