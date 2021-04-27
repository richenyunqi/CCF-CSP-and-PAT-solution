// DFS
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 #include<
    bits / stdc++.h> using namespace std;
using gg = long long;
const gg MAX = 1005;
vector<vector<gg>> graph(MAX);
vector<bool> visit(MAX);
void dfs(gg v) {
    visit[v] = true;
    for (gg i : graph[v]) {
        if (not visit[i]) {
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ki, ai, bi;
    cin >> ni >> mi >> ki;
    for (gg i = 0; i < mi; ++i) {
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }
    while (ki--) {
        cin >> ai;
        fill(visit.begin(), visit.begin() + ni + 1, false);
        visit[ai] = true;
        gg num = 0;
        for (gg i = 1; i <= ni; ++i) {
            if (not visit[i]) {
                ++num;
                dfs(i);
            }
        }
        cout << num - 1 << "\n";
    }
    return 0;
}
//并查集
#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg MAX = 1005;
vector<gg> ufs(MAX);
void init() { iota(ufs.begin(), ufs.end(), 0); }
gg findRoot(gg x) { return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]); }
void unionSets(gg a, gg b) { ufs[findRoot(a)] = findRoot(b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ki, ai;
    cin >> ni >> mi >> ki;
    vector<array<gg, 2>> edges(mi);
    for (auto& e : edges) {
        cin >> e[0] >> e[1];
    }
    while (ki--) {
        cin >> ai;
        init();
        for (auto& e : edges) {
            if (e[0] != ai and e[1] != ai) {  //边的两端点都不是ai，可以进行合并
                unionSets(e[0], e[1]);
            }
        }
        gg num = 0;  //记录连通分量的数量
        for (gg i = 1; i <= ni; ++i) {  //计算不包括ai的集合个数
            if (i != ai and i == ufs[i]) {
                ++num;
            }
        }
        cout << num - 1 << "\n";
    }
    return 0;
}