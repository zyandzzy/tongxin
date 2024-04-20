#pragma once
#include<iostream>
#include<ctime>
#include<cstring>

//定义结构体 含有卡的各种信息
struct card
{
    char card[99];//卡号

    char password[99];//密码

    int status;//储存卡的状态,1上机，0未上机

    time_t tstart;//记录开卡时间

    time_t tend; //记录结束时间

    time_t tlast;//记录最后使用的时间

    float xiao;

    float totle_use; //记录总金额

    int usecount = 0;//记录使用次数

    float balance;//记录余额

    int del;//删除标志（0-未删除，1-已删除）

    char start[66];//开卡时间

    char last[66];//上次使用时间

    char end[66];//结束使用的时间
};



struct CardNode//链表
{
    card date;

    CardNode* next;
    
    CardNode(card _date) : date(_date), next(nullptr) {}
};

struct cz//充值退费信息
{
    char card[20];//卡号

    char tt[40];//充值时间

   float balance;//充值金额

    float bal;//退费金额

    float totle;//总金额

    time_t ti;

    cz() : card(),tt(),balance(),bal(),ti() {}
};

struct jy//储存用户的建议
{
  char xx[200];
};
