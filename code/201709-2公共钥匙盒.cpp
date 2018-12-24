#include<bits/stdc++.h>
using namespace std;
struct Key{//定义Key类 
	int num;//钥匙编号 
	int time;//当前时间 
	bool borrow;//表示是取钥匙还是还钥匙 ，true表示取，false表示还 
	Key(int n,int t,bool b):num(n),time(t),borrow(b){}//构造函数 
	bool operator<(const Key&k)const{//重载<运算符 ，注意优先级队列默认以最大元素为队首元素
		if(this->time!=k.time)//以时间最早的位于队首 
			return this->time>k.time;
		else if(this->borrow!=k.borrow)//先还钥匙再取钥匙 
			return this->borrow&&!k.borrow;
		else//以钥匙编号最小的位于队首 
			return this->num>k.num;
	}
};
priority_queue<Key>pq;//优先级队列 
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int a[N+1];//表示当前挂钩上钥匙顺序的数组 
	for(int i=0;i<N+1;++i)
		a[i]=i;
	for(int i=0;i<K;++i){//读取数据 
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		pq.push(Key(a,b,true));
		pq.push(Key(a,b+c,false));
	}
	while(!pq.empty()){//队列不空，继续循环 
		Key k=pq.top();
		pq.pop();
		if(k.borrow){//如果是取钥匙 
			int i=1; 
			while(a[i]!=k.num)//查找取的钥匙编号在数组中的位置
				++i;
			a[i]=-1;//令该位置处钥匙编号为-1，表示该挂钩没有挂钥匙 
		}else{//如果是还钥匙 
			int i=1;
			while(a[i]!=-1)//查找数组中第一个没挂钥匙的挂钩 
				++i;
			a[i]=k.num;//令该位置处钥匙编号为还的钥匙编号 
		}
	}
	for(int i=1;i<N+1;++i)//输出 
		printf("%d ",a[i]);
} 
