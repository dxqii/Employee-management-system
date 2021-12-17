#include "boss.h"


//构造函数
Boss::Boss(int id, string name, int did)//作用域
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "员工编号： " << m_Id
		<< " \t职工姓名： " << m_Name
		<< " \t岗位： " << getDeptName()
		<< " \t岗位职责：管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::getDeptName()
{
	return string("总裁");
}