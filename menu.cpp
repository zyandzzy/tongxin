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
updw ud = {};
card ca = {};
CardNode* cardlist = new CardNode(ca);//cardlist作为链表的头
upnode*  cardlistt = new upnode(ud);







void put()
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
	cout<<"0. 退出:"<<endl;
}


void chaxun()
{    
    cout<<"请输入要查询的卡号："<<endl;
    char x[99];
    cin>>x;
    int n = 0;
    int &y =n;
    infile("card.txt",x,y);
    /*int x;   
    char arr[29];//记录卡号，与已有卡号对比
    cout<<"请输入要查询的卡号：";
    cin>>arr;
    for(int i = 0;i<=99;i++)
    {
        if(strcmp(arr,cardN[i].card) == 0)
        {
            cout << "查询到的卡信息为：" << endl;
	        cout <<"卡号" << "\t"<<"密码" << "\t"<<"开卡时间" <<"\t"<<"\t"<<"上次使用时间"<<"\t";
            cout<<"\t"<<"状态"<<"\t";
	        cout<<"总金额" << "\t"<<"余额" <<"\t"<< endl;	
            cout<<cardN[i].card<<"\t";	
	  	    cout<<cardN[i].password<<"\t";
	        cout<<tmt<<"\t";
            if (tml[0]==0)    cout<<"您未使用过这张卡"<<"\t";
            else if(tml[0]!=0)  cout<<tml<<"\t";
			cout<<cardN[i].status<<"\t";
		    cout<<cardN[i].totle_use<<"\t";
		    cout<<cardN[i].balance<<"\t"<<endl;
            break;
        }

        else if(strcmp(arr,cardN[i].card) != 0)
        {   
            int y;
            cout<<"您输入的卡号错误或并没有开卡"<<endl;
            cout<<"您是否要继续查询"<<endl;
            cout<<"输入0继续查询:"<<endl;
            cout<<"输入1放弃查询:"<<endl;
            cin>>y;
            x = y;
           if(x==0)
            {
                chaxun();
                break;
            }
            if(x==1)
           {
              break;
           } 
        }
    }*/

}

void add()
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

void querycard()//查询卡信息
{   
    char x[30];

    int mod;//判断是精确还是模糊
    cout<<"请选择查询方式:"<<endl;
    cout<<"1:精准查询"<<endl<<"2:模糊查询"<<endl;
    cin>>mod;
    if(mod == 1)
    {
        cout<<"请输入卡号:"<<endl;
        cin>>x;
        for(CardNode* i = cardlist;i!=nullptr;i = i->next)
        {   

            cout << "查询到的卡信息为：" << endl;
            cout <<"卡号" << "\t"<<"密码" << "\t"<<"开卡时间" <<"\t"<<"\t"<<"上次使用时间"<<"\t";
            cout<<"\t"<<"状态"<<"\t";
            cout<<"总金额" << "\t"<<"余额" <<"\t"<< endl;
            if(strcmp(x,i->date.card)==0)
            {
                cout<<i->date.card<<"\t";
                cout<<i->date.password<<"\t";
                cout<<i->date.start<<"\t";
                if(strcmp(i->date.start,i->date.last)==0) cout<<"您未使用过这张卡"<<"\t";
                else  cout<<i->date.last<<"\t";
                cout<<i->date.status<<"\t";
                cout<<i->date.totle_use<<"\t";
                cout<<i->date.balance<<"\t"<<endl;
                break;
            }
        }
    }
    else if(mod==2)
    {
         cout<<"请输入卡号:"<<endl;
         cin>>x+1;
         for(CardNode* i = cardlist;i!=nullptr;i = i->next)
        {
            if(kmp(x,i->date.card))
            {
            cout << "查询到的卡信息为：" << endl;
            cout <<"卡号" << "\t"<<"密码" << "\t"<<"开卡时间" <<"\t"<<"\t"<<"上次使用时间"<<"\t";
            cout<<"\t"<<"状态"<<"\t";
            cout<<"总金额" << "\t"<<"余额" <<"\t"<< endl;

            cout<<i->date.card<<"\t";
            cout<<i->date.password<<"\t";
            cout<<i->date.start<<"\t";
            if(strcmp(i->date.start,i->date.last)==0) cout<<"您未使用过这张卡"<<"\t";
            else  cout<<i->date.last<<"\t";
            cout<<i->date.status<<"\t";
            cout<<i->date.totle_use<<"\t";
            cout<<i->date.balance<<"\t"<<endl;
            }
        }
    }
}

