//使用DFS
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<vector<gg>> tree(105);
gg ni, mi, ki;
vector<gg> ans;  //存储每层叶子结点数量
void preOrder(gg root, gg depth) {
    if (ans.size() <= depth) {
        ans.push_back(0);
    }
    if (tree[root].empty()) {  //是叶结点，增加对应层次上叶子结点数量
        ++ans[depth];
    }
    for (auto i : tree[root]) {
        preOrder(i, depth + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni >> mi;
    gg id1, id2;
    while (mi--) {
        cin >> id1 >> ki;
        while (ki--) {
            cin >> id2;
            tree[id1].push_back(id2);
        }
    }
    preOrder(1, 0);
    for (int i = 0; i < ans.size(); ++i) {
        cout << (i == 0 ? "" : " ") << ans[i];
    }
    return 0;
}
//使用BFS
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<vector<gg>> tree(105);
gg ni, mi, ki;
void levelOrder(gg root) {
    queue<gg> q;
    q.push(root);
    bool space = false;  //标志是否输出空格
    while (not q.empty()) {
        gg s = q.size(), ans = 0;
        while (s--) {
            auto t = q.front();
            q.pop();
            if (tree[t].empty()) {  //是叶子结点
                ++ans;
            }
            for (auto i : tree[t]) {
                q.push(i);
            }
        }
        cout << (space ? " " : "") << ans;
        space = true;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni >> mi;
    gg id1, id2;
    while (mi--) {
        cin >> id1 >> ki;
        while (ki--) {
            cin >> id2;
            tree[id1].push_back(id2);
        }
    }
    levelOrder(1);
    return 0;
}
