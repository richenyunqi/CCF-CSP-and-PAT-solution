#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[20];//每排剩余座位数
    for(int i=0;i<20;++i)
        a[i]=5;//初始化为5
    int N;
    scanf("%d",&N);
    while(N--){
        int k;
        scanf("%d",&k);//读取需要几张车票
        int i=0;
        while(i<20&&a[i]<k)//查找是否有剩余座位数多于k的排
            ++i;
        if(i<20){//有，从该排起始编号开始输出k个连续递增数字
            int start=i*5+6-a[i];
            for(int j=0;j<k;++j)
                printf("%d ",start+j);
            printf("\n");
            a[i]-=k;
        }else{//没有，从有剩余座位的排中输出空闲座位直至输出空余座位总数为k
            for(int j=0;j<20&&k>0;++j)
                if(a[j]>0){
                    int start=j*5+6-a[j];
                    for(int m=0;m<min(a[j],k);++m)
                        printf("%d ",start+m);
                    k-=a[j];
                    a[j]=k>a[j]?0:a[j]-k;
                }
            printf("\n");
        }
    }
    return 0;
}
