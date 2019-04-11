#include<bits/stdc++.h>
using namespace std;
const int MAX=10005;
char temp[9],disks[1005][85000]={""};//存储所有磁盘数据
int main(){
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
            int ans=0,k;
            for(int i=0;i<n;++i)//遍历其他的块
                if(diskNo!=i){
                    for(int j=0;j<8;++j)//将对应的8个字符复制粘贴到temp中
                        temp[j]=disks[i][block*8+j];
                    temp[8]='\0';//temp末尾字符置\0
                    sscanf(temp,"%x",&k);//将16进制字符串转换为10进制数
                    ans^=k;//进行异或运算
                }
            printf("%08X\n",ans);//输出8位16进制字符串，不够8位在高位补0
        }
    }
    return 0;
}
