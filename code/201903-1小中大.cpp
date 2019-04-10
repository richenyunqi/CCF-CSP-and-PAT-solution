#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    vector<int>v;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(i==0)
            v.push_back(a);
        if((n%2==1&&i==n/2)||(n%2==0&&i==n/2-1))
            v.push_back(a);
        if(n%2==0&&i==n/2)
            v.push_back(a);
        if(i==n-1)
            v.push_back(a);
    }
    sort(v.begin(),v.end());
    printf("%d ",v.back());
    if(v.size()==3)
        printf("%d ",v[1]);
    else if((v[1]+v[2])%2==0)
        printf("%d ",(v[1]+v[2])/2);
    else
        printf("%.1f ",(v[1]*1.0+v[2])/2);
    printf("%d",v.front());
    return 0;
}
