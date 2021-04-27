#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Time {
    //月日时分、onoff表示是否在线、time表示距0日0时0分的分钟数
    gg month, day, hour, minute, onoff, time;
    Time(gg m, gg d, gg h, gg mi, gg of) :
        month(m), day(d), hour(h), minute(mi), onoff(of) {
        time = day * 24 * 60 + hour * 60 + minute;
    }
};
array<double, 25> price, sumPrice;
double compute(const Time& t) {  //计算当前时间到0日0时0分所用话费
    return sumPrice.back() * t.day + sumPrice[t.hour] +
           price[t.hour + 1] * t.minute;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (gg i = 1; i <= 24; ++i) {
        cin >> price[i];
        price[i] /= 100.0;  //将单位变为美元/分钟
        //计算从0时到i时的电话费用
        sumPrice[i] = sumPrice[i - 1] + price[i] * 60;
    }
    gg ni;
    cin >> ni;
    map<string, vector<Time>> bills;
    while (ni--) {
        string s1, s2;
        gg m, d, h, mi;
        char c;
        cin >> s1 >> m >> c >> d >> c >> h >> c >> mi >> s2;
        bills[s1].push_back(Time(m, d, h, mi, s2 == "on-line" ? 0 : 1));
    }
    cout << setfill('0') << fixed << setprecision(2);  //高位补0，保留两位小数
    for (auto& bill : bills) {
        const string& name = bill.first;
        auto& b = bill.second;
        //按时间顺序排序所有电话记录
        sort(b.begin(), b.end(),
             [](const Time& t1, const Time& t2) { return t1.time < t2.time; });
        double sum = 0;
        bool out = false;  //标记名字和月份是否已输出过
        for (gg i = 1; i < b.size(); ++i) {
            if (b[i].onoff == 1 and b[i - 1].onoff == 0) {
                if (not out) {  //输出名字和月份
                    cout << name << " " << setw(2) << b[i].month << "\n";
                    out = true;
                }
                double temp = compute(b[i]) - compute(b[i - 1]);  //计算呼叫费用
                sum += temp;
                cout << setw(2) << b[i - 1].day << ":" << setw(2)
                     << b[i - 1].hour << ":" << setw(2) << b[i - 1].minute
                     << " " << setw(2) << b[i].day << ":" << setw(2)
                     << b[i].hour << ":" << setw(2) << b[i].minute << " "
                     << b[i].time - b[i - 1].time << " $" << temp << "\n";
            }
        }
        if (out) {
            cout << "Total amount: $" << sum << "\n";
        }
    }
    return 0;
}
