#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	queue<int>q;
	for(int i=1;i<=N;++i)//将所有人编号压入队列 
		q.push(i);
	int num=1;//当前的报数 
	while(q.size()>1){
		int t=q.front();//获取当前报数的人的编号 
		q.pop();
		if(!(num%K==0||num%10==K))//如果既不是K的倍数，末位也不为K 
			q.push(t);//将这个人编号加入队列中 ，表示没有被淘汰 
		++num;//递增当前报数
	}
	printf("%d",q.front());//输出最后获胜的人的编号 
} 
