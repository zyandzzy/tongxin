#include"menu.hpp"
#include"struct.hpp"
#include"tool.hpp"
#include"file.hpp"
#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>

using namespace std;

int j = 0;//记录
card cardN[99];//记录卡的信息
int  con = 0;//记录现有卡的数目
char tmt[20];//记录开卡时间（年月日）
char tml[20];//记录上次使用时间
card ca = {};
CardNode* cardlist = new CardNode(ca);//cardlist作为链表的头


void add()//添加卡信息
{   
    cout << "------添加卡------" << endl;
    string ca,cb;
    cout << "请输入卡号1~18位:";
    cin >> ca;
    cout << "请输入密码:";
    cin >> cb;
    
    cout << "请输入开卡金额";
    cin >> cardN[con].balance;
    if (ca.length()>18||cb.length()>18)
    {   

        cout << "卡号出错，请重新输入" << endl;
        add();
    }
    else
    {   
        strcpy(cardN[con].password,cb.c_str());
        strcpy(cardN[con].card , ca.c_str());
        cardN[con].totle_use = cardN[0].balance;
        cardN[con].usecount = 0;
        cardN[con].status = 0;
        cardN[con].del = 0;
        cardN[con].tstart =  time(NULL);
        cardN[con].tend = time(NULL);
        cardN[con].tlast =time(NULL);
        timetrs(cardN[con].tstart,tmt);

        
        if(putfile("card.txt",&cardN[con])==0)
        {   
            cout<<"该卡号已存在"<<endl;
            return;
        }
        else (putfile("card.txt",&cardN[con])==1);
        {
            cout << "-----添加的卡信息如下-----" << endl;
            printf("\t卡号\t密码\t状态\t余额\t");
            cout << endl;
            cout << "\t" << cardN[con].card << "\t" << cardN[con].password << "\t" << cardN[con].status << "\t" << cardN[con].balance << endl;
            con+=1;
        }
    } 
}

void querycard()//查询卡信息
{   
    char x[30];
    int sum=0;
    int mod;//判断是精确还是模糊
    std::cout<<"请选择查询方式:"<<std::endl;
    std::cout<<"1:精准查询"<<std::endl<<"2:模糊查询"<<std::endl;
    std::cin>>mod;
    if(mod == 1)
    {
        cout<<"请输入卡号:"<<endl;
        cin>>x;
        while(strlen(x)>18||strlen(x)<3)
        {
           std::cout<<"卡号长度错误,请重新输入卡号"<<endl;
           std::cin>>x;
           if(strlen(x)<=18||strlen(x)>3)
           return;
        }
            for(CardNode* i = cardlist;i!=nullptr;i = i->next)//遍历卡信息结构体，并输出符合要求的卡信息
            {   
                if(strcmp(x,i->date.card)==0)
                {   
                    if(i->date.del==0)  
                { 
                    cout << "查询到的卡信息为：" << endl;
                    cout <<"卡号" << "\t"<<"密码" << "\t"<<"开卡时间" <<"\t"<<"\t"<<"上次使用时间"<<"\t";
                    cout<<"\t"<<"上下机状态"<<"\t"<<"删除状态"<<"\t";
                    cout<<"总金额" << "\t"<<"余额" <<"\t"<<"使用次数"<<endl;
                    cout<<i->date.card<<"\t";
                    cout<<i->date.password<<"\t";
                    cout<<i->date.start<<"\t";
                    if(strcmp(i->date.start,i->date.last)==0) cout<<"您未使用过这张卡"<<"\t";
                    else  cout<<i->date.last<<"\t";
                    cout<<i->date.status<<"\t\t";
                    cout<<i->date.del<<"\t\t";
                    cout<<i->date.totle_use<<"\t";
                    cout<<i->date.balance<<"\t";
                    cout<<i->date.usecount<<"\t"<<endl;
                    sum++;
                    break;
                }
                    else if(i->date.del==1)
                    {
                        cout<<"该卡号已被注销"<<endl;
                    }
                }
            }
        if(sum==0)
        cout<<"未查询到该卡，请检查输入的卡号和密码是否正确"<<endl;
    }
    else if(mod==2)
    {
         cout<<"请输入卡号:"<<endl;
         cin>>x+1;
         int tm=0;
         for(CardNode* i = cardlist;i!=nullptr;i = i->next)
        {   
            
            if(kmp(x,i->date.card))
            {
                if(tm ==0&&i->date.del==0)
                {
                    cout << "查询到的卡信息为：" << endl;
                    cout <<"卡号" << "\t"<<"密码" << "\t"<<"开卡时间" <<"\t"<<"\t"<<"上次使用时间"<<"\t";
                    cout<<"\t"<<"上下机状态"<<"\t"<<"删除状态"<<"\t";
                    cout<<"总金额" << "\t"<<"余额" <<"\t"<<"使用次数"<<endl;
                    tm = 1;
                }
                if(i->date.del==0)
                {
                    cout<<i->date.card<<"\t";
                    cout<<i->date.password<<"\t";
                    cout<<i->date.start<<"\t";
                    if(strcmp(i->date.start,i->date.last)==0) cout<<"您未使用过这张卡"<<"\t";
                    else  cout<<i->date.last<<"\t";
                    cout<<i->date.status<<"\t\t";
                    cout<<i->date.del<<"\t\t";
                    cout<<i->date.totle_use<<"\t";       
                    cout<<i->date.balance<<"\t";
                    cout<<i->date.usecount<<endl;
                    sum++;
                }
            }
        }
        if(sum==0)
        cout<<"未查询到卡信息，请检查输入的卡号和密码是否正确"<<endl;
    }
}

