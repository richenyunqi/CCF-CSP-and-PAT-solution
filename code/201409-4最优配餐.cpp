#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//由某点可到达的四个位置
int graph[1005][1005];//相应元素值<0、==0、>0分别表示不能通过位置、能通过位置、客户位置
bool inQueue[1005][1005];
struct Position{
    int x,y,cost;//横坐标、纵坐标，到达该位置时的最短路径长
    Position(int xx,int yy,int c=0):x(xx),y(yy),cost(c) {}
};
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&d);
    queue<Position>q;
    int a,b,c;
    long long ans=0;//最终结果需用long long储存
    while(m--){
        scanf("%d%d",&a,&b);
        q.push(Position(a,b));//将源点都压入队列中
        inQueue[a][b]=true;//源点都已入队
    }
    while(k--){
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b]+=c;//同一个位置可以有多个客户，使用+=，而不是直接赋值
    }
    while(d--){
        scanf("%d%d",&a,&b);
        graph[a][b]=-1;//不能通过的位置置-1
    }
    while(!q.empty()){
        Position p=q.front();
        q.pop();
        if(graph[p.x][p.y]>0)//该位置是客户位置
            ans+=(long long)p.cost*graph[p.x][p.y];//累加花费
        for(int i=0;i<4;++i){//遍历该位置能到达的位置
            int ii=p.x+direction[i][0],jj=p.y+direction[i][1];//下一个可到达的位置
            if(ii>0&&ii<=n&&jj>0&&jj<=n&&graph[ii][jj]>=0&&!inQueue[ii][jj]){
                q.push(Position(ii,jj,p.cost+1));
                inQueue[ii][jj]=true;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
