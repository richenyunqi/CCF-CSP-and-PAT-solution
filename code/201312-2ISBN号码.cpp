#include<bits/stdc++.h>
using namespace std;
int main(){
	int s1,s2,s3;//前三个数字 
	int sum=0,num=1;//sum表示前9个数字与权重相乘之和,num表示权重 
	char s4,ss2[4],ss3[6];//s4表示输入的最后一个字符 
	scanf("%d-%d-%d-%c",&s1,&s2,&s3,&s4);//读取输入数据 
	sum+=s1*(num++);//进行权重乘法加和 
	//将读取的数字转换成字符串 
	sprintf(ss2,"%03d",s2);
	sprintf(ss3,"%05d",s3);
	//进行权重乘法加和 
	for(int i=0;ss2[i]!='\0';++i)
		sum+=(ss2[i]-'0')*(num++);
	for(int i=0;ss3[i]!='\0';++i)
		sum+=(ss3[i]-'0')*(num++);
	sum%=11;//求余 
	//输出 
	if((sum<=9&&sum==s4-'0')||(sum==10&&s4=='X'))
		printf("Right");
	else
		printf("%d-%d-%d-%c",s1,s2,s3,sum==10?'X':(sum+'0'));
	return 0;
}
