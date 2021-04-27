#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg> level;
struct BTNode {
    gg val;
    BTNode *left, *right;
    BTNode(gg v, BTNode* l = nullptr, BTNode* r = nullptr) :
        val(v), left(l), right(r) {}
};
void insertElement(BTNode*& root, gg x) {
    if (not root) {  //根结点为空，新建一个结点
        root = new BTNode(x);
    } else if (x <= root->val) {  //向左子树中插入
        insertElement(root->left, x);
    } else {  //向右子树中插入
        insertElement(root->right, x);
    }
}
void preOrder(BTNode* root, gg depth) {
    if (not root)
        return;
    if (level.size() <= depth)
        level.push_back(0);
    ++level[depth];
    preOrder(root->left, depth + 1);
    preOrder(root->right, depth + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    BTNode* root = nullptr;
    gg ni, ai;
    cin >> ni;
    while (ni--) {
        cin >> ai;
        insertElement(root, ai);
    }
    preOrder(root, 0);
    gg k1 = level.back(), k2 = level.size() > 1 ? level[level.size() - 2] : 0;
    cout << k1 << " + " << k2 << " = " << (k1 + k2);
    return 0;
}