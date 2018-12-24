#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	int s[9]={0,3500,5000,8000,12500,38500,58500,83500,INT_MAX};//税前工资 
	double rate[9]={0.0,0.0,0.03,0.1,0.2,0.25,0.3,0.35,0.45};//纳税比率 
	int t[9]={0};//税后工资
	for(int i=1;i<9;++i)//计算各节点处税后工资
		t[i]=t[i-1]+(s[i]-s[i-1])*(1-rate[i]);
	for(int i=1;i<9;++i){//查找输入的T 对应的S 所在区间，并计算S，输出 
		if(t[i]>=T){//如果t[i]>T 说明税前工资在当前区间内 
			int S=(T-t[i-1])/(1-rate[i])+s[i-1];//计算税前工资S 
			printf("%d",S);//输出 
			break;
		}
	}
	return 0;
}
