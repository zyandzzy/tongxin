#pragma once
#include"struct.hpp"
int putfile(char * file , card * cardfile);

void infile(char * file,char * x,int& y);

void filetoli(card* p,int& j);//将card文件内容转化为结构体

int kmp(char* p,char* q);//模糊查询

int update(CardNode* cardfile);//更新card.txt的内容

void fileupdate(CardNode* ud);//将内容写入文件updown中
