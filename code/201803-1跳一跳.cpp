#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=1,score=0,num=0;//a存储输入数据，score为最终得分，num为连跳方块中心次数
    while(~scanf("%d",&a)&&a!=0)//数据输入还没完成且a!=0
        if(a==1){//如果a==1
            score+=a;//加上1分
            num=0;//连跳方块中心次数归零
        }else if(a==2)//a==2
            score+=2*(++num);//递增连跳方块中心次数，得分为该次数乘2
    printf("%d",score);
    return 0;
}
