#include<bits/stdc++.h>
using namespace std;
int main(){
    int red,yellow,green,N,a,b,ans=0;
    scanf("%d%d%d%d",&red,&yellow,&green,&N);
    while(~scanf("%d%d",&a,&b))
        if(a==0||a==1)
            ans+=b;
        else if(a==2)
            ans+=b+red;
    printf("%d",ans);
    return 0;
}
