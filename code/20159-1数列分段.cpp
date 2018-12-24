#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int num=1,current; 
	scanf("%d",¤t);
	for(int i=1;i<N;++i){
		int a;
		scanf("%d",&a);
		if(a!=current){
			++num;
			current=a;
		}
	}
	printf("%d",num);
	return 0;
}
