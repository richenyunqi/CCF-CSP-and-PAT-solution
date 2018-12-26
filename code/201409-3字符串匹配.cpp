#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;//读取需要匹配的字符串
    int n,m;
    scanf("%d%d%*c",&m,&n);
    regex r("[[:alpha:]]*"+s+"[[:alpha:]]*");//[:alpha:]表示任意字符，*表示0个或多个这样的字符
    if(m==0)//m是0，利用regex::icase标志，表示匹配时忽略大小写
        r=regex("[[:alpha:]]*"+s+"[[:alpha:]]*",regex::icase);
    while(n--){
        getline(cin,s);//读取要匹配的字符串
        if(regex_match(s,r))//匹配成功
            puts(s.c_str());//输出
    }
    return 0;
}
