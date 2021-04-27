#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct BTNode {
    string val;
    gg left, right;
};
vector<BTNode> tree(25);
void inOrder(gg root, gg r) {
    if (root == -1) {
        return;
    }
    if (tree[root].left == -1 and tree[root].right == -1) {
        cout << tree[root].val;
        return;
    }
    if (root != r) {  //最外层的表达式是没有括号的
        cout << "(";
    }
    inOrder(tree[root].left, r);
    cout << tree[root].val;
    inOrder(tree[root].right, r);
    if (root != r) {  //最外层的表达式是没有括号的
        cout << ")";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<bool> f(ni + 1);
    for (gg i = 1; i <= ni; ++i) {
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1) {
            f[tree[i].left] = true;
        }
        if (tree[i].right != -1) {
            f[tree[i].right] = true;
        }
    }
    gg root = find(f.begin() + 1, f.end(), false) - f.begin();
    inOrder(root, root);
    return 0;
}
