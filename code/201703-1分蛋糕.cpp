#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int a[N];
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	int i=0,num=0;
	while(i<N){
		int k=0;
		while(i<N&&k<K){
			k+=a[i];
			++i;
		}
		++num;
	}
	printf("%d",num);
	return 0;
} 
