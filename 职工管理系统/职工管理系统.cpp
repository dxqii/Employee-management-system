//Employee-management-system
//Author: Duxuqiang, 535848067@qq.com
#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//创建管理类
//与用户的沟通菜单界面
//对职工增删改查的操作
//与文件的读写交互

//void test()
//{
//	Worker * worker = NULL;//创建员工父类指针 用来指向具体子类对象
//	worker = new Employee(1, "张三", 1); //张三员工 注意创建的对象类型 new子类对象
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "李四", 2); //李四经理
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "王五", 3); //王五老板
//	worker->showInfo();
//	delete worker;
//}

int main()
{
	//实例化管理者对象
	WorkerManager wm;
	int choice;//存储用户选项
	while (true)
	{
		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择： " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.ADD_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
			wm.Clean_file();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	//test();
	
	system("pause");
	return 0;
}