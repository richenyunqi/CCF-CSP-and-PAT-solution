#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,a;
    scanf("%d",&N);
    unordered_map<int,int>m;
    for(int i=0;i<N;++i){
        scanf("%d",&a);
        ++m[a];//将读取的数字出现次数递增
    }
    vector<pair<int,int>>v;
    for(auto i:m)//将map中元素搬迁到vector中,注意first表示数字,second表示数字出现的次数
        v.push_back(i);
    sort(v.begin(),v.end(),[](const pair<int,int>&p1,const pair<int,int>&p2){
        return p1.second!=p2.second?p1.second>p2.second:p1.first<p2.first;
    });//排序
    //输出
    for(auto i:v)
        printf("%d %d\n",i.first,i.second);
    return 0;
}
