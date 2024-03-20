#include<ctime>

//转换时间为年月日
void timetrs(time_t p,char * time)
{
    struct  tm * TM;
    TM = localtime(&p);
    strftime(time , 20, "%Y-%m-%d %H:%M",TM);
}