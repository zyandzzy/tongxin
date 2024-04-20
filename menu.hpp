#pragma once
//查询卡的信息
void chaxun();
//添加卡的信息
void add();
//释放卡信息链表
void releaseCardlist();
//初始化卡信息链表
//true代表成功，false代表失败
int initCardlist();

int getcard();//获取卡信息

void shangji();//实现上机

void querycard();//实现查询卡信息

void xiaji();//实现下机功能

int shijian(char*t1,char* t2);//计算出消费时间

void chongzhi();//充值

void tuifei();//退钱

void zhuxiao();//注销卡

void chaxuntongji();//实现查询统计功能

void suggest();//用户提出建议