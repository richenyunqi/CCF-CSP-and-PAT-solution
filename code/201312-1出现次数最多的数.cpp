#include<bits/stdc++.h>​
using namespace std;
int main(){
    int N,input;
    scanf("%d",&N);
    map<int,int>m;
    for(int i=0;i<N;++i){
        scanf("%d",&input);
        ++m[input];
    }
    int ans=m.begin()->first;
    for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
        if(it->second>m[ans])
            ans=it->first;
    printf("%d\n",ans);
    return 0;
}
