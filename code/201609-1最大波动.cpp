#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int a,b,MAX=-1;
	scanf("%d",&a);
	for(int i=1;i<N;++i){
		scanf("%d",&b);
		if(abs(a-b)>MAX)
			MAX=abs(a-b);
		a=b;
	} 
	printf("%d",MAX);
	return 0;
} 
