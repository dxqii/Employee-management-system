#include "manager.h"


//���캯��
Manager::Manager(int id, string name, int did)//������
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;//�趨Ϊ���� Ϊ�˷���������Ϣ
}

//��ʾ������Ϣ
void Manager::showInfo()//��д���麯��
{
	cout << "Ա����ţ� " << m_Id
		<< " \tְ�������� " << m_Name
		<< " \t��λ�� " << getDeptName()
		<< " \t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}