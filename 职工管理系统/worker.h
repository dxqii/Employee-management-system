#pragma once
#include <iostream>
using namespace std;
#include <string>

//ְ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;//���麯��
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//��Ա����
	int m_Id;
	string m_Name;
	int m_DeptId;
};