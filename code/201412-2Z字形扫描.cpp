#include<bits/stdc++.h>
using namespace std;
int matrix[505][505];//矩阵 
int a[2][2]={{0,1},{1,0}};//右、下 两个方向 
int b[2][2]={{1,-1},{-1,1}};//左下、右上两个方向
//判断当前坐标是否越界 
bool outOfBorder(int i,int j,int n){
	if(i<0||i>=n||j<0||j>=n)
		return true;
	return false;
} 
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%d",&matrix[i][j]);
	//当矩阵为1*1时，要进行特判 
	if(N==1){
		printf("%d",matrix[0][0]);
		return 0;
	}
	//i,j表示当前坐标
	//aindex表示当前是右、下两个方向中的哪一个
	//bindex表示当前是左下、右上两个方向中的哪一个 
	int i=0,j=0,aindex=0,bindex=0;
	printf("%d ",matrix[i][j]);//输出当前坐标下的数字 
	while(true){
		int ii=i+a[aindex%2][0],jj=j+a[aindex%2][1];//下一步要到达的坐标 
		if(outOfBorder(ii,jj,N))//如果下一步越界 
			++aindex;//递增aindex 
		//更新当前坐标 
		i+=a[aindex%2][0];
		j+=a[aindex%2][1];
		printf("%d ",matrix[i][j]);//输出当前坐标下的数字
		++aindex;//递增aindex
		//到达右下角时跳出循环 
		if(i==N-1&&j==N-1)
			break;
		//下一步要到达的坐标 
		ii=i+b[bindex%2][0];
		jj=j+b[bindex%2][1];
		while(!outOfBorder(ii,jj,N)){//如果下一步不越界 
		    //更新当前坐标 
			i=ii;
			j=jj;
			printf("%d ",matrix[i][j]);//输出当前坐标下的数字
			//下一步要到达的坐标 
			ii=i+b[bindex%2][0];
			jj=j+b[bindex%2][1];
		}
		++bindex;//递增bindex 
	}
	return 0;
} 
