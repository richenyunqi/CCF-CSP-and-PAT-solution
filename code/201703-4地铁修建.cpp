#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v,cost;
    bool operator <(const Edge&e)const{//重载小于运算符
        return this->cost>e.cost;
    }
};
vector<Edge>graph[100005];//图
int N,M,result=0;
bool visit[100005];//当前顶点是否已访问过
int main(){
    scanf("%d%d",&N,&M);
    while(M--){//读取数据，注意所给图为无向图
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    priority_queue<Edge>pq;//优先级队列
    int current=1;//当前处理的顶点
    while(current!=N){//当前处理的顶点不是N时继续循环
        visit[current]=true;//当前顶点已访问
        for(int i=0;i<graph[current].size();++i)//遍历当前顶点能到达的顶点
            if(!visit[graph[current][i].v])//如果没有访问过
                pq.push(graph[current][i]);//压入优先级队列
        Edge e=pq.top();//获取队首元素
        pq.pop();
        current=e.v;//更新current为当前cost最小的顶点
        result=max(result,e.cost);//更新result
    }
    printf("%d",result);
    return 0;
}
