#include<bits/stdc++.h>
using namespace std;
struct Window{//窗口类 
	int num;//编号
	int x1,y1,x2,y2; //左上角和右下角坐标 
};
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	list<Window>window;//窗口的list 
	for(int i=1;i<=N;++i){//读取数据并加入list中 
		Window w;
		scanf("%d%d%d%d",&w.x1,&w.y1,&w.x2,&w.y2);
		w.num=i;
		window.push_front(w);
	}
	while(M--){
		int a,b;
		scanf("%d%d",&a,&b);
		auto i=window.begin();
		while(i!=window.end()&&!(a>=i->x1&&a<=i->x2&&b>=i->y1&&b<=i->y2))//查找list中有没有点击包含点击坐标的窗口 
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
