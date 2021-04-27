#include<bits/stdc++.h>
using namespace std;
char itc[17]="0123456789ABCDEF";//10进制数与16进制字符的映射关系
unordered_map<int,char>trans;//存储16进制字符与异或后的结果之间的映射关系
char disks[1005][85000]={""};//存储所有磁盘数据
int main(){
    for(int i=0;i<16;++i)//计算0~15这16个数字之间彼此异或的256种结果
        for(int j=i;j<16;++j)
            trans[itc[i]*128+itc[j]]=trans[itc[j]*128+itc[i]]=itc[i^j];
    int n,s,l,m,a,maxBlock=0;
    scanf("%d%d%d",&n,&s,&l);
    for(int i=0;i<l;++i){//读取l块磁盘的数据
        scanf("%d%*c",&a);
        fgets(disks[a],85000,stdin);
        maxBlock=strlen(disks[a])/8;//maxBlock存储一块磁盘上的块数
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d",&a);
        int band=a/s,row=band/(n-1);//计算条带号、单磁盘上的条带号
        int diskNo=(n-row%n+band%(n-1))%n,block=row*s+a%s;//计算所在磁盘号、所在磁盘上的块号
        if(block>=maxBlock||(disks[diskNo][0]=='\0'&&n-l>1))//块号超过磁盘上的块数或者该磁盘被损坏且坏掉的磁盘超过1个
            puts("-");//该磁盘上对应块的数据无法获取
        else if(disks[diskNo][0]!='\0'){//该磁盘数据完好，直接输出对应块的数据即可
            for(int i=0;i<8;++i)
                putchar(disks[diskNo][block*8+i]);
            puts("");
        }else{//该磁盘被损坏，但数据可恢复
            char ans[9]="00000000";//存储对应块的数据
            for(int i=0;i<n;++i)//遍历其他的块
                if(diskNo!=i)
                    for(int j=0;j<8;++j)//求出异或结果
                        ans[j]=trans[ans[j]*128+disks[i][block*8+j]];
            puts(ans);
        }
    }
    return 0;
}
