#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 105;
struct Node {
    gg val, left = -1, right = -1;
};
vector<Node> tree(MAX);
vector<gg> in(MAX);
gg ni;
void inOrder(gg root, gg& p) {
    if (root == -1) {
        return;
    }
    inOrder(tree[root].left, p);
    tree[root].val = in[p++];
    inOrder(tree[root].right, p);
}
void levelOrder(gg root) {
    queue<gg> q;
    q.push(root);
    while (not q.empty()) {
        auto t = q.front();
        q.pop();
        cout << (t == 0 ? "" : " ") << tree[t].val;
        if (tree[t].left != -1)
            q.push(tree[t].left);
        if (tree[t].right != -1)
            q.push(tree[t].right);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni;
    for (gg i = 0; i < ni; ++i) {
        cin >> tree[i].left >> tree[i].right;
    }
    for (gg i = 0; i < ni; ++i) {
        cin >> in[i];
    }
    sort(in.begin(), in.begin() + ni);
    gg p = 0;  //标记当前要处理的数字在中根序列中的下标
    inOrder(0, p);
    levelOrder(0);
    return 0;
}
