#include"file.hpp"
#include"struct.hpp"
#include"tool.hpp"
#include<fstream>
#include<iostream>

using namespace std;

int putfile(char * file ,card* cardfile)//将结构体信息以文本形式写入文件
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
        
        putFile<<cardfile->del<<"##";
        putFile<<cardfile->totle_use<<"##";

        putFile<<cardfile->balance<<"##";

        putFile<<cardfile->usecount<<"##";
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
          cout<<"总金额" << "\t\t"<<"余额" <<"\t"<<"使用次数" <<endl;
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

void filetoli(card* p,int &j)//将二进制文件读入链表中
{
   ifstream infi;
   j = 0;//每次转换的时候都要把j变为0，重新给结构体赋值
   int i =0,k=0;//i来储存当前读到文件的第几位，k表示储存到结构体内容的第几位
   char strf[100];
   infi.open("card.txt",ios_base::in);

   while(infi.getline(strf,100))//每次读取一行
  { 
    i = 0;
    for(k = 0;strf[i]!='#';i++,k++)//每进入循环，把k赋值为0，确保从头赋值
    {           
      p[j].card[k] = strf[i];
    }
    p[j].card[k] = '\0';
    i+=2;
    
    for(k=0;strf[i]!='#';i++,k++)
    {           
      p[j].password[k] = strf[i];
    }
    p[j].password[k] = '\0';
    i+=2;

    for(k=0;strf[i]!='#';i++,k++)
    {           
      p[j].start[k] = strf[i];
    }

    p[j].start[k] = '\0';
    i+=2;

    for(k=0;strf[i]!='#';i++,k++)
    {           
      p[j].last[k] = strf[i];
    }

    p[j].last[k] = '\0';
    i+=2;

    for(;strf[i]!='#';i++)
    {           
      p[j].status = strf[i]-'0';
    }
    i+=2;

    for(;strf[i]!='#';i++)
    {           
      p[j].del = strf[i]-'0';
    }
    i+=2;

    p[j].totle_use = strf[i]-'0';
    i++;//先初始化为0
    int fu=0;
    for(;strf[i]!='#';i++)
    { 
      if(strf[i]!='.'&&strf[i]!='-')          
      {
      p[j].totle_use *= 10;
      p[j].totle_use+=strf[i]-'0';
    }
      else if (strf[i]=='.')
      {
        i++;
        p[j].totle_use+=(float)(strf[i]-'0')/10;
      }
      else if(strf[i]=='-')
       fu=1;
    }
    i+=2;
    if(fu==1)
    p[j].totle_use*=-1;
     
    fu = 0;
    if(strf[i]=='-')
    {
      fu=1;
      i++;
    }
     p[j].balance =strf[i]-'0';
   
    i++;
   
    for(;strf[i]!='#';i++)
    { 
      if(strf[i]!='.'&&strf[i]!='-')          
      {
        p[j].balance *= 10;
        p[j].balance+=strf[i]-'0';
      }
      else if (strf[i]=='.')
      {
        i++;
        p[j].balance+=(float)(strf[i]-'0')/10;
      }
    }
    i+=2;
    if(fu==1)
    p[j].balance*=-1;

    p[j].usecount =strf[i]-'0';
    j++;
  }
   /*ifstream infi("card.dat",ios_base::in|ios_base::binary);
   int i=0;
   while(infi.read((char*)&p[i],sizeof(&p)))
   {
    i++;
   }*/
}

int kmp(char* p,char* q)//p是子串，q是模板串，用来模糊查询
{ 
  
  int n = strlen(p)-1,m = strlen(q);

  for(int i = m;i>=1;i--)
  q[i] = q[i-1];

  int ne[20];

  memset(ne,0,20);
  for(int i = 2,j = 0;i<=n;i++)
  {
     while(j&&p[i]!=p[j+1]) j = ne[j];

     if(p[i]==p[j+1]) j++;

     ne[i] = j;
  }

  for(int i = 1,j = 0;i<=m;i++)
  {
    while(j&&q[i]!=p[j+1]) j=ne[j];

    if(q[i]==p[j+1]) j++;

    if(j==n)
    {  
       for(int i = 0;i<m;i++)
       q[i] = q[i+1];
       q[m] = '\0';
       return 1;
    }
  }
  return 0;
}

int update(CardNode* cardfile)//重新写入card文件
{
  ofstream pp;
  pp.open("card.txt",ios_base::out);
  if(!pp.is_open())//如果未打开成功
  {
    cout<<"can't open"<<"card.txt"<<endl;
    return 0;
  }
  cardfile = cardfile->next;
  for(CardNode* i = cardfile;i!=NULL;i = i->next)
  {     
        pp<<i->date.card<<"##";

        pp<<i->date.password<<"##";

        pp<<i->date.start<<"##";

        pp<<i->date.last<<"##";

        pp<<i->date.status<<"##";
         
         pp<<i->date.del<<"##";

        pp<<i->date.totle_use<<"##";

        pp<<i->date.balance<<"##";

        pp<<i->date.usecount<<"##";
        pp<<"\n";
  }
  return 1;
}

void fileupdate(CardNode* ud)//以二进制形式更新updown
{
  ofstream fp;

  fp.open("updown.dat",ios_base::binary|ios_base::out|ios::app);

  if(!fp.is_open())
  {
    cout<<"---写入文件updown.dat失败---"<<endl;
    return;
  }
  fp.write((const char*)ud,sizeof (*ud));
}