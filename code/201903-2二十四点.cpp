#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    queue<int>num;//存储加减法的操作数和乘除法的结果
    queue<char>op;//存储+、-符号
    while(n--){
        cin>>s;
        s.push_back('+');//在每个表达式末尾加上"+"字符
        for(int i=1;i<s.size();i+=2){//遍历整个字符串
            int t=s[i-1]-'0';
            for(;i<s.size()&&s[i]=='x'||s[i]=='/';i+=2){//求出连续乘除运算的结果
                t=(s[i]=='x')?t*(s[i+1]-'0'):t/(s[i+1]-'0');
            }
            num.push(t);
            op.push(s[i]);
        }
        num.push(0);//加减法操作数再放入一个0，保证在整个表达式末尾添上了+0运算
        int t=num.front();//第一个加减法操作数
        num.pop();
        while(!op.empty()){//同时遍历两个队列，求出加减运算的结果
            char c=op.front();
            op.pop();
            t=(c=='+')?t+num.front():t-num.front();
            num.pop();
        }
        puts(t==24?"Yes":"No");
    }
    return 0;
}
