#include<bits/stdc++.h>
using namespace std;
const int MAXV=10005;
vector<int>graph[MAXV],reverseGraph[MAXV];//图G和置换图Gr
bool visit[MAXV];
stack<int>s;
int N,M,result=0;
void DFS(int v){//对图G做深度优先遍历
    visit[v]=true;
    for(int i=0;i<graph[v].size();++i)
        if(!visit[graph[v][i]])
            DFS(graph[v][i]);
    s.push(v);//压栈
}
void DFS(int v,int&num){//对图Gr做深度优先遍历
    visit[v]=true;
    ++num;//该连通分支下顶点个数+1
    for(int i=0;i<reverseGraph[v].size();++i)
        if(!visit[reverseGraph[v][i]])
            DFS(reverseGraph[v][i],num);
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }
    for(int i=1;i<=N;++i)
        if(!visit[i])
            DFS(i);
    fill(visit+1,visit+N+1,false);
    while(!s.empty()){
        int t=s.top(),num=0;
        s.pop();
        if(!visit[t]){
            DFS(t,num);
            result+=num*(num-1)/2;
        }
    }
    printf("%d",result);
    return 0;
}
