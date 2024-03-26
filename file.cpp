#include"file.hpp"
#include"struct.hpp"
#include"tool.hpp"
#include<fstream>
#include<iostream>

using namespace std;
//y=0表示该卡号已存在

//将内容写入到文件当中
int putfile(char * file ,card* cardfile)
{
  ofstream putFile;
  ifstream inf;
  char tmt[199];
  char str[20],strr[102];
  char ch;
  putFile.open(file,ios_base::out|ios_base::app);
  inf.open(file,ios_base::in);
  if(!putFile.is_open())//如果未打开成功
  {
    cout<<"can't open"<<file<<endl;
  }
  else//如果成功打开文件
  { 
       while(inf.getline(str,20,'#'))
       {  
        
         if(strcmp(str,cardfile->card)==0)
        {
          
            return 0;
        }
        inf.getline(strr,100);
       }
        timetrs(cardfile->tstart,tmt);

        putFile<<cardfile->card<<"##";

        putFile<<cardfile->password<<"##";

        putFile<<tmt<<"##";

        putFile<<tmt<<"##";

        putFile<<cardfile->status<<"##";

        putFile<<cardfile->totle_use<<"##";

        putFile<<cardfile->balance<<"##";
        putFile<<"\n";
        return 1;
       
       /*infile(file,cardfile->card,y);//判断该卡号是否存在，若不存在，y=1,若存在，y = 0

        if(y==0)//如果y = 0,返回0，表示该卡号已存在
        return 0;
        if(y==1)//如果该卡号不存在，就写入文件中
       {

        timetrs(cardfile->tstart,tmt);

        putFile<<cardfile->card<<"##";

        putFile<<cardfile->password<<"##";

        putFile<<tmt<<"##";

        putFile<<tmt<<"##";

        putFile<<cardfile->status<<"##";

        putFile<<cardfile->totle_use<<"##";

        putFile<<cardfile->balance<<"##";
        putFile<<"\n";
        return 1;
       }*/
  }
}

//将文件中内容读出;
void infile(char * file,char * x,int& y)//y==0代表查询,y==1代表写入
{
  ifstream inFile;
  char ch,bh,str[20],strr[102];

  int i = 0;

  inFile.open(file,ios_base::in);//以只读形式打开文件

  /*while(inFile.get(ch))//循环读入文件中内容
  { 
    
    if(ch=='#')//如果等于#的话，说明卡号已经读取完全，接下来遍历到下一行
    {
      i = 0;
      memset(str,0,20);
      while(inFile.get(ch))
      {
          if(ch=='\n')
          break;
      }
    }
    else//如果不等于#的话，就把读取的文件内容存进str数组中
    {
      str[i] = ch;
      i++;
    }
    if(strcmp(str,x)==0)//如果相同，就说明要添加的卡号已经在文件中存在（可能是另一个卡号的一部分）
     {
      if(y==0)//查询卡的信息
      {
         inFile.get(ch);
          if(ch=='#')//接着读取下一个数字，若是#说明卡号已存在，若不是#说明卡号不存在
          {   
              cout << "查询到的卡信息为：" << endl;
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
      else if(y==1)//写入文件时，判断是否已经存在
      {    
        inFile.get(ch);
        if(ch=='#')
          {
             y = 0; 
            return;
          }
      }
     }*/
     while(inFile.getline(str,20,'#'))
     {  
       
        if(strcmp(str,x)==0)
        {            
          cout << "查询到的卡信息为：" << endl;
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
        inFile.getline(strr,100,'\n');
     }
  
  cout<<"未查询到这张卡"<<endl;
}


void filetoli(card* p)
{
   ifstream infi;
   
   int i =0,j=0;
   char strf[100];
   infi.open("card.txt",ios_base::in);

   while(infi.getline(strf,100,'\n'))
  {
    for(i=0;strf[i]!='#';i++)
    {           
      p[j].card[i] = strf[i];
    }
    i+=2;
    
    for(;strf[i]!='#';i++)
    {           
      p[j].password[i] = strf[i];
    }
    i+=2;

    for(;strf[i]!='#';i++)
    {           
      p[j].start[i] = strf[i];
    }
    i+=2;

    for(;strf[i]!='#';i++)
    {           
      p[j].last[i] = strf[i];
    }
    i+=2;

    for(;strf[i]!='#';i++)
    {           
      p[j].status = strf[i]-'0';
    }
    i+=2;

    p[j].totle_use += (strf[i]-'0');
    i++;
    for(;strf[i]!='#';i++)
    {           
      p[j].totle_use *= 10;
      p[j].totle_use+=strf[i];
    }
    i+=2;

     p[j].balance += (strf[i]-'0');
    i++;
    for(;strf[i]!='#';i++)
    {           
      p[j].balance *= 10;
      p[j].balance+=strf[i];
    }
    i+=2;
    j++;
  }
}