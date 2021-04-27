#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki;
    cin >> ni >> ki;
    queue<gg> q;
    for (gg i = 1; i <= ni; ++i) {  //将1~n这些人的编号压入队列
        q.push(i);
    }
    for (gg i = 1; q.size() > 1; ++i) {  // i表示当前报的数字
        gg t = q.front();  //弹出当前应该报数的人的编号
        q.pop();
        if (i % ki != 0 and i % 10 != ki) {  //不该被淘汰，重新入队
            q.push(t);
        }
    }
    cout << q.front();
    return 0;
}