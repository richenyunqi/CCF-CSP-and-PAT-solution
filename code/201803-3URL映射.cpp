#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d%*c",&n,&m);
    string p,r;
    vector<pair<string,regex>>rules;//存储URL规则，映射为规则名->规则的正则表达式
    vector<pair<regex,string>>trans={
        {regex("<int>"),"([0-9]+)"},{regex("<str>"),"([^/]+)"},{regex("<path>"),"(.+)"}
    };
    while(n--){
        cin>>p>>r;
        for(auto&i:trans)
            p=regex_replace(p,i.first,i.second);//将规则转换为对应的正则表达式
        rules.push_back({r,regex(p)});//按输入顺序压入rules中
    }
    smatch result;
    while(m--){
        cin>>p;
        for(auto i:rules)//对每条规则逐一进行匹配
            if(regex_match(p,result,i.second)){//匹配成功
                printf("%s",i.first.c_str());//输出规则名
                for(auto i=1;i<=result.size();++i){//遍历每一个匹配到的元组
                    p=result.str(i).c_str();
                    while(p[0]=='0')//去掉前导0
                        p.erase(0,1);
                    printf(" %s",p.c_str());//输出
                }
                puts("");//换行
                goto loop;//匹配成功，直接匹配下一个URL地址
            }
        puts("404");//没有匹配到任何一个规则，输出404
        loop:;
    }
    return 0;
}
