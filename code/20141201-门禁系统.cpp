#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int>m;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		int a;
		scanf("%d",&a);
		++m[a];
		printf("%d ",m[a]);
	}
	return 0;
} 
