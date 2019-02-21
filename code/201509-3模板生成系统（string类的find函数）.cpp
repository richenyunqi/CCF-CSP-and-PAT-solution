#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    scanf("%d%d%*c",&m,&n);
    vector<string>html;
    string line;
    while(m--){
        getline(cin,line);
        html.push_back(line);
    }
    unordered_map<string,string>strReplace;
    while(n--){
        getline(cin,line);
        int t=line.find(' ');//查找第一个空格字符的位置，该空格字符可以用来分割变量名和值
        string s1=line.substr(0,t),s2=line.substr(t+2,line.size()-t-3);//s1存储变量名，s2存储去除首尾"字符的值
        strReplace[s1]=s2;//将变量名和值对应起来
    }
    for(string&i:html){
        int j=0;
        for(j=0;j<i.size();){
            int k1=i.find("{{ ",j),k2=i.find(" }}",j);//查找"{{ "和" }}"的位置
            if(k1==string::npos&&k2==string::npos)//没有匹配成功的子字符串，跳出循环
                break;
            for(;j<k1;++j)//输出从开始搜索的位置到匹配成功的子字符串的起始位置的所有字符
                printf("%c",i[j]);
            auto k=strReplace.find(i.substr(k1+3,k2-k1-3));//查看strReplace中是否有相应的变量名
            printf("%s",k!=strReplace.end()?(k->second).c_str():"");//输出变量名对应的值
            j=k2+3;//将下一个开始搜索位置更新为当前匹配成功的子字符串的末尾位置
        }
        for(;j<i.size();++j)//输出从最后一个匹配成功的子字符串的末尾位置到整个字符串末尾位置的所有字符
            printf("%c",i[j]);
        puts("");//换行
    }
    return 0;
}
