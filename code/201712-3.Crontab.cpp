#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>monthsAndWeeks={//建立英文缩写与数值的映射，注意英文缩写不区分大小写
    {"jan",1},{"feb",2},{"mar",3},{"apr",4},{"may",5},{"jun",6},
    {"jul",7},{"aug",8},{"sep",9},{"oct",10},{"nov",11},{"dec",12},
    {"sun",0},{"mon",1},{"tue",2},{"wed",3},{"thu",4},{"fri",5},{"sat",6}
};
int n,monthdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//平年时每个月有多少天
long long s,t;//起始时间、结束时间
const int year=(int)(1e8),month=(int)(1e6),day=10000,hour=100;//用来分割时间的常量
string crontab[5];//存储配置信息前5项字符串
vector<string>command;//存储配置信息最后一项命令字符串
set<int>commandTime[5];//用来存储配置信息的具体时间范围，按配置信息中的顺序存储
map<long long,vector<int>>ans;//存储最终结果，键表示时间，值表示对应的多条命令字符串的下标
int daysOfMonth(int y,int m){//判断y年m月有几天
    if((y%400==0||y%4==0&&y%100!=0)&&m==2)//y年是闰年且查询2月有几天
        return 29;//闰年2月有29天
    return monthdays[m];//直接返回monthdays的相应位置的天数
}
int determineMonthOrWeek(string s){//判断字符串s是几月或星期几
    if(isdigit(s[0]))//s是数字字符串
        return stoi(s);//转换成数字并返回
    for(char&c:s)//s是英文缩写，先将s中的字母都转化成小写字母
        c=tolower(c);
    return monthsAndWeeks[s];//返回s的对应数值
}
int determineWeek(int y,int m,int d,int week=4){//根据1970年1月1日是周四，返回y年m月d日是周几
    for(int i=1970;i<y;++i){//检查1970年到y年经历的年份
        int temp=(i%400==0||i%4==0&&i%100!=0)?366:365;//平年有365天，闰年有366天
        week=(week+temp)%7;//更新week
    }
    for(int i=1;i<m;++i)//检查1月到m月的月份
        week=(week+daysOfMonth(y,i))%7;//求出该月有几天，并更新week
    return (week+d-1)%7;//返回周几
}
void splitCommand(){//分割命令
    for(int i=0;i<5;++i){//遍历配置信息的前5项
        commandTime[i].clear();//先清空commandTime的相应位置
        if(crontab[i]=="*"){//配置信息如果是*，表示可以取任意值
            int left=0,right=59;
            if(i==1)
                right=23;
            else if(i==2){
                left=1;
                right=31;
            }else if(i==3){
                left=1;
                right=12;
            }else if(i==4)
                right=6;
            for(int j=left;j<=right;++j)
                commandTime[i].insert(j);
        }
        else//配置信息不是*
            for(int j=0,k1=0;true;j=k1+1){//j来存储每一次搜索','字符的起始位置
                k1=crontab[i].find(',',j);//k1存储从j位置开始','字符的位置
                string temp=crontab[i].substr(j,k1==string::npos?k1:k1-j);//temp存储,字符前的时间范围字符串
                int k2=temp.find('-');//k2存储temp中-字符的位置
                int p1=determineMonthOrWeek(temp.substr(0,k2)),p2;//p1、p2分别存储时间范围的下界和上界
                if(k2==string::npos)//temp中不含-字符
                    p2=p1;//时间上下界相同
                else//temp中含-字符
                    p2=determineMonthOrWeek(temp.substr(k2+1));//p2存储时间范围下界
                for(int k=p1;k<=p2;++k)//将时间范围内的时间全都插入到commandTime的相应位置
                    commandTime[i].insert(k);
                if(k1==string::npos)//已经到达配置信息末尾
                    break;//跳出循环
            }
    }
}
void computeCrontab(int c){//计算符合该crontab的时间，参数c表示该命令字符串在command中的下标
    for(int y=s/year;y<=t/year;++y)//遍历起始年份到结束年份
        for(int m:commandTime[3])//遍历符合要求的月份
            for(int d:commandTime[2]){//遍历符合要求的天
                if(d>daysOfMonth(y,m))//如果当前日期超过了该月份的最大天数
                    continue;//略过其他操作
                if(find(commandTime[4].begin(),commandTime[4].end(),
                        determineWeek(y,m,d))!=commandTime[4].end())//该日期对应的星期几符合要求
                    for(int h:commandTime[1])//遍历小时
                        for(int minute:commandTime[0]){//遍历分钟
                            long long temp=(long long)y*year+m*month+d*day+h*hour+minute;//将时间格式化
                            if(temp>=s&&temp<t)//时间在[起始时间，结束时间)区间内
                                ans[temp].push_back(c);//放入结果
                        }
            }
}
int main(){
    cin>>n>>s>>t;
    command.resize(n);//n个命令
    for(int i=0;i<n;++i){
        for(int j=0;j<5;++j)//读取配置信息前5项
            cin>>crontab[j];
        cin>>command[i];//读取配置信息的命令项
        splitCommand();//分割配置信息
        computeCrontab(i);//计算结果
    }
    for(auto&i:ans)//输出
        for(auto j:i.second)
            printf("%lld %s\n",i.first,command[j].c_str());
    return 0;
}
