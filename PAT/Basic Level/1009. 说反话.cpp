//第一种方法：使用栈
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    stack<string> st;
    while (cin >> s) {
        st.push(s);
    }
    while (not st.empty()) {
        cout << st.top();
        st.pop();
        cout << (st.empty() ? "" : " ");
    }
    return 0;
}
//第二种方法：使用vector+反向迭代器
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    vector<string> v;
    while (cin >> s) {
        v.push_back(s);
    }
    for (auto i = v.rbegin(); i != v.rend(); ++i) {
        cout << (i == v.rbegin() ? "" : " ") << *i;
    }
    return 0;
}
