#include<bits/stdc++.h>
using namespace std;
struct Vertex{
    int r,c,t;
    Vertex(int rr,int cc,int tt):r(rr),c(cc),t(tt) {}
};
bool inQueue[105][105][305];//标志一个结点是否已入队
int n,m,t,direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//方向
int main(){
    scanf("%d%d%d",&n,&m,&t);
    while(t--){
        int r,c,a,b;
        scanf("%d%d%d%d",&r,&c,&a,&b);
        for(int i=a;i<=b;++i)//将处于危险时间段内的格子直接标志为已入过队
            inQueue[r][c][i]=true;
    }
    queue<Vertex>q;
    q.push(Vertex(1,1,0));
    inQueue[1][1][0]=true;
    while(!q.empty()){
        Vertex v=q.front();
        q.pop();
        if(v.r==n&&v.c==m){//到达了终点，输出时间
            printf("%d",v.t);
            return 0;
        }
        for(int i=0;i<4;++i){
            int r=v.r+direction[i][0],c=v.c+direction[i][1],t=v.t+1;
            if(r>0&&r<=n&&c>0&&c<=m&&!inQueue[r][c][t]){
                q.push(Vertex(r,c,t));
                inQueue[r][c][t]=true;
            }
        }
    }
    return 0;
}
