#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Window {
    gg num, x1, y1, x2, y2;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    list<Window> windows(ni);
    gg num = 1;
    //输入是按从最下层到最顶层的顺序输入的，要用反向迭代器读取
    for (auto i = windows.rbegin(); i != windows.rend(); ++i) {
        cin >> i->x1 >> i->y1 >> i->x2 >> i->y2;
        i->num = num++;
    }
    gg x, y;
    while (mi--) {
        cin >> x >> y;
        auto i =  //查找第一个包含点击点的窗口
            find_if(windows.begin(), windows.end(), [x, y](const Window& w) {
                return w.x1 <= x and w.x2 >= x and w.y1 <= y and w.y2 >= y;
            });
        if (i == windows.end()) {  //没有这样的窗口
            cout << "IGNORED\n";
            continue;
        }
        cout << i->num << "\n";
        windows.push_front(*i);  //插入到链表头部
        windows.erase(i);
    }
    return 0;
}
