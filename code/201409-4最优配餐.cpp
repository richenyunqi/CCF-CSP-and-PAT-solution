#include<bits/stdc++.h>
using namespace std;
int N,M,K,D;
bool visit[1005][1005];
int graph[1005][1005];//相应元素值<0、==0、>0分别表示不能通过位置、能通过位置、客户位置
struct Tuple{
    int i,j,cost;//横坐标、纵坐标，到达该位置时的最短路径长
    Tuple(int ii,int jj,int c):i(ii),j(jj),cost(c) {}
};
bool outOfBorder(int i,int j){//是否越界
    return i<1||j<1||i>N||j>N||graph[i][j]<0;
}
int main(){
    scanf("%d%d%d%d",&N,&M,&K,&D);
    queue<Tuple>q;
    int a,b,c;
    for(int i=0;i<M;++i){
        scanf("%d%d",&a,&b);
        q.push(Tuple(a,b,0));//将源点都压入队列中
    }
    for(int i=0;i<K;++i){
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b]+=c;
    }
    for(int i=0;i<D;++i){
        scanf("%d%d",&a,&b);
        graph[a][b]=-1;//不能通过的位置置-1
    }
    int direction[4][2]={
        {-1,0},{0,1},{1,0},{0,-1}//由某点可到达的四个位置，上右下左顺序
    };
    long long sumCost=0;//最终结果需用long long储存
    while(!q.empty()){//开始BFS遍历
        Tuple p=q.front();
        q.pop();
        if(visit[p.i][p.j])//该点已访问过，不进行操作，直接继续循环
            continue;
        visit[p.i][p.j]=true;
        if(graph[p.i][p.j]>0)//该位置是客户位置
            sumCost+=(long long)p.cost*graph[p.i][p.j];//累加花费
        for(int j=0;j<4;++j)//遍历该位置能到达的位置
            if(!outOfBorder(p.i+direction[j][0],p.j+direction[j][1])&&!visit[p.i+direction[j][0]][p.j+direction[j][1]])
                q.push(Tuple(p.i+direction[j][0],p.j+direction[j][1],p.cost+1));
    }
    printf("%lld",sumCost);
    return 0;
}
