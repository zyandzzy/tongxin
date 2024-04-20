#include<ctime>
#include<iostream>
#include"struct.hpp"

using namespace std;
//转换时间为年月日
void timetrs(time_t p,char * time)
{
    struct  tm * TM;
    TM = localtime(&p);
    strftime(time , 20, "%Y-%m-%d %H:%M",TM);
}

int shijian(char *t1,char* t2)
{   
    int ti = 0;
    int a  = 0;
    for(int i = 11;i<=12;i++)
    {
       a*=10;
       a+=t1[i]-t2[i];
    }
    a*=60;
    int b = 0;
    for(int i = 13;i<=15;i++)
    {
        b*=10;
        b+=t1[i]-t2[i];
    }
    return a+b;
}

void put()//输出菜单
{
	cout<<"-----菜单-----"<<endl;
	cout<<"1. 添加卡:"<<endl;
	cout<<"2. 查询卡:"<<endl;
	cout<<"3. 上机:"<<endl;
	cout<<"4. 下机:"<<endl;
	cout<<"5. 充值:"<<endl;
	cout<<"6. 退费:"<<endl;
	cout<<"7. 查询统计:"<<endl;
	cout<<"8. 注销:"<<endl;
    /*cout<<"9. 帮助手册:"<<endl;
    cout<<"10. 提供建议"<<endl;*/
	cout<<"0. 退出:"<<endl;
}


