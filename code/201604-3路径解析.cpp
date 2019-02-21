#include<bits/stdc++.h>
using namespace std;
void split(string&p,vector<string>&v){//按字符/分割字符串
    for(int i=0,j;i<p.size();i=j){//遍历字符串
        j=p.find('/',i);//j表示从位置i开始的字符/在字符串p中的下标
        if(j==string::npos)//到达字符串末尾
            v.push_back(p.substr(i));//将分割得到的字符串放入v中
        else
            v.push_back(p.substr(i,j-i));//将分割得到的字符串放入v中
        while(j<p.size()&&p[j]=='/')//更新j为下一个非/字符的下标
            ++j;
    }
}
int main(){
    int n;
    scanf("%d%*c",&n);
    vector<string>cur;//存储当前目录
    string path;
    getline(cin,path);
    split(path,cur);//按字符/分割当前目录
    while(getline(cin,path)){
        vector<string>v,ans;
        split(path,v);//按字符/分割路径
        if(v.empty()||v[0]=="."){//路径为空或者路径的第一个目录为字符.
            ans=cur;//将路径赋值为当前目录
        }else if(v[0]=="")//路经的第一个目录为根目录
            ans.push_back("");//将根目录放入ans中
        else if(v[0]==".."){//路经的第一个目录为..
            ans=cur;//将路径赋值为当前目录
            ans.pop_back();//更新为当前目录的父目录
        }else{//其他情况
            ans=cur;//将路径赋值为当前目录
            ans.push_back(v[0]);//将路径的第一个目录或文件放入ans中
        }
        for(int j=1;j<v.size();++j)//从路径的第2个目录或文件开始遍历
            if(v[j]==".."){//求父目录
                if(ans.size()>1)//当前得到的路径中的目录等于1时代表根目录，只有大于1时才能弹出莫为元素
                    ans.pop_back();//弹出末尾元素
            }else if(v[j]!=".")//是本目录，不进行任何操作;否则将下一个目录或文件放入ans
                ans.push_back(v[j]);
        if(ans.size()==1&&ans[0]=="")//ans的第一个目录是根目录且ans只有一个目录或文件
            printf("/");//输出/
        else//否则输出ans的第一个目录或文件
            printf("%s",ans[0].c_str());
        for(int j=1;j<ans.size();++j)//从ans的第2个目录或文件开始输出
            printf("/%s",ans[j].c_str());
        puts("");//换行
    }
    return 0;
}
