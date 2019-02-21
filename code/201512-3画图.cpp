#include<bits/stdc++.h>
using namespace std;
char graph[105][105];//整个图
int m,n,q,command,direct[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//4个方向
void DFS(int i,int j,char c){//填充字符
    if(i<0||i>=n||j<0||j>=m//超出画布
            ||graph[i][j]=='-'||graph[i][j]=='|'||graph[i][j]=='+'//是线段的一部分
            ||graph[i][j]==c)//已经填充过
        return;//直接返回
    graph[i][j]=c;//进行填充
    for(int k=0;k<4;++k)//递归处理4个周边坐标
        DFS(i+direct[k][0],j+direct[k][1],c);
}
int main(){
    scanf("%d%d%d",&m,&n,&q);
    memset(graph,'.',sizeof(graph));
    while(q--){
        scanf("%d",&command);
        if(command==0){//画线
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1>x2)//x1存储x1和x2之间的最小值，x2存储x1和x2之间的最大值
                swap(x1,x2);
            if(y1<y2)//y1存储y1和y2之间的最小值，y2存储y1和y2之间的最大值
                swap(y1,y2);
            if(x1!=x2)
                for(int i=x1;i<=x2;++i)
                    if(graph[n-1-y1][i]=='|'||graph[n-1-y1][i]=='+')
                        graph[n-1-y1][i]='+';
                    else
                        graph[n-1-y1][i]='-';
            else
                for(int i=y1;i>=y2;--i)
                    if(graph[n-1-i][x1]=='-'||graph[n-1-i][x1]=='+')
                        graph[n-1-i][x1]='+';
                    else
                        graph[n-1-i][x1]='|';
        }else{//填充字符
            int x,y;
            char c;
            scanf("%d%d %c",&x,&y,&c);
            DFS(n-1-y,x,c);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            printf("%c",graph[i][j]);
        puts("");
    }
    return 0;
}