void shangji()//实现上机功能
{   
    char arr[20];
    char ps[20];

    cout<<"请输入您要登录的卡号:";
    cin>>arr;
    cout<<"请输入密码:";
    cin>>ps;
    getcard(); 

    for(CardNode* i = cardlist;i!=nullptr;i = i->next)
    {   
        if(strcmp(arr,i->date.card)==0&&strcmp(ps,i->date.password)==0)
        {  
            if(i->date.balance<=0)
            {
                cout<<"余额不足，无法上机"<<endl;
                return;
            } 
            if(i->date.del==0)
            {
                if(i->date.status==0)
                {   
                   
                    i->date.tlast = time(NULL);
                    timetrs(i->date.tlast,i->date.last);
                    timetrs(i->date.tlast,i->date.end);
                    i->date.status = 1;
                    i->date.usecount++;
                    if(update(cardlist)==1)
                    {
                        cout<<"-----卡信息更新成功-----"<<endl;
                    }
                    cout<<"-----上机卡的信息为-----"<<endl;
                    cout<<"卡号"<<"\t"<<"余额"<<"\t"<<"上机时间"<<endl;
                    cout<<i->date.card<<"\t"<<i->date.balance<<"\t";
                    cout<<i->date.last<<endl;
                }
                else
                cout<<"该卡正在上机，无需上机"<<endl;
            }
            else 
            cout<<"该卡号已注销"<<endl;

            return;
        }
    }
     cout<<"卡号或密码错误,请重新尝试"<<endl;
     shangji();
}

void xiaji()//实现下机功能
{
    char arr[20];
    char ps[20];

    cout<<"请输入您要登录的卡号:";
    cin>>arr;
    cout<<"请输入密码:";
    cin>>ps;
    getcard(); 
    for(CardNode* i = cardlist;i!=nullptr;i = i->next)
    {   
        if(strcmp(arr,i->date.card)==0&&strcmp(ps,i->date.password)==0)
        {   
            if(i->date.del==0)
            {
                if(i->date.status==1)
                {   
                    cout<<"下机成功"<<endl;
                    i->date.tend = time(NULL);
                    timetrs(i->date.tend,i->date.end);
                    int tt = shijian(i->date.end,i->date.last);
                    i->date.balance-=((tt+14)/15)*0.5;
                    float x = ((tt+14)/15)*0.5;//消费金额
                    i->date.status = 0;
                    i->date.xiao = x;
                    if(update(cardlist)==1)
                    {
                        cout<<"-----卡信息更新成功-----"<<endl;
                    }
                    fileupdate(i);
                    //ong long t = i->date.tend-i->date.tlast;
    
                    int s = tt%60;

                    int h = tt/60;
                // querrybilling(i);
                cout<<"-----下机信息为-----"<<endl;
                cout<<"卡号\t"<<"消费\t"<<"余额\t"<<"上机时间\t\t"<<"下机时间\t\t"<<"使用时间"<<endl;
                cout<<i->date.card<<"\t";
                cout<<x<<"\t";
                cout<<i->date.balance<<"\t";
                cout<<i->date.last<<"\t";
                cout<<i->date.end<<"\t";
                cout<<h<<"小时"<<s<<"分钟"<<endl;
                    //cout<<"您当前余额为："<<i->date.balance<<endl;
                }            
                else
                cout<<"该卡未上机，无需下机"<<endl;   
            } 
            else
            cout<<"该卡号已注销"<<endl;  

            return;     
        }
    }

    cout<<"卡号或密码错误,请重新尝试"<<endl;
     xiaji();
}

