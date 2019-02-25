#include<bits/stdc++.h>
using namespace std;
const int MAX=10005;
vector<int>graph[MAX];
//index[i]表示i是第几个被访问的结点,lowLink[i]表示从i出发经有向边可到达的所有节点中最小的index,sccno[i]表示i所属的强连通分量的编号
int index[MAX],lowLink[MAX],sccno[MAX],dfsNo=0,scc_cnt=0;
int ans=0;//最终结果
stack<int>s;
void DFS(int v){
    index[v]=lowLink[v]=++dfsNo;
    s.push(v);
    for(int i:graph[v]){
        if(index[i]==0){
            DFS(i);
            lowLink[v]=min(lowLink[v],lowLink[i]);
        }else if(sccno[i]==0)
            lowLink[v]=min(lowLink[v],index[i]);
    }
    if(lowLink[v]==index[v]){//是一个强连通分支的根结点
        ++scc_cnt;
        int t,num=0;//num表示该强连通分量中结点的个数
        do{
            t=s.top();
            s.pop();
            ++num;
            sccno[t]=scc_cnt;
        }while(t!=v);
        ans+=(num-1)*num/2;//加上该强连通分量中的便利城市对个数
    }
}
int main(){
    int n,m,k,a,b;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;++i)
        if(index[i]==0)
            DFS(i);
    printf("%d",ans);
    return 0;
}
