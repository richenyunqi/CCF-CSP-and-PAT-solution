#include<bits/stdc++.h>
using namespace std;
struct IP{//IP地址类
    string ip="";//IP地址32位的二进制字符串
    int length=-1;//IP地址的前缀长度
};
IP stringToIp(string&input){//将输入的IP地址转换为32位二进制IP地址，并求出前缀长度
    IP ip;
    string s="";
    vector<int>pow2={1,2,4,8,16,32,64,128};//2的0~7次幂
    for(int i=0;i<=input.size();++i)//遍历输入的IP地址
        if(i==input.size()||!isdigit(input[i])){//到达字符串末尾或当前字符不是数字字符
            int k=stoi(s);//将字符串s转换为整数
            for(int ii=7;ii>=0;--ii)//求出当前整数的二进制表示
                if(k>=pow2[ii]){
                    ip.ip+="1";
                    k-=pow2[ii];
                }else
                    ip.ip+="0";
            s="";
            if(input[i]=='/'){//遇到了/字符，其后面的整数就代表了前缀长度
                ip.length=stoi(input.substr(i+1));
                break;
            }
        }else
            s+=input[i];
    if(ip.length==-1)//输入的IP地址中不包含前缀长度
        ip.length=ip.ip.size();//前缀长度即为2进制字符串长度
    while(ip.ip.size()<32)//IP地址小于32位，在末尾补0
        ip.ip+="0";
    return ip;
}
bool isChildCollection(IP&a,IP&b){//判断IP地址b是不是IP地址a的匹配集的子集
    if(a.length>b.length)
        return false;
    for(int i=0;i<a.length;++i)
        if(a.ip[i]!=b.ip[i])
            return false;
    return true;
}
void Merge1(list<IP>&ipAddress){//第一步合并，移除匹配集是前一IP地址子集的IP地址
    auto i=ipAddress.begin(),j=ipAddress.begin();
    for(++j;j!=ipAddress.end();){
        if(isChildCollection(*i,*j)){
            j=ipAddress.erase(j);
        }else{
            ++i;
            ++j;
        }
    }
}
bool unionCollection(IP&a,IP&b){//判断IP地址a和b的匹配集的并集是否等于a'的匹配集
    if(a.length!=b.length)
        return false;
    for(int i=0;i<a.length-1;++i)
        if(a.ip[i]!=b.ip[i])
            return false;
    return a.ip[a.length-1]!=b.ip[a.length-1];
}
void Merge2(list<IP>&ipAddress){//第二步合并，同级合并
    auto i=ipAddress.begin(),j=ipAddress.begin();
    for(++j;j!=ipAddress.end();){
        if(unionCollection(*i,*j)){
            j=ipAddress.erase(j);
            --(*i).length;
            if(i!=ipAddress.begin()){
                --i;
                --j;
            }
        }else{
            ++i;
            ++j;
        }
    }
}
int main(){
    int N;
    cin>>N;
    list<IP>ipAddress;
    while(N--){
        string input;
        cin>>input;
        ipAddress.push_back(stringToIp(input));
    }
    ipAddress.sort([](const IP&a,const IP&b){
        if(a.ip!=b.ip)
            return a.ip<b.ip;
        return a.length<b.length;
    });
    Merge1(ipAddress);//第一步合并
    Merge2(ipAddress);//第二步合并
    for(auto&i:ipAddress){//输出IP地址
        for(int j=0;j<4;++j){//求出每8位2进制字符串代表的整数并输出
            int k=0;
            for(int ii=0;ii<8;++ii)
                k=k*2+(i.ip[ii+j*8]-'0');
            printf("%d%s",k,j<3?".":"/");
        }
        printf("%d\n",i.length);//输出前缀长度
    }
    return 0;
}
