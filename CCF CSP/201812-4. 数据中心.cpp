#include<bits/stdc++.h>
using namespace std;
struct Edge{//边的类
    int v1,v2,cost;
    Edge(int vv1,int vv2,int c):v1(vv1),v2(vv2),cost(c){}
    bool operator <(const Edge&e)const{//重载小于运算符
        return this->cost>e.cost;
    }
};
priority_queue<Edge>edges;
int father[50005];//并查集
int findFather(int x){//查找根结点并进行路径压缩
    if(father[x]==x)
        return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
int main(){
    int n,m,root,ans=0;
    scanf("%d%d%d",&n,&m,&root);
    iota(father,father+n+1,0);//初始化并查集
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges.push(Edge(a,b,c));
    }
    while(!edges.empty()){
        Edge e=edges.top();
        edges.pop();
        int ua=findFather(e.v1),ub=findFather(e.v2);
        if(ua!=ub){//边的两个端点不属于同一个集合
            father[ua]=ub;
            ans=e.cost;//更新最长边
        }
    }
    printf("%d",ans);
    return 0;
}
