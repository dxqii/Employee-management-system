#include "boss.h"


//���캯��
Boss::Boss(int id, string name, int did)//������
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "Ա����ţ� " << m_Id
		<< " \tְ�������� " << m_Name
		<< " \t��λ�� " << getDeptName()
		<< " \t��λְ�𣺹���˾��������" << endl;
}

//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ܲ�");
}