//Employee-management-system
//Author: Duxuqiang, 535848067@qq.com
#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//����������
//���û��Ĺ�ͨ�˵�����
//��ְ����ɾ�Ĳ�Ĳ���
//���ļ��Ķ�д����

//void test()
//{
//	Worker * worker = NULL;//����Ա������ָ�� ����ָ������������
//	worker = new Employee(1, "����", 1); //����Ա�� ע�ⴴ���Ķ������� new�������
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "����", 2); //���ľ���
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "����", 3); //�����ϰ�
//	worker->showInfo();
//	delete worker;
//}

int main()
{
	//ʵ���������߶���
	WorkerManager wm;
	int choice;//�洢�û�ѡ��
	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ�� " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.ADD_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_file();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	//test();
	
	system("pause");
	return 0;
}