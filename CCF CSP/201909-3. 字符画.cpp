#include <bits/stdc++.h>
using namespace std;
void output(string& s, array<int, 3> rgb = {0, 0, 0}) {  //输出
    for (char c : s)
        if (c == 'R' || c == 'G' || c == 'B') {  //是RGB数值
            string t = to_string(rgb[c == 'R' ? 0 : c == 'G' ? 1 : 2]);  //将数值转换成字符串
            for (char cc : t)  //遍历字符串
                printf("\\x%02X", cc);  //输出16进制数
        } else
            printf("\\x%02X", c);  //输出字符的16进制数
}
int main() {
    string back = "\x1b[48;2;R;G;Bm", reset = "\x1b[0m";  //背景色和重置默认值字符串
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    vector<vector<array<int, 3>>> image(n);  //图像像素
    string rgb;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> rgb;
            if (rgb.size() == 2)  //只有2位字符
                rgb += string(5, rgb.back());  //字符串末尾添加5个末尾字符
            else if (rgb.size() == 4)  //只有4位字符
                rgb = "#" + string(2, rgb[1]) + string(2, rgb[2]) + string(2, rgb[3]);  //添加成为6位
            image[i].push_back({0, 0, 0});
            for (int t = 0; t < 3; ++t)  //计算RGB数值，将16进制数转换成10进制
                image[i].back()[t] = stoi(rgb.substr(2 * t + 1, 2), 0, 16);
        }
    }
    array<int, 3> last = {0, 0, 0}, start = {0, 0, 0};
    for (int i = 0; i < n / q; ++i) {  //遍历所有像素
        for (int j = 0; j < m / p; ++j) {
            array<int, 3> cur = {0, 0, 0};
            for (int r = 0; r < q; ++r) {  //计算块内RGB颜色分量之和
                for (int s = 0; s < p; ++s) {
                    for (int t = 0; t < 3; ++t)
                        cur[t] += image[i * q + r][j * p + s][t];
                }
            }
            for (int t = 0; t < 3; ++t)  //计算RGB颜色分量平均值
                cur[t] /= p * q;
            if (cur != last)  //和上一个块颜色分量不同
                if (cur == start)  //和默认颜色分量一致，输出重置转义序列
                    output(reset);
                else
                    output(back, cur);
            last = cur;  //更新上一个状态为当前状态
            printf("\\x%02X", ' ');  //每一个块后输出一个空格
        }
        if (last != start)  //每一行结束后恢复默认状态
            output(reset);
        last = start;  //每一行结束后更新上一个状态位默认状态
        printf("\\x%02X", '\n');  //每一行字符后输出一个换行
    }
    return 0;
}