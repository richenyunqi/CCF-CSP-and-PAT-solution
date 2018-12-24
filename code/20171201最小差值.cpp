#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	sort(a,a+N);
	int MIN=INT_MAX;
	for(int i=1;i<N;++i)
		if(abs(a[i]-a[i-1])<MIN)
			MIN=abs(a[i]-a[i-1]);
	printf("%d",MIN);
} 
