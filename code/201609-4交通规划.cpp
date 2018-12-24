#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v,cost;
};
vector<Edge>graph[10005];//图
int N,M,result=0;
bool visit[10005];//当前顶点是否已访问过
int dis[10005],cost[10005];
void Dijkstra(){
    for(int ii=0;ii<N;++ii){//循环N次
        int v=-1,MIN=INT_MAX;
        for(int i=1;i<=N;++i)//得出当前有最短距离的未被访问的结点
            if(!visit[i]&&dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
        visit[v]=true;//当前结点已访问过
        result+=cost[v];//将到达当前结点的边长加和到最终结果中
        for(int i=0;i<graph[v].size();++i){//遍历当前结点能到达的结点
            int temp=graph[v][i].v;
            //取最短距离，如果最短距离相等，取到达结点最小的边
            if((!visit[temp]&&dis[temp]>dis[v]+graph[v][i].cost)||(dis[temp]==dis[v]+graph[v][i].cost&&cost[temp]>graph[v][i].cost)){
                dis[temp]=dis[v]+graph[v][i].cost;
                cost[temp]=graph[v][i].cost;
            }
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){//读取数据，注意所给图为无向图
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    fill(dis+2,dis+N+1,INT_MAX);
    Dijkstra();
    printf("%d",result);
    return 0;
}
