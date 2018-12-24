#include<bits/stdc++.h>
using namespace std;
//窗口类 
struct Window{
	int num;//编号
	int x1,y1,x2,y2; //左上角和右下角坐标 
};
//判断点击的坐标(a,b)是否在窗口w中 
bool InWindow(Window&w,int a,int b){
	if(a>=w.x1&&a<=w.x2&&b>=w.y1&&b<=w.y2)
		return true;
	return false;
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	list<Window>window;//窗口的list 
	//读取数据并加入list中 
	for(int i=1;i<=N;++i){
		Window w;
		scanf("%d%d%d%d",&w.x1,&w.y1,&w.x2,&w.y2);
		w.num=i;
		window.push_front(w);
	}
	while(M--){
		int a,b;
		scanf("%d%d",&a,&b);
		list<Window>::iterator i=window.begin();
		//查找list中有没有点击包含点击坐标的窗口 
		while(i!=window.end()&&!InWindow(*i,a,b)) 
			++i;
		if(i==window.end())//没有输出IGNORED 
			printf("IGNORED\n");
		else{//有 
			printf("%d\n",i->num);//输出该窗口编号 
			window.erase(i);//从List中删除该窗口 
			window.push_front(*i);//将该窗口加入list首位 
		}
	}
	return 0;
}
