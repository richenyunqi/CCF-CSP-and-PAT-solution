#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10005],path;//图、欧拉路径
int N,M;
bool visit[10005][10005];//表示边是否已被访问
bool f(vector<int>&v){//顶点v的度数是否为奇数
    return v.size()%2==1;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){//读取数据，注意所给图为无向图
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=N;++i)//排序
        sort(graph[i].begin(),graph[i].end());
    stack<int>s;
    s.push(1);//1号顶点入栈
    while(!s.empty()){
        int v=s.top(),i;
        for(i=0;i<graph[v].size();++i){//遍历该点能到达的结点
            int w=graph[v][i];
            if(!visit[v][w]){//该边没有被访问过
                s.push(w);//顶点w入栈
                visit[v][w]=visit[w][v]=true;//该边已被访问
                break;//跳出循环
            }
        }
        if(i==graph[v].size()){//没有还未访问的边
            path.push_back(v);//顶点v加入欧拉序列
            s.pop();//出栈
        }
    }
    int k=count_if(graph+1,graph+N+1,f);//度数为奇数的顶点个数
    if(path.size()==M+1&&(k==0||(k==2&&f(graph[1]))))
        for(auto i=path.rbegin();i!=path.rend();++i)//倒序输出
            printf("%d ",*i);
    else
        printf("-1");
    return 0;
}
