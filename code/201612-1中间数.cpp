#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>A(n);
    for(int i=0;i<n;++i)
        scanf("%d",&A[i]);
    sort(A.begin(),A.end());
    auto i=equal_range(A.begin(),A.end(),A[A.size()/2]);
    if(i.first-A.begin()==A.end()-i.second)
        printf("%d",A[A.size()/2]);
    else
        printf("-1");
    return 0;
}
