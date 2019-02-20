#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>category;//存储权限类名和对应的最高等级
unordered_map<string,unordered_map<string,int>>role,user;//存储角色、用户和对应的权限名及等级
pair<string,int> split(string&s){//分割权限类名和等级
    int i=s.find(':');
    int level=(i!=string::npos)?stoi(s.substr(i+1)):-1;
    return make_pair(s.substr(0,i),level);
}
int main(){
    int p,r,t,q,n;
    string s1,s2;
    scanf("%d",&p);
    while(p--){//读取权限类名和最高等级
        cin>>s1;
        category.insert(split(s1));
    }
    scanf("%d",&r);
    while(r--){//读取角色名和对应的权限类名和等级
        cin>>s1>>n;
        while(n--){
            cin>>s2;
            pair<string,int>p=split(s2);
            if(role[s1].find(p.first)!=role[s1].end())
                role[s1][p.first]=min(max(role[s1][p.first],p.second),category[p.first]);
            else
                role[s1][p.first]=min(p.second,category[p.first]);
        }
    }
    scanf("%d",&t);
    while(t--){//读取用户名和对应的角色名
        cin>>s1>>n;
        while(n--){
            cin>>s2;
            for(auto&i:role[s2])//遍历对应的角色名，将权限、等级和用户对应存储起来
                if(user[s1].find(i.first)!=user[s1].end())
                    user[s1][i.first]=max(i.second,user[s1][i.first]);
                else
                    user[s1][i.first]=i.second;
        }
    }
    scanf("%d",&q);
    while(q--){//查询
        cin>>s1>>s2;
        pair<string,int>p=split(s2);
        if(user.find(s1)!=user.end()&&user[s1].find(p.first)!=user[s1].end()
                &&p.second<=user[s1][p.first]){
            if(p.second==-1&&user[s1][p.first]!=-1)
                printf("%d\n",user[s1][p.first]);
            else
                puts("true");
        }else
            puts("false");
    }
    return 0;
}
