#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<regex,string>>trans={
        {regex("^\\* +(.*)"),"<li>$1</li>"},//无序列表
        {regex("_([^_]+)_"),"<em>$1</em>"},//强调
        {regex("\\[([^\\]]+)\\]\\(([^\\)]+)\\)"),"<a href=\"$2\">$1</a>"}//超链接
    };
    for(int i=1;i<=6;++i)//6中等级的标题
        trans.push_back({regex("^"+string(i,'#')+" +(.*)"),"<h"+to_string(i)+">$1</h"+to_string(i)+">"});
    vector<vector<string>>markdown(1);//按区块存储所有字符串
    string s="";
    while(getline(cin,s))//读取markdown文本
        if(s==""){//遇到空行
            markdown.push_back({});//新增区块
        }else
            markdown.back().push_back(s);
    for(auto&i:markdown){//遍历所有区块
        if(i.empty())//区块为空，不进行任何操作
            continue;
        int type=i[0][0]=='*'?0:i[0][0]=='#'?1:2;//type为0/1/2分别表示无序列表、标题、段落
        printf("%s",type==0?"<ul>\n":type==2?"<p>":"");//输出<ul>、<p>
        for(int j=0;j<i.size();++j){//遍历区块中所有字符串
            for(auto&k:trans)//遍历所有正则表达式进行替换
                i[j]=regex_replace(i[j],k.first,k.second);
            printf("%s%s",i[j].c_str(),j==i.size()-1?"":"\n");//输出该字符串
        }
        puts(type==0?"\n</ul>":type==2?"</p>":"");//输出</ul>、</p>
    }
    return 0;
}
