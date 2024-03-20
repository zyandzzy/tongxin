#pragma once
#include<iostream>
#include<ctime>
#include<cstring>

//定义结构体 含有卡的各种信息
struct card
{
    char card[99];//卡号

    char password[99];//密码

    int status;//储存卡的状态

    time_t tstart;//记录开卡时间

    time_t tend; //记录结束时间

    time_t tlast;//记录最后使用的时间

    float totle_use; //记录总金额

    int usecount = 0;//记录使用次数

    float balance;//记录余额

    int del;//删除标志（0-未删除，1-已删除）
};