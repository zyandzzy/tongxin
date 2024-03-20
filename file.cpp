#include"file.hpp"
#include"struct.hpp"
#include"tool.hpp"
#include<fstream>
#include<iostream>

using namespace std;


void putfile(char * file ,card* cardfile)//将内容写入到文件当中
{
  ofstream putFile;
  
  char tmt[199];

  putFile.open(file,ios_base::out|ios_base::app);

  timetrs(cardfile->tstart,tmt);
  
  putFile<<cardfile->card<<"##";

  putFile<<cardfile->password<<"##";

  putFile<<tmt<<"##";
  
  putFile<<tmt<<"##";

  putFile<<cardfile->status<<"##";
  
  putFile<<cardfile->totle_use<<"##";
  
  putFile<<cardfile->balance<<"##";
  putFile<<"\n";
}

void infile(char * file,char * x)//将文件中内容读出;
{
  ifstream inFile;
  char ch,bh;

  int i = 0;

  inFile.open(file,ios_base::in);

  while(inFile.get(ch))
  { 
    if(ch==x[i])
    i++;
    else if(ch!=x[i])
    i = 0;

    if(ch =='\n')
    i = 0;
    if(i == strlen(x))
     {
      inFile.get(ch);
      if(ch=='#')
       {  cout << "查询到的卡信息为：" << endl;
          cout <<"卡号" << "\t\t"<<"密码" << "\t\t"<<"开卡时间" <<"\t"<<"\t\t"<<"上次使用时间"<<"\t";
          cout<<"\t\t"<<"状态"<<"\t\t";
          cout<<"总金额" << "\t\t"<<"余额" << endl;
          cout<<x;
          cout<<"\t";
          while(inFile.get(bh)&&bh!='\n')
          {   
            if(bh=='#')
            cout<<"\t";
            else
              cout<<bh;
          }
          cout<<endl;
          return;
       }
       else
       continue;
     }
  }
  
  cout<<"未查询到这张卡"<<endl;
}