void chongzhi()//实现充值功能
{   
    char arr[20];
    char ps[20];
    
    cz cc = cz();
    cout<<"请输入您要充值的卡号:";
    cin>>arr;

    cout<<"请输入密码:";
    cin>>ps;
    
    ofstream cfp("chongzhi.dat",ios_base::app|ios_base::binary);
    getcard(); 
    for(CardNode* i = cardlist;i!=nullptr;i = i->next)
    {   
      
        if(strcmp(arr,i->date.card)==0&&strcmp(ps,i->date.password)==0)
        {        
             if(i->date.del==0)   
              {  
                
                 cout<<"请输入您要充值的金额:";
                 float x;
                 cin>>x;
                 //puts("");
                 cc.ti = time(NULL);
                 timetrs(cc.ti,cc.tt);
                 cc.balance = x;
                 strcpy(cc.card,i->date.card);
                 i->date.balance+=x;
                 i->date.totle_use+=x;
                 cc.totle = i->date.balance;
                 if(update(cardlist)==1)
                 cout<<"充值成功"<<endl;
                 cout<<"您当前余额为："<<i->date.balance<<endl;
                 cfp.write((const char*)&cc,sizeof cc);
              }
              else 
              cout<<"该卡号已注销"<<endl;
        }
    }

}

void tuifei()//实现退费功能
{
    char arr[20];
    char ps[20];

    cout<<"请输入您要退费的卡号:";
    cin>>arr;
    cout<<"请输入密码:";
    cin>>ps;
    getcard(); 

    ofstream cfp("chongzhi.dat",ios_base::app|ios_base::binary);
     cz cc = cz();
    
    for(CardNode* i = cardlist;i!=nullptr;i = i->next)
    {   
        if(strcmp(arr,i->date.card)==0&&strcmp(ps,i->date.password)==0)
        {    cc.ti = time(NULL);
            timetrs(cc.ti,cc.tt);
            if(i->date.del==0)
            {   cout<<"您当前余额为："<<i->date.balance<<endl;
                cout<<"请输入您要退费的金额：";
                float x;
                cin>>x;
                 cc.bal = x;
                 strcpy(cc.card,i->date.card);
            if(i->date.balance>=x)
             {  
                if(i->date.status==0)
               { 
                    i->date.balance-=x;
                    i->date.totle_use-=x;
                    cc.totle = i->date.balance;
                    if(update(cardlist)==1)
                    {
                        cout<<"退费成功"<<endl;
                        cout<<"您当前余额为:"<<i->date.balance<<endl;
                    }
                    cfp.write((const char*)&cc,sizeof cc);
               }
               else if(i->date.status==1)
               {               
                int xx = shijian(cc.tt,i->date.last);
                 float z = ((xx+14)/15)*0.5;//消费金额
                  if(i->date.balance-x-1<z)
                  cout<<"退费失败"<<endl;
                  else
                  { 
                    i->date.balance-=x;
                    i->date.totle_use-=x;
                    cc.totle = i->date.balance;
                    if(update(cardlist)==1)
                    {cout<<"退费成功"<<endl;
                    cout<<"您当前余额为:"<<i->date.balance<<endl;
                    }
                  }
               }
             }
               else 
               {
                cout<<"余额不足，退费失败"<<endl;
                cout<<"您当前余额为："<<i->date.balance<<endl;
               }
            }
            else
            cout<<"该卡号已注销"<<endl;
        }

    }
}

void chaxuntongji()//实现查询统计
{
   ifstream ff("updown.dat",ios_base::in|ios_base::binary);
   ifstream jiy("jianyi.dat",ios_base::in|ios_base::binary);
   card nn = {};//初始化结构体nn
   CardNode x(nn);
   char y[20];
   cout<<"您要查询的卡号:";
   cin>>y;
   int tm=0;
   float bal;
   while(ff.read((char*)&x,sizeof x))
   {
   
    if(strcmp(x.date.card,y)==0)
    { 
      if(tm==0)
      { 
        cout<<"-----查询到的上下机信息为-----"<<endl;
        cout<<"开始上机时间\t\t"<<"下机时间\t\t"<<"消费金额\t"<<"余额\t"<<endl;
        cout<<x.date.last<<"\t"<<x.date.end<<"\t"<<x.date.xiao<<"\t\t"<<x.date.balance<<endl;
        bal = x.date.balance;
        //cout<<x.date.balance<<bal<<endl;
        tm=1;
      }
      else
      {   
            cout<<x.date.last<<"\t"<<x.date.end<<"\t"<<bal - x.date.balance<<"\t\t"<<x.date.balance<<endl;
      }

    }
   }

   ifstream fcz("chongzhi.dat",ios_base::in|ios_base::binary);

   cz cc = cz();//通过构造函数初始化结构体

   tm = 0;
    while(fcz.read((char*)&cc,sizeof cc))
   {
    
    if(strcmp(cc.card,y)==0)
    { 
      if(tm==0)
      { 
        cout<<"-----查询到的充值记录为-----"<<endl;
        cout<<"卡号\t\t"<<"操作时间\t\t"<<"充值金额\t退费金额\t余额"<<endl;
        cout<<cc.card<<"\t"<<cc.tt<<"\t\t"<<cc.balance<<"\t\t"<<cc.bal<<"\t\t"<<cc.totle<<endl;
       
        tm=1;
      }
      else
      {
           cout<<cc.card<<"\t"<<cc.tt<<"\t\t"<<cc.balance<<"\t\t"<<cc.bal<<"\t\t"<<cc.totle<<endl;
      }

    }
   }
}

