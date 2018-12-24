#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1005];
bool visit[1005];
int N,M;
bool know[1005][1005];
void DFS(int v,int start){
    visit[v]=true;
    know[start][v]=know[v][start]=true;
    for(int i=0;i<graph[v].size();++i)
        if(!visit[graph[v][i]])
            DFS(graph[v][i],start);
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    int result=0;
    for(int i=1;i<=N;++i){
        fill(visit+1,visit+N+1,false);
        DFS(i,i);
    }
    for(int i=1;i<=N;++i)
        if(count(know[i]+1,know[i]+N+1,true)==N)
            ++result;
    printf("%d",result);
    return 0;
}
