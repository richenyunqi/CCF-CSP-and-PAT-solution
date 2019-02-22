#include<bits/stdc++.h>
using namespace std;
int main(){
    int type[128]={0};//1表示无参数选项，2表示有参数选项
    string s,t;
    cin>>s;
    for(int i=0;i<s.size();++i)
        if(s[i+1]==':')//有参数选项
            type[s[i++]]=2;//置type为2
        else//无参数选项
            type[s[i]]=1;//置type为1
    int n;
    scanf("%d%*c",&n);
    for(int ii=1;ii<=n;++ii){
        getline(cin,s);
        stringstream ss(s);//用stringstream来分割字符串
        map<char,string>ans;//存储最终结果
        ss>>s;//命令行工具名
        while(ss>>s){//读取每个命令行选项
            if(s.size()==2&&s[0]=='-'&&type[s[1]]==1){//是无参数选项
                ans[s[1]]="";//存储到ans中，置值为空字符串
            }else if(s.size()==2&&s[0]=='-'&&type[s[1]]==2&&ss>>t){//有参数选项且参数为t
                ans[s[1]]=t;//存储到ans中，置值为t
            }else//其他情况，直接跳出循环
                break;
        }
        printf("Case %d:",ii);//输出
        for(auto&j:ans)
            printf(" -%c%s",j.first,(j.second=="")?"":(" "+j.second).c_str());
        puts("");
    }
    return 0;
}
