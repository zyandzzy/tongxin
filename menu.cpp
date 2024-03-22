#include"menu.hpp"
#include"struct.hpp"
#include"tool.hpp"
#include"file.hpp"
#include<iostream>
#include<cstring>
#include<ctime>

using namespace std;

card cardN[99];//记录卡的信息
int  con = 0;//记录现有卡的数目
char tmt[20];//记录开卡时间（年月日）
char tml[20];//记录上次使用时间
CardNode* cardlist = nullptr;




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
        strcpy(cardN[con].password,cb.c_str()) ;
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


int initCardlist ()
{
    CardNode* head = nullptr;

    if(cardlist = nullptr)
    {
        head = new CardNode;

        if(head != nullptr)
        {
            head->next = nullptr;
            cardlist = head;
        }
    }
}
