#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg> path;  //存储路径
void dfs(vector<gg>& v, gg root) {
    if (root >= v.size()) {
        return;
    }
    if (root * 2 + 1 >= v.size()) {  //是叶子结点
        for (gg i : path) {
            cout << i << " ";
        }
        cout << v[root] << "\n";
        return;
    }
    path.push_back(v[root]);
    dfs(v, root * 2 + 2);  //递归遍历右子树
    dfs(v, root * 2 + 1);  //递归遍历左子树
    path.pop_back();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<gg> v(ni);
    for (gg& i : v) {
        cin >> i;
    }
    dfs(v, 0);
    if (is_heap(v.begin(), v.end())) {  //能构成大根堆
        cout << "Max Heap\n";
    } else if (is_heap(v.begin(), v.end(), greater<gg>())) {  //能构成小根堆
        cout << "Min Heap\n";
    } else {  //不能构成堆
        cout << "Not Heap\n";
    }
    return 0;
}