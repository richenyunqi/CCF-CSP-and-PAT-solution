#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct BTNode {
    int left = -1, right = -1;
};
vector<bool> f(25);  //标记有无父结点
vector<BTNode> tree(25);
gg ni;
void isCompleteTree(gg root) {
    queue<array<gg, 2>> q;  // array元素分别表示结点下标、结点编号
    q.push({root, 1});
    auto last = q.front();  //存放最后一个结点信息
    for (gg i = 1; !q.empty(); ++i) {
        last = q.front();
        q.pop();
        if (i != last[1]) {  //不是完全二叉树
            cout << "NO " << root;
            return;
        }
        if (tree[last[0]].left != -1)
            q.push({tree[last[0]].left, last[1] * 2});
        if (tree[last[0]].right != -1)
            q.push({tree[last[0]].right, last[1] * 2 + 1});
    }
    cout << "YES " << last[0];  //是完全二叉树，输出YES和最后一个结点下标
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni;
    string si;
    for (gg i = 0; i < ni; ++i) {
        for (gg j = 0; j < 2; ++j) {
            cin >> si;
            if (si != "-") {
                gg t = stoll(si);
                j == 0 ? tree[i].left = t : tree[i].right = t;
                f[t] = true;
            }
        }
    }
    gg root = find(f.begin(), f.begin() + ni, false) - f.begin();
    isCompleteTree(root);
    return 0;
}