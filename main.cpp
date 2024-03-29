#include<iostream>
#include<cstring>
#include"menu.hpp"
#include"file.hpp"
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
		else if (num1 == 5) cout << "请输入你要充值的金额" << endl;
		else if (num1 == 6) cout << "退费成功" << endl;
		else if (num1 == 7) cout << "查询成功" << endl;
		else if (num1 == 8) cout << "注销成功" << endl;
		else if (num1 == 0)
		{
			cout << "欢迎使用本系统";
			break;
		}
		else
		{
			cout << "编号错误,请输入正确编号"<<endl;
      
		}
		put();
	}
}

