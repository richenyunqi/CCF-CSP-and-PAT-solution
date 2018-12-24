#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	sort(a,a+N);
	int num=0;
	for(int i=0;a[i]<=0;++i)
		if(binary_search(a+i+1,a+N,-a[i]))
			++num;
	printf("%d",num);
	return 0;
}
