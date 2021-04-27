#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n;
    scanf("%d%d%*c",&T,&n);
    while(T--){
        list<pair<queue<int>,int>>process;//first成员是一个队列，存储每个进程的所有指令；second成员存储上一条执行的指令，初始化为INT_MAX
        unordered_set<int>commands;//存储每个进程正在执行的指令
        string s;
        for(int i=0;i<n;++i){
            process.push_back({queue<int>(),INT_MAX});
            getline(cin,s);
            for(int j=0,k;j<s.size();j=k+1){//按空格键分割字符串，并用整数表示指令
                k=s.find(' ',j);
                if(k==string::npos)
                    k=s.size();
                if(s[j]=='S')
                    process.back().first.push(i*10000+stoi(s.substr(j+1,k-j-1)));
                else
                    process.back().first.push(-(stoi(s.substr(j+1,k-j-1))*10000+i));
            }
        }
        for(bool f=true;!process.empty();f=true){//f标志是否所有进程指令都被堵塞
            for(auto i=process.begin();i!=process.end();++i){//遍历所有进程
                if(commands.find(i->second)!=commands.end())//上一次执行的指令被堵塞了
                    continue;//进程也被堵塞，其他指令无法执行
                if((i->first).empty()){//所有指令均已执行完毕
                    i=process.erase(i);//将该进程删除
                    --i;
                    continue;
                }
                while(!(i->first).empty()){//进程还有指令要执行
                    int t=(i->first).front();//从队首弹出一条指令
                    (i->first).pop();
                    auto j=commands.find(-t);//查找其它进出中是否有正在执行的对应的指令
                    if(j==commands.end()){//没有对应的指令
                        commands.insert(t);//将该指令插入到commands中
                        i->second=t;//更新上一次执行的指令为当前指令
                        break;
                    }else{//有对应的指令
                        commands.erase(j);//将对应的指令从commands中删除
                        f=false;//并不是所有进程都被堵塞
                    }
                }
            }
            if(f)//遍历完所有进程后发现所有进程均被堵塞，说明发生死锁
                break;
        }
        puts(process.empty()?"0":"1");//跳出循环时进程list为空，表示所有进程指令均执行完毕，则没有死锁
    }
    return 0;
}