void shangji()
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
            if(i->date.status==0)
            {   
                cout<<"上机成功"<<endl;
                i->date.tlast = time(NULL);
                timetrs(i->date.tlast,i->date.last);
                i->date.status = 1;
                if(update(cardlist)==1)
                {
                    cout<<"-----卡信息更新成功-----"<<endl;
                }
                fuzhi(&ud,&i->date);
                fileupdate(i);
                cout<<"您当前余额为："<<i->date.balance<<endl;
            }
            
        }
    }
}


int initupnode()
{
    upnode* head;

    if(cardlistt->next == nullptr)
    {
        head = new upnode(ud);

        if(head->next == nullptr)
        {
            head->next = nullptr;
            cardlistt = head;
            return true;
        }
    }
    return false;
}

void releaseupdw()
{
    upnode* cur = cardlistt;
    upnode* next = nullptr;

    while(cur->next!=nullptr)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
    cardlistt = new upnode(ud);
}

int getupdw()//获取卡信息，并储存在链表中
{
    int i = 0;

    int& m = j;
    
    char c[100];

    updw* pup = nullptr;//读取到的一条卡信息
    
    int ncount = 0;//读取到的卡信息个数

   upnode* node = new upnode(ud);//当前尾节点指针

   upnode* cur ;//= new CardNode(ca);

   if(cardlist!=nullptr)
   {
      releaseupdw();//释放链表
   }

   if(initupnode()==0)
   cout<<"链表初始化失败，请重新尝试"<<endl;

   ifstream inF;//打开文件的前置工作

   inF.open("updown.txt",ios_base::in);//以只读形式打开文件

   while(inF.getline(c,100,'\n'))
   {
      if(c[0]=='\0') 
      return false;
      
      ncount++;
   }

   pup = new updw [ncount];//给予内存空间

   filetoud(pup,m);//把文件中信息存到结构体中

   if(pup!=nullptr)
   {
     for( i=0,node = cardlistt;i<ncount;i++)//node为头指针，他的初始值是cardlist，所以cardlist也是头指针，并且cardlist的值并未被改变
     {
        cur = new upnode(ud);

        if(cur == nullptr)
        {   
            delete cur;
            return false;
        }
       // memset(cur,0,sizeof(CardNode));

       cur->date = pup[i];//把获取到的结构体内容赋值给链表节点cur

       cur->next = nullptr;//让cur指向空节点

       node->next = cur;//node是头节点或者是上一次循环的cur

       node = cur;//cur成为新的node ，保证下一次循环的cur是尾节点指向的
     }
      delete [] pup;
      return true;
   }

   return false;

}


void xiaji()
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
            if(i->date.status==1)
            {   
                cout<<"下机成功"<<endl;
                i->date.tend = time(NULL);
                timetrs(i->date.tend,i->date.end);
                i->date.balance-=(i->date.tend-i->date.tlast)/900*0.5;
                i->date.status = 0;
                if(update(cardlist)==1)
                {
                    cout<<"-----卡信息更新成功-----"<<endl;
                }
                fuzhi(&ud,&i->date);
                ud.status = 0;
                fileupdate(cardlist);
                long long t = i->date.tend-i->date.tlast;
                t/=60;
                int s = t%60;

                int h = t/60;
                cout<<"您本次上机时间为"<<h<<"小时"<<s<<"分钟"<<endl;
                cout<<"您当前余额为："<<i->date.balance<<endl;
            }
            else
            cout<<"该卡未上机，无需下机"<<endl;
            
        }
    }

}