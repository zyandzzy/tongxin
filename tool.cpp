#include<ctime>
#include"struct.hpp"
//转换时间为年月日
void timetrs(time_t p,char * time)
{
    struct  tm * TM;
    TM = localtime(&p);
    strftime(time , 20, "%Y-%m-%d %H:%M",TM);
}

//将卡结构体信息赋值给上下机结构体
void fuzhi(updw* ud,card* cd)
{
    strcpy(ud->card,cd->card);

    ud->del = 0;

    strcpy(ud->tstart,cd->start);

    strcpy(ud->last,cd->last);
    
    ud->status = 1;  
}

/*int initupnode(upnode* cardlistt)
{
    

    if(cardlistt->next == nullptr)
    {
        head = new upnode(ca);

        if(head->next == nullptr)
        {
            head->next = nullptr;
            cardlistt = head;
            return true;
        }
    }
    return false;
}

void releaseCardlist(upnode* cardlistt)
{
    upnode* cur = cardlistt;
    upnode* next = nullptr;

    while(cur->next!=nullptr)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
    cardlistt = new upnode(ca);
}

/*int getcard()//获取卡信息，并储存在链表中
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

}*/
