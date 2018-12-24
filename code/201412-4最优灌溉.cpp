#include<bits/stdc++.h>
using namespace std;
struct Edge{//边的类
    int v1,v2,cost;//边的两个端点，以及边的花费
    Edge(int vv1,int vv2,int c):v1(vv1),v2(vv2),cost(c) {}//构造函数
    bool operator <(const Edge&e)const{//重载小于运算符
        return this->cost>e.cost;
    }
};
int N,M,father[1005];
priority_queue<Edge>pq;//边的优先级队列
int findFather(int x){//查找并查集中某一顶点的根节点
    if(x==father[x])
        return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
void unionSet(int a,int b){//合并并查集的两个顶点
    int ua=findFather(a),ub=findFather(b);
    if(ua!=ub)
        father[ua]=ub;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        pq.push(Edge(a,b,c));
    }
    for(int i=0;i<N+1;++i)
        father[i]=i;
    int sumCost=0;
    while(!pq.empty()){
        Edge e=pq.top();//弹出一条边
        pq.pop();
        if(findFather(e.v1)!=findFather(e.v2)){
            unionSet(e.v1,e.v2);
            sumCost+=e.cost;
        }
    }
    printf("%d",sumCost);
    return 0;
}
