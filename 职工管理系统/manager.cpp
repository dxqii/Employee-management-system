#include "manager.h"


//构造函数
Manager::Manager(int id, string name, int did)//作用域
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;//设定为数字 为了方便输入信息
}

//显示个人信息
void Manager::showInfo()//重写纯虚函数
{
	cout << "员工编号： " << m_Id
		<< " \t职工姓名： " << m_Name
		<< " \t岗位： " << getDeptName()
		<< " \t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}