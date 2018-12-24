#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;//ans存储最终结果
    scanf("%d",&n);
    vector<pair<int,int>>v1(n),v2(n);//分别存储小H和小W的装车时间段
    for(int i=0;i<n;++i)
        scanf("%d%d",&v1[i].first,&v1[i].second);
    for(int i=0;i<n;++i)
        scanf("%d%d",&v2[i].first,&v2[i].second);
    for(pair<int,int>p1:v1)
        for(pair<int,int>p2:v2)
            if(p1.first<=p2.second&&p1.second>=p2.first)//判断有无重叠区间
                ans+=min(p1.second,p2.second)-max(p1.first,p2.first);//加上重叠区间
    printf("%d",ans);
    return 0;
}
