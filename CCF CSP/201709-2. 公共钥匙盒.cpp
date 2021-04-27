#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Key {  //钥匙编号，取/还时间，flag=0表示是还；flag=1表示是取
    gg num, time, flag;
    Key(gg n, gg t, gg f) : num(n), time(t), flag(f) {}
};
//优先级：时间小、先还后取、编号小的优先
bool operator<(const Key& k1, const Key& k2) {
    return tie(k1.time, k1.flag, k1.num) > tie(k2.time, k2.flag, k2.num);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki, wi, si, ci;
    cin >> ni >> ki;
    vector<gg> v(ni);  //存储挂钩上所有钥匙编号
    iota(v.begin(), v.end(), 1);  //初始时挂钩上钥匙编号为1~N
    priority_queue<Key> pq;
    while (ki--) {
        cin >> wi >> si >> ci;
        pq.push(Key(wi, si, 1));  //取钥匙
        pq.push(Key(wi, si + ci, 0));  //还钥匙
    }
    while (not pq.empty()) {
        auto k = pq.top();
        pq.pop();
        if (k.flag == 1) {  //取钥匙
            *find(v.begin(), v.end(), k.num) = -1;  //置为-1表示该挂钩没有放钥匙
        } else {  //还钥匙
            *find(v.begin(), v.end(), -1) = k.num;  //找到最左边的空的挂钩放钥匙
        }
    }
    for (gg i : v) {
        cout << i << " ";
    }
    return 0;
}