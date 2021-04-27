#include <bits/stdc++.h>
using namespace std;
using gg = long long;
void getPostFromPreIn(vector<gg>& pre, vector<gg>& in, gg r, gg left, gg right) {
    if (left > right)  //序列为空，直接返回
        return;
    gg i = find(in.begin(), in.end(), pre[r]) - in.begin();
    getPostFromPreIn(pre, in, r + 1, left, i - 1);  //递归遍历左子树
    getPostFromPreIn(pre, in, r + 1 + i - left, i + 1, right);  //递归遍历右子树
    cout << pre[r] << (r == 0 ? "" : " ");  // r==0时为整棵树的根结点，后面不能有空格
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ai;
    cin >> ni;
    string si;
    stack<gg> st;
    vector<gg> pre, in;
    for (gg i = 0; i < 2 * ni; ++i) {
        cin >> si;
        if (si == "Push") {
            cin >> ai;
            st.push(ai);
            pre.push_back(ai);
        } else {
            in.push_back(st.top());
            st.pop();
        }
    }
    getPostFromPreIn(pre, in, 0, 0, in.size() - 1);
    return 0;
}