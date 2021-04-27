#include<bits/stdc++.h>
using namespace std;
struct Record{
    int type;//type表示该操作类型，buy为0，sell为1，cancel为2
    long long s;//股数
    double p;//成交价
    bool cancel;//该记录是否被取消
    Record(int t,long long ss,double pp=0.0,bool c=false):type(t),s(ss),p(pp),cancel(c){}
};
vector<Record>records={Record(-1,0)};//存储读取的每行数据
bool cmp(int a,int b){//排序函数，按出价从大到小排序
    return records[a].p>records[b].p;
}
int main(){
    vector<int>buy,sell;
    string str;
    double p;
    int s;
    while(cin>>str){//读取每行数据
        if(str=="cancel"){
            scanf("%d",&s);
            records.push_back(Record(2,0));
            records[s].cancel=true;
        }else{
            scanf("%lf%lld",&p,&s);
            records.push_back(Record(str=="buy"?0:1,s,p));
        }
    }
    long long buyS=0,sellS=0,ansS=0;//买单的总股数、卖单的总股数、最终结果的总股数
    double ansP=0.0;//最终结果的开盘价
    for(int i=1;i<records.size();++i)//遍历record，将未被取消的买单和买单的下标分别存储到buy和sell中
        if(records[i].type==0&&!records[i].cancel)
            buy.push_back(i);
        else if(records[i].type==1&&!records[i].cancel){
            sell.push_back(i);
            sellS+=records[i].s;
        }
    sort(buy.begin(),buy.end(),cmp);//按出价从大到小排序
    sort(sell.begin(),sell.end(),cmp);//按出价从大到小排序
    for(int i=0,j=0;i<buy.size();++i){//遍历买单，以当前买单的出价作为开盘价
        buyS+=records[buy[i]].s;//增加买单的总股数
        for(;j<sell.size()&&records[sell[j]].p>records[buy[i]].p;++j)//遍历卖单
            sellS-=records[sell[j]].s;//卖单的总股数应该减去出价大于开盘价的那些股数
        if(min(buyS,sellS)>ansS){//卖单和买单的最小值比最终结果的总股数大
            ansS=min(buyS,sellS);//更新最终结果的总股数
            ansP=records[buy[i]].p;//更新开盘价
        }
    }
    printf("%.2f %lld",ansP,ansS);//输出
    return 0;
}