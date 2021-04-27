#include<bits/stdc++.h>
using namespace std;
struct element{
    int father;//父元素所在行号
    string label,id;//标签、id属性
};
vector<element>elements(105);//从下标1开始存储所有元素，下标代表每个元素所在行号
vector<vector<int>>series;
int main(){
    int n,m;
    string line;
    scanf("%d%d%*c",&n,&m);
    for(int i=1;i<=n;++i){
        getline(cin,line);
        int j=0,k=0;
        while(line[j]=='.')//循环结束后j就表示小数点数量，line[j]表示第一个非小数点的字符
            ++j;
        for(k=j;k<line.size()&&line[k]!=' ';++k);//循环结束后,k就表示字符串末尾或字符串中空格位置
        if(series.size()<=j/2)//series还没有下标为j/2的元素
            series.push_back({i});//压入一个初始化为当前元素所在行号的vector
        else//series有下标为j/2的元素
            series[j/2].push_back(i);//直接把行号压入
        elements[i].label=line.substr(j,k-j);//取标签字符串
        for(auto&c:elements[i].label)//将元素的标签中的英文字符都变为小写字符
            c=tolower(c);
        elements[i].id=(k==line.size())?"":line.substr(k+1);//取id属性字符串
        elements[i].father=j/2-1<0?-1:series[j/2-1].back();//求父元素所在行号
    }
    while(m--){
        getline(cin,line);
        vector<string>query;//存储查询的元素
        for(int i=0;i<line.size();++i){//遍历读取的一行字符串
            int j=i;
            while(j<line.size()&&line[j]!=' ')
                ++j;
            string s=line.substr(i,j-i);
            if(s[0]!='#')//将标签中所有字符转换为小写字符
                for(auto&c:s)
                    c=tolower(c);
            query.push_back(s);
            i=j;
        }
        vector<int>ans;
        for(int i=query.size()-1;i<series.size();++i)//从query.size()-1开始遍历
            for(int j:series[i])//遍历当前series[i]中的元素行号
                if(elements[j].label==query.back()||elements[j].id==query.back()){//如果标签或id等于最低查询元素
                    int k=query.size()-2;//k指向查询的倒数第2个元素
                    for(int p=elements[j].father;k>=0&&p!=-1;p=elements[p].father)//遍历行号为p元素的祖先元素行号
                        if(elements[p].label==query[k]||elements[p].id==query[k])//如果与当前查询的元素相同
                            --k;//继续查询前面的元素
                    if(k<0)//所有元素均已查询到，该元素符合要求
                        ans.push_back(j);//压入ans中
                }
        printf("%d ",ans.size());//输出
        for(auto i:ans)
            printf("%d ",i);
        puts("");//换行
    }
    return 0;
}
