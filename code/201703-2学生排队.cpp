#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	list<int>l;//存储学号的链表
	for(int i=0;i<N;++i)//将所有学号加入链表中 
		l.push_back(i+1);
	while(M--){
		int a,b;
		scanf("%d%d",&a,&b);//读取移动的学号，和移动的长度 
		list<int>::iterator i=l.begin(); 
		while(*i!=a)//遍历链表查找要移动的学号在链表中的位置
			++i;
		i=l.erase(i);//删除该元素
		while(b<0){//找到移动后的位置 
			--i;
			++b;
		}
		while(b>0){
			++i;
			--b;
		}
		l.insert(i,a);//插入该元素 
	}
	for(list<int>::iterator i=l.begin();i!=l.end();++i)//遍历输出 
		printf("%d ",*i);
	return 0;
} 
