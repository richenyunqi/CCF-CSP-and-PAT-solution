#include<bits/stdc++.h>
using namespace std;
const int MAXV=20005;
vector<int>tree[MAXV];//存储整棵树
int len[MAXV],N,M;//len存储从源点到达每个节点的路径
bool visit[MAXV];//标记每个节点是否已被访问
void DFS(int root){//深度优先遍历
    visit[root]=true;
    for(int i=0;i<tree[root].size();++i)
        if(!visit[tree[root][i]]){
            len[tree[root][i]]=len[root]+1;//获取到达当前节点的路径长度
            DFS(tree[root][i]);
        }
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=2;i<=N+M;++i){
        int a;
        scanf("%d",&a);
        tree[a].push_back(i);
        tree[i].push_back(a);//将树的边存储为无向边
    }
    DFS(1);//第一次深度优先遍历
    int temp=max_element(len+1,len+N+M+1)-len;//C++标准库函数max_element返回指向序列中值最大的指针
    fill(visit+1,visit+N+M+1,false);
    fill(len+1,len+N+M+1,0);
    DFS(temp);//二次遍历
    printf("%d",*(max_element(len+1,len+N+M+1)));//输出最大长度
    return 0;
}
