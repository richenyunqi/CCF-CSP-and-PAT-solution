#include <bits/stdc++.h>
using namespace std;
using gg = long long;
void getPostFromBSTPre(vector<gg>& pre, gg left, gg right, vector<gg>& post,
                       bool mirror) {
    if (left > right)
        return;
    //查找右子树根结点在先根序列中的位置
    gg i = find_if(pre.begin() + left + 1, pre.begin() + right + 1,
                   [&pre, left, mirror](gg a) {
                       return mirror ? a < pre[left] : a >= pre[left];
                   }) -
           pre.begin();
    //如果右子树中有任意一个结点不满足大于等于（二叉查找树）/小于（镜像树）根结点的性质，提前返回
    if (any_of(pre.begin() + i, pre.begin() + right + 1,
               [&pre, left, mirror](gg a) {
                   return mirror ? a >= pre[left] : a < pre[left];
               })) {
        return;
    }
    getPostFromBSTPre(pre, left + 1, i - 1, post, mirror);
    getPostFromBSTPre(pre, i, right, post, mirror);
    post.push_back(pre[left]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<gg> pre(ni), post1, post2;
    for (gg& i : pre) {
        cin >> i;
    }
    getPostFromBSTPre(pre, 0, ni - 1, post1, true);
    getPostFromBSTPre(pre, 0, ni - 1, post2, false);
    if (post1.size() == ni or post2.size() == ni) {
        cout << "YES\n";
        auto& post = post1.size() == ni ? post1 : post2;
        for (gg i = 0; i < ni; ++i) {
            cout << (i == 0 ? "" : " ") << post[i];
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}
