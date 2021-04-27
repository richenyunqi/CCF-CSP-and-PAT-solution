#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Customer {
    gg endTime, num, w;  //结束服务的时间、顾客编号、服务窗口编号
    Customer(gg e, gg n, gg ww) : endTime(e), num(n), w(ww) {}
};
bool operator<(const Customer& c1, const Customer& c2) {
    return tie(c1.endTime, c1.w) > tie(c2.endTime, c2.w);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ki, qi, ai, endTime = 17 * 60;
    cin >> ni >> mi >> ki >> qi;
    vector<gg> ans(ki, INT_MAX);  // INT_MAX默认为该顾客没有接受服务
    //目前排在黄线内的所有顾客信息
    priority_queue<Customer> customers;
    // peopleNum存储每个窗口的排队人数、time存储每个窗口排在最后的人处理完成的时间
    vector<gg> peopleNum(ni), time(ni, 8 * 60);
    for (gg i = 0; i < ki; ++i) {
        cin >> ai;  //读取顾客需要的服务时间
        //黄线内人数达到上限，从队列中弹出一个顾客
        if (customers.size() == ni * mi) {
            auto c = customers.top();
            customers.pop();
            peopleNum[c.w]--;
        }
        gg j = min_element(peopleNum.begin(), peopleNum.end()) - peopleNum.begin();
        peopleNum[j]++;
        if (time[j] >= endTime) {  //开始服务时间超过17:00，该顾客不能被服务
            continue;
        }
        time[j] += ai;
        customers.push(Customer(time[j], i, j));
        ans[i] = time[j];
    }
    for (gg i = 0; i < qi; ++i) {
        cin >> ai;
        if (ans[ai - 1] == INT_MAX) {
            cout << "Sorry\n";
        } else {
            cout << setfill('0') << setw(2) << ans[ai - 1] / 60 << ":" << setw(2)
                 << ans[ai - 1] % 60 << "\n";
        }
    }
    return 0;
}