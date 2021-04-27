#include<bits/stdc++.h>
using namespace std;
vector<int>tree[20005];//存储整棵树
int n,m,a;
int dp1[20005],dp2[20005];
void DP(int v){//深度优先遍历
    int max1=0,max2=0;
    for(int i:tree[v]){
        DP(i);
        if(dp1[i]+1>max1){//计算到根结点v到叶子结点的最远距离
            max2=max1;
            max1=dp1[i]+1;
        }else if(dp1[i]+1>max2)//计算到根结点v到叶子结点的第二远距离
            max2=dp1[i]+1;
    }
    dp1[v]=max1;
    dp2[v]=max1+max2;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n+m;++i){
        scanf("%d",&a);
        tree[a].push_back(i);
    }
    DP(1);
    printf("%d",*max_element(dp2+1,dp2+n+m+1));//dp2中最大值即为所求
    return 0;
}
