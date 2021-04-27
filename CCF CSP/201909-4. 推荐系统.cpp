#include <bits/stdc++.h>
using namespace std;
struct Commodity {  //商品类
    long long id, score;  //id和分数
    Commodity(long long i, long long s) : id(i), score(s) {}
    bool operator<(const Commodity& c) const {  //重载小于运算符
        return this->score != c.score ? this->score > c.score : this->id < c.id;
    }
};
int main() {
    const long long mul = (long long)(1e9);
    int m, n, id, score, op, t, c, k;
    cin >> m >> n;
    vector<int> K(m);  //存储每类商品被选中的最多件数
    set<Commodity> commodities;  //对所有商品进行排序
    unordered_map<long long, set<Commodity>::iterator> um;  //存储商品id和对应的set中的迭代器
    for (int i = 0; i < n; ++i) {
        cin >> id >> score;
        for (int j = 0; j < m; ++j) {
            long long a = j * mul + id;
            um[a] = commodities.insert(Commodity(a, score)).first;
        }
    }
    cin >> op;
    while (op--) {
        cin >> c;
        if (c == 1) {  //添加商品
            cin >> t >> id >> score;
            long long a = t * mul + id;
            um[a] = commodities.insert(Commodity(a, score)).first;
        } else if (c == 2) {  //删除商品
            cin >> t >> id;
            long long a = t * mul + id;
            commodities.erase(um[a]);
            um.erase(a);
        } else {
            vector<vector<int>> ans(m);
            cin >> k;
            for (int i = 0; i < m; ++i)
                cin >> K[i];
            for (auto& i : commodities) {  //遍历整个set
                t = i.id / mul;
                if (ans[t].size() < K[t]) {
                    ans[t].push_back(i.id % mul);
                    if (--k == 0)  //商品已选满k件，结束遍历
                        break;
                }
            }
            for (auto& i : ans)
                if (i.empty()) {  //没有选中的商品，输出-1
                    cout << "-1\n";
                } else {
                    // sort(i.begin(), i.end());//从小到大排序，注释掉这行代码能拿到满分，不注释掉只有60分
                    for (auto j : i)
                        cout << j << " ";
                    cout << "\n";
                }
        }
    }
    return 0;
}