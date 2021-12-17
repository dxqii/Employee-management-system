#pragma once  //防止头文件重复包含
#include <iostream>  //包含输入输出流头文件
using namespace std;  //使用标准命名空间
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:

	WorkerManager();
	~WorkerManager();
	//展示菜单
	void Show_Menu();

	//退出功能
	void exitSystem();

	//增加职工
	void ADD_Emp();
	
	//保存文件
	void save();

	//统计文件中人数
	int get_EmpNum();

	//读取文件中职工数据
	void init_Emp();

	//展示职工信息
	void show_Emp();

	//按照职工编号判断职工是否存在，存在返回职工在数组中的位置 不存在返回-1
	int IsExist(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按编号排序
	void Sort_Emp();

	//清空文件
	void Clean_file();

	//记录文件中的人数个数
	int m_EmpNum;

	//员工数组的指针
	Worker ** m_EmpArray;




	//判断文件是否为空 标志
	bool m_FileIsEEmpty;

	
	

};