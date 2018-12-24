#include<bits/stdc++.h>
using namespace std;
int main(){
    int y,d;
    scanf("%d%d",&y,&d);
    int month[13]={
        0,31,28,31,30,31,30,31,31,30,31,30,31
    };
    if(y%400==0||(y%100!=0&&y%4==0))
        month[2]=29;
    int i=0;
    while(d>month[++i])
        d-=month[i];
    printf("%d\n%d",i,d);
    return 0;
}
