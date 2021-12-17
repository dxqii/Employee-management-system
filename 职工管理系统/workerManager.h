#pragma once  //��ֹͷ�ļ��ظ�����
#include <iostream>  //�������������ͷ�ļ�
using namespace std;  //ʹ�ñ�׼�����ռ�
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
	//չʾ�˵�
	void Show_Menu();

	//�˳�����
	void exitSystem();

	//����ְ��
	void ADD_Emp();
	
	//�����ļ�
	void save();

	//ͳ���ļ�������
	int get_EmpNum();

	//��ȡ�ļ���ְ������
	void init_Emp();

	//չʾְ����Ϣ
	void show_Emp();

	//����ְ������ж�ְ���Ƿ���ڣ����ڷ���ְ���������е�λ�� �����ڷ���-1
	int IsExist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���������
	void Sort_Emp();

	//����ļ�
	void Clean_file();

	//��¼�ļ��е���������
	int m_EmpNum;

	//Ա�������ָ��
	Worker ** m_EmpArray;




	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEEmpty;

	
	

};