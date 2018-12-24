#include<bits/stdc++.h>
using namespace std;
bool A[105][105];//坐标系
int main(){
    int N,cnt=0;
    scanf("%d",&N);
    while(N--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<x2;++i)//将矩形内所有元素涂色
            for(int j=y1;j<y2;++j)
                A[i][j]=true;
    }
    for(int i=0;i<105;++i)//计算出坐标系内所有为true的元素个数
        cnt+=count(A[i],A[i]+105,true);//count为C++标准库自带函数，返回给定的迭代器所指区间内所有等于指定值的元素个数
    printf("%d",cnt);
    return 0;
}
