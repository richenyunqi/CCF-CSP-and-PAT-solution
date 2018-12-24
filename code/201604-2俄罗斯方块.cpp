#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[15][10],Atemp[10],B[4][4],Btemp[4]={-1,-1,-1,-1};
    fill(Atemp,Atemp+10,15);
    for(int i=0;i<15;++i)
        for(int j=0;j<10;++j){
            scanf("%d",&A[i][j]);
            if(A[i][j]==1&&i<Atemp[j])
                Atemp[j]=i;
        }
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j){
            scanf("%d",&B[i][j]);
            if(B[i][j]==1){
                Btemp[j]=i;
            }
        }
    int num,minRow=15;
    scanf("%d",&num);
    for(int i=0;i<4;++i)
        if(Btemp[i]>-1)
            minRow=min(minRow,Atemp[num+i-1]-Btemp[i]-1);
    for(int i=0;i<4&&i+minRow<15;++i)
        for(int j=0;j<4;++j)
            if(i+minRow>=0)
                A[i+minRow][num-1+j]=B[i][j]==1?1:A[i+minRow][num-1+j];
    for(int i=0;i<15;++i){
        for(int j=0;j<10;++j)
            printf("%d ",A[i][j]);
        printf("\n");
    }
    return 0;
}
