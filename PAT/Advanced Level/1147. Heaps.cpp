#include <bits/stdc++.h>
using namespace std;
using gg = long long;
gg mi, ni;
void postOrder(vector<gg>& v, gg root, gg& num) {
    if (root >= v.size()) {
        return;
    }
    postOrder(v, root * 2 + 1, num);
    postOrder(v, root * 2 + 2, num);
    cout << v[root] << (num++ < ni - 1 ? " " : "\n");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> mi >> ni;
    vector<gg> v(ni);
    while (mi--) {
        for (gg& i : v) {
            cin >> i;
        }
        if (is_heap(v.begin(), v.end())) {  //能构成大根堆
            cout << "Max Heap\n";
        } else if (is_heap(v.begin(), v.end(), greater<gg>())) {  //能构成小根堆
            cout << "Min Heap\n";
        } else {  //不能构成堆
            cout << "Not Heap\n";
        }
        gg num = 0;  //记录输出到第几个数字了
        postOrder(v, 0, num);
    }
    return 0;
}