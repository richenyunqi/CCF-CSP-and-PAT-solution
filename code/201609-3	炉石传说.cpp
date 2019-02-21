#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cur=0;
    cin>>n;
    vector<pair<int,int>>player[2]={{{30,0}},{{30,0}}};
    while(n--){
        string command;
        int a,b,c;
        cin>>command;
        if(command=="summon"){
            cin>>a>>b>>c;
            player[cur].insert(player[cur].begin()+a,{c,b});//添加随从
        }else if(command=="attack"){
            cin>>a>>b;
            player[cur][a].first-=player[cur^1][b].second;
            player[cur^1][b].first-=player[cur][a].second;
            if(player[cur][a].first<=0&&a!=0)//生命值小于等于0且是随从
                player[cur].erase(player[cur].begin()+a);//删除该随从
            if(player[cur^1][b].first<=0&&b!=0)//生命值小于等于0且是随从
                player[cur^1].erase(player[cur^1].begin()+b);//删除该随从
        }else if(command=="end")
            cur^=1;
    }
    if(player[0][0].first>0&&player[1][0].first>0)
        puts("0");
    else if(player[0][0].first>0)
        puts("1");
    else
        puts("-1");
    for(int i=0;i<2;++i){
        printf("%d\n%d ",player[i][0].first,player[i].size()-1);
        for(int j=1;j<player[i].size();++j)
            printf("%d ",player[i][j].first);
        puts("");
    }
    return 0;
}
