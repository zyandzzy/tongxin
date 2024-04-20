#include<iostream>
#include<cstring>
#include"menu.hpp"
#include"file.hpp"
#include"tool.hpp"
using namespace std;


int main()
{   
	int num1;
	cout << "欢迎进入计费管理系统" << endl;
    put();
	while (cin >> num1)
	{   
		if(num1 == 1)
		{
			add();
			getcard();
		}

		else if (num1 == 2)
		{   
			getcard();
			//chaxun();
			querycard();
		}

		else if (num1 == 3) 
		{
			shangji();
		}
		else if (num1 == 4)
		{
			xiaji();
		}
		else if (num1 == 5) 
		{
			chongzhi();
		}
		else if (num1 == 6) 
		{
			tuifei();
		}
		else if (num1 == 7) 
		{
			chaxuntongji();
		}
		else if (num1 == 8) 
		{
			zhuxiao();
		}
		else if (num1 == 0)
		{
			cout << "欢迎使用本系统";
			break;
		}
		/*else if(num1 == 9)
		{   
			cout<<"计费标准是每15分钟5毛钱"<<endl;
			cout<<"卡号:3-18位数字和字母"<<endl<<"密码:3-12位数字和字母"<<endl;
		    cout<<"上下机状态中，0代表下机(未上机),1代表上机中"<<endl;
			cout<<"删除状态中，0代表未删除，1代表已删除"<<endl;
		}
		else if(num1 == 10)
		{
			suggest();
		}*/
		/*else if(num1 == 11)
		{
			xiugai();
		}*/
		else
		{      
	    	cout << "编号错误,请输入正确编号" << endl;
		}
		put();
		
	}
}

