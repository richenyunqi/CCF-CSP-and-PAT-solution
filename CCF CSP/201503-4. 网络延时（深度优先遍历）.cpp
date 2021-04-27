#include<bits/stdc++.h>
using namespace std;
vector<int>tree[20005];//存储整棵树
int n,m,a,ansV=-1,ansLevel=0;//ansV表示距离最远的结点编号，ansLevel表示最远距离
bool visit[20005];//标记每个节点是否已被访问
void DFS(int v,int level){//深度优先遍历
    visit[v]=true;
    if(level>ansLevel){
        ansLevel=level;
        ansV=v;
    }
    for(int i:tree[v])
        if(!visit[i])
        DFS(i,level+1);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n+m;++i){
        scanf("%d",&a);
        tree[a].push_back(i);
        tree[i].push_back(a);//将树的边存储为无向边
    }
    DFS(1,0);//第一次深度优先遍历
    memset(visit,0,sizeof(visit));
    DFS(ansV,0);//二次遍历
    printf("%d",ansLevel);
    return 0;
}
