#include<bits/stdc++.h>
using namespace std;
struct Router{//路由器
    long long x,y;//坐标
    int cost=0,addNum=0;//经过的路由器个数、增设的路由器个数
    bool add;//是否是增设的路由器
    Router(long long xx,long long yy,bool a=false):x(xx),y(yy),add(a) {}
};
int n,m,k,r;
vector<Router>routers;//存储路由器
inline bool canReach(int i,int j){//计算两个路由器之间的距离是否超过r
    return (routers[i].x-routers[j].x)*(routers[i].x-routers[j].x)+
            (routers[i].y-routers[j].y)*(routers[i].y-routers[j].y)<=(long long)r*r;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&r);
    long long a,b;
    while(n--){
        scanf("%lld%lld",&a,&b);
        routers.push_back(Router(a,b));
    }
    while(m--){
        scanf("%lld%lld",&a,&b);
        routers.push_back(Router(a,b,true));
    }
    vector<bool>inQueue(routers.size(),false);//标志一个路由器是否已经入过队
    queue<int>q;
    q.push(0);
    inQueue[0]=true;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t==1)//到达1号结点，跳出循环
            break;
        for(int i=0;i<routers.size();++i)//遍历所有路由器
            if(!inQueue[i]&&canReach(t,i)){//没有入过队且从t号路由器可以到达该路由器
                if(routers[i].add&&routers[t].addNum+1>k)//如果该路由器是增设路由器且增设的路由器超过了k
                    continue;//不进行任何操作
                routers[i].cost=routers[t].cost+1;//经过的路由器个数+1
                routers[i].addNum=routers[t].addNum+(routers[i].add?1:0);//更新经过的增设路由器个数
                inQueue[i]=true;
                q.push(i);//入队
            }
    }
    printf("%d",routers[1].cost-1);//输出
    return 0;
}
