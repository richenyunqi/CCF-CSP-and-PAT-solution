#include<bits/stdc++.h>
using namespace std;
struct T{
	int data;//数字 
	int num;//出现次数 
	T(int d,int n):data(d),num(n){}//构造函数 
};
//比较函数 
bool cmp(const T&t1,const T&t2){
	if(t1.num!=t2.num)
		return t1.num>t2.num;
	else 
		return t1.data<t2.data;
}
int main(){
	int N;
	scanf("%d",&N);
	map<int,int>m;
	for(int i=0;i<N;++i){
		int a;
		scanf("%d",&a);
		++m[a];//将读取的数字出现次数递增 
	}
	vector<T>v;
	//将map中元素搬迁到vector中 
	for(map<int,int>::iterator i=m.begin();i!=m.end();++i)
		v.push_back(T(i->first,i->second));
	sort(v.begin(),v.end(),cmp);//排序
	//输出 
	for(int i=0;i<v.size();++i)
		printf("%d %d\n",v[i].data,v[i].num);
	return 0;
} 
