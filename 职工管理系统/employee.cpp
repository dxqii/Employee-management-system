#include "employee.h"


//���캯��
Employee::Employee(int id, string name, int did)//������
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "Ա����ţ� " << m_Id
		<< " \tְ�������� " << m_Name
		<< " \t��λ�� " << getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");//"Ա��"Ϊ const char *����
}