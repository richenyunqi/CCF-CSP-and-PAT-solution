#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 15;
gg ni;
vector<array<gg, 2>> tree(MAX, {-1, -1});
void inOrder(gg root, gg& n) {
    if (root == -1)
        return;
    inOrder(tree[root][0], n);
    cout << root << (++n == ni ? "\n" : " ");
    inOrder(tree[root][1], n);
}
void levelOrder(gg root) {
    queue<gg> q;
    q.push(root);
    gg n = 0;
    while (not q.empty()) {
        auto t = q.front();
        q.pop();
        cout << t << (++n == ni ? "\n" : " ");
        if (tree[t][0] != -1)
            q.push(tree[t][0]);
        if (tree[t][1] != -1)
            q.push(tree[t][1]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni;
    string s1, s2;
    vector<bool> f(ni);
    for (gg i = 0; i < ni; ++i) {
        cin >> s1 >> s2;
        if (s1 != "-") {
            tree[i][1] = stoll(s1);
            f[stoll(s1)] = true;
        }
        if (s2 != "-") {
            tree[i][0] = stoll(s2);
            f[stoll(s2)] = true;
        }
    }
    gg root = find(f.begin(), f.end(), false) - f.begin();
    levelOrder(root);
    gg n = 0;
    inOrder(root, n);
    return 0;
}
