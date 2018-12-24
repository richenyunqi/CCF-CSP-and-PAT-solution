#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	int num=0;
	for(int i=1;i<N-1;++i)
		if((a[i-1]<a[i]&&a[i]>a[i+1])||(a[i-1]>a[i]&&a[i]<a[i+1]))
			++num;
	printf("%d",num);
	return 0;
}
