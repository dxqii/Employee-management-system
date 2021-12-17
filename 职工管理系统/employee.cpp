#include "employee.h"


//构造函数
Employee::Employee(int id, string name, int did)//作用域
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

//显示个人信息
void Employee::showInfo()
{
	cout << "员工编号： " << m_Id
		<< " \t职工姓名： " << m_Name
		<< " \t岗位： " << getDeptName()
		<< " \t岗位职责：完成经理交给的任务" << endl;
}

//获取岗位名称
string Employee::getDeptName()
{
	return string("员工");//"员工"为 const char *类型
}