void zhuxiao()//实现注销
{
    char arr[20];
    char ps[20];

    cout<<"请输入您要注销的卡号:";
    cin>>arr;
    cout<<"请输入密码:";
    cin>>ps;
    getcard(); 
    for(CardNode* i = cardlist;i!=nullptr;i = i->next)
    {   
        if(strcmp(arr,i->date.card)==0&&strcmp(ps,i->date.password)==0)
        {   
            if(i->date.status==1)
            {
                cout<<"该卡正在上机，无法注销"<<endl;
                return;
            }
            i->date.del=1;
            i->date.balance=0;
            i->date.totle_use = 0;
            if(update(cardlist)==1)
            cout<<"注销成功"<<endl;
        }
    }
}

//初始化卡信息链表
//true代表成功，false代表失败
int initCardlist()
{
    CardNode* head = nullptr;

    if(cardlist->next == nullptr)
    {
        head = new CardNode(ca);

        if(head->next == nullptr)
        {
            head->next = nullptr;
            cardlist = head;
            return true;
        }
    }

    return false;
}

//释放卡信息列表
void releaseCardlist()
{
    CardNode* cur = cardlist;
    CardNode* next = nullptr;

    while(cur->next!=nullptr)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
    cardlist = new CardNode(ca);
}

int getcard()//获取卡信息，并储存在链表中
{
    int i = 0;

    int& m = j;
    
    char c[100];

    card* pcard = nullptr;//读取到的一条卡信息
    
    int ncount = 0;//读取到的卡信息个数

   CardNode* node = new CardNode(ca);//当前尾节点指针

   CardNode* cur ;//= new CardNode(ca);

   if(cardlist!=nullptr)
   {
      releaseCardlist();//释放链表
   }

   if(initCardlist()==0)
   cout<<"链表初始化失败，请重新尝试"<<endl;

   ifstream inF;//打开文件的前置工作

   inF.open("card.txt",ios_base::in);//以只读形式打开文件

   while(inF.getline(c,100,'\n'))
   {
      if(c[0]=='\0') 
      return false;
      
      ncount++;
   }

   pcard = new card [ncount];//给予内存空间

   filetoli(pcard,m);//把文件中信息存到结构体中

   if(pcard!=nullptr)
   {
     for( i=0,node = cardlist;i<ncount;i++)//node为头指针，他的初始值是cardlist，所以cardlist也是头指针，并且cardlist的值并未被改变
     {
        cur = new CardNode(ca);

        if(cur == nullptr)
        {   
            delete cur;
            return false;
        }
       // memset(cur,0,sizeof(CardNode));

       cur->date = pcard[i];//把获取到的结构体内容赋值给链表节点cur

       cur->next = nullptr;//让cur指向空节点

       node->next = cur;//node是头节点或者是上一次循环的cur

       node = cur;//cur成为新的node ，保证下一次循环的cur是尾节点指向的
     }
      delete [] pcard;
      return true;
   }

   return false;

}

void suggest()
{
    cout<<"请输入您的建议:"<<endl;
    cout<<"退出请按1"<<endl;
    jy str;
    cin.ignore();//忽略可能出现的换行符
    cin.getline(str.xx,200);
    if(str.xx[0]!='1')
    {
        ofstream sug;
        sug.open("jianyi.dat",ios_base::binary|ios_base::app|ios_base::out);
        sug.write((const char*)&str,sizeof str);
    }
}

/*void xiugai()
{   
    getcard();
    cout<<"请输入您要修改的卡号"<<endl;
    char str[30];
    cin>>str;
    if(strlen(str)>18||strlen(str)<4)
    cout<<"卡号长度出错"<<endl;
    cout<<"请输入您预留的修改信息"<<endl;

}*/
