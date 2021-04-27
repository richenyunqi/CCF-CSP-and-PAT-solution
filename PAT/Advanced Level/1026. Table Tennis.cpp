#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Player {  //运动员
    gg arrive, server, vip;  //到达时间、打球所需时间、是否为vip
    Player(gg a, gg s, gg v) : arrive(a), server(s), vip(v) {}
};
// tableNum==-1，表示playerNum号运动员于time时间到达，需分配空闲球台
// tableNum!=-1，表示playerNum号运动员占据了tableNum号球台，在time时间会离开
struct Action {
    gg tableNum, playerNum, time;
    Action(gg t, gg p, gg ti) : tableNum(t), playerNum(p), time(ti) {}
};
bool operator<(const Action& a1, const Action& a2) { return a1.time > a2.time; }
void output(gg time) {  //打印时间
    cout << setfill('0') << setw(2) << time / 3600 << ":" << setw(2)
         << time % 3600 / 60 << ":" << setw(2) << time % 60 << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ki, mi, ai;
    cin >> ni;
    gg endTime = 21 * 3600;
    vector<Player> players;
    priority_queue<Action> actions;
    for (gg i = 0; i < ni; ++i) {
        gg h, m, s, p, vip;
        char c;
        cin >> h >> c >> m >> c >> s >> p >> vip;
        //注意，打球时间超过2小时，按2小时计！
        players.push_back(
            Player(h * 3600 + m * 60 + s, min(p, 120ll) * 60, vip));
        actions.push(Action(-1, i, players[i].arrive));
    }
    cin >> ki >> mi;
    vector<gg> ans(ki);  //存储每个球台接待的次数
    vector<bool> vip(ki);  //球台是否为vip球台
    while (mi--) {
        cin >> ai;
        vip[ai - 1] = true;  //球台从0~k-1编号
    }
    set<gg> freeTables, freeVipTables;  //空闲的所有球台、空闲的vip球台
    list<gg> waitPlayers, waitVipPlayers;  //等待的所有球员、等待的vip球员
    //初始时所有球台均闲置
    for (gg i = 0; i < ki; ++i) {
        freeTables.insert(i);
        if (vip[i]) {
            freeVipTables.insert(i);
        }
    }
    while (not actions.empty()) {
        auto a = actions.top();
        actions.pop();
        if (a.time >= endTime) {  //超过营业时间，不再接待球员，跳出循环
            break;
        }
        if (a.tableNum == -1) {  //需为球员分配空闲球台
            if (freeTables.empty()) {  //没有空闲球台，该球员加入等待队列
                waitPlayers.push_back(a.playerNum);
                if (players[a.playerNum].vip) {
                    waitVipPlayers.push_back(a.playerNum);
                }
            } else {  //有空闲球台
                gg num = -1;  //存储分配的球台编号
                //是vip球员且有空闲的vip球台，分配编号最小的vip球台
                if (players[a.playerNum].vip and not freeVipTables.empty()) {
                    num = *freeVipTables.begin();
                    freeVipTables.erase(num);
                    freeTables.erase(num);
                } else {  //不是vip球员或是vip球员但没有空闲的vip球台，分配普通球台
                    num = *freeTables.begin();
                    freeTables.erase(num);
                    if (freeVipTables.count(num)) {
                        freeVipTables.erase(num);
                    }
                }
                actions.push(Action(num, a.playerNum,
                                    a.time + players[a.playerNum].server));
                ++ans[num];
                output(a.time);
                output(a.time);
                cout << "0\n";
            }
        } else {  //球员离开，释放球台
            if (waitPlayers.empty()) {  //没有等待的球员，球台闲置
                freeTables.insert(a.tableNum);
                if (vip[a.tableNum]) {
                    freeVipTables.insert(a.tableNum);
                }
            } else {  //有等待的球员
                gg num = -1;  //存储将该球台分配给的球员编号
                //是vip球台且有vip球员等待，分配给队列首位的vip球员
                if (vip[a.tableNum] and not waitVipPlayers.empty()) {
                    num = waitVipPlayers.front();
                    waitVipPlayers.pop_front();
                    waitPlayers.erase(
                        find(waitPlayers.begin(), waitPlayers.end(), num));
                } else {  //不是vip球台或是vip球台但没有vip球员等待，分配给队列首位的普通球员
                    num = waitPlayers.front();
                    waitPlayers.pop_front();
                    auto i =
                        find(waitVipPlayers.begin(), waitVipPlayers.end(), num);
                    if (i != waitVipPlayers.end()) {
                        waitVipPlayers.erase(i);
                    }
                }
                actions.push(
                    Action(a.tableNum, num, a.time + players[num].server));
                ++ans[a.tableNum];
                output(players[num].arrive);
                output(a.time);
                cout << round((a.time - players[num].arrive) / 60.0) << "\n";
            }
        }
    }
    for (gg i = 0; i < ki; ++i) {  //输出所有球台接待的次数
        cout << (i == 0 ? "" : " ") << ans[i];
    }
    return 0;
}