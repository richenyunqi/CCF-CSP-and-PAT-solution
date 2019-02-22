#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;++i)
        scanf("%d",&A[i]);
    for(int left=0;left<n;++left){//枚举left
        int minHeight=A[left];//初试化最小高度为A[left]
        for(int right=left;right<n;++right){//枚举right
            minHeight=min(A[right],minHeight);//更新minHeight
            ans=max(ans,(right-left+1)*minHeight);//计算矩形面积
        }
    }
    printf("%d",ans);
    return 0;
}
