#include "workerManager.h"


WorkerManager::WorkerManager()
{
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		//��ʼ������
		m_EmpNum = 0;

		//��ʼ������ָ��
		m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		m_FileIsEEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ������
		//��ʼ����¼����
		//��ʼ������
		m_EmpNum = 0;

		//��ʼ������ָ��
		m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		m_FileIsEEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ������ұ���ְ������
	int num = get_EmpNum();
	//cout << "ְ������Ϊ�� " << num << endl;
	//��ʼ������
	m_EmpNum = num;
	//��ʼ������ָ��
	//���ٿռ�
	m_EmpArray = new Worker *[m_EmpNum];
	//��ʼ���ļ��Ƿ�Ϊ��
	m_FileIsEEmpty = false;
	//�ļ������ݴ��������
	init_Emp();
	//���Դ���
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "��" << i + 1 << "��ְ�����Ϊ" << m_EmpArray[i]->m_Id
			<< "\t��" << i + 1 << "��ְ������Ϊ" << m_EmpArray[i]->m_Name
			<< "\t��" << i + 1 << "��ְ����λΪ" << m_EmpArray[i]->m_DeptId << endl;
	}*/
	return;

}



//չʾ�˵�
void WorkerManager::Show_Menu() //ע��������
{
	cout << "*******************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ!  *********" << endl;
	cout << "*************  0.�˳��������  ************" << endl;
	cout << "*************  1.����ְ����Ϣ  ************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  ************" << endl;
	cout << "*************  3.ɾ����ְְ��  ************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  ************" << endl;
	cout << "*************  5.����ְ����Ϣ  ************" << endl;
	cout << "*************  6.���ձ������  ************" << endl;
	cout << "*************  7.��������ĵ�  ************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}
//�˳�����
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´μ���ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}
//����ְ��
void WorkerManager::ADD_Emp()
{
	//��ʾ���뼸����Ա����Ϣ
	cout << "���������ְ�������� " << endl;
	int addNum = 0; //�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//��ʼ��ָ������
		//��������¿ռ��С
		int newSize = m_EmpNum + addNum;//�¿ռ�����
		//�����¿ռ�
		Worker ** newSpace = new Worker *[newSize];
		//��ԭ���ռ��µ����ݿ������¿ռ�
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			//��ȡ���
			while (true)//�ж��Ƿ�����ظ����
			{
				cout << "�������" << i + 1 << "����ְ����ţ� " << endl;
				cin >> id;
				int ret = IsExist(id);
				if (ret == -1)//û�ҵ� ��û���ظ����
				{
					break;
				}
				else
				{
					cout << "���ظ���ţ����������룡" << endl;
				}
			}
			
			//��ȡ����
			cout << "�������" << i + 1 << "����ְ�������� " << endl;
			string name;
			cin >> name;
			//��ȡ��λ����
			cout << "�������" << i + 1 << "����ְ����λ�� " << endl;
			cout << "1 --- ��ְͨ�� " << endl;
			cout << "2 --- ���� " << endl;
			cout << "3 --- �ϰ� " << endl;
			int did;
			cin >> did;
			//��ʼ������ָ��
			Worker * worker = NULL;
			//ȷ�������������
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);//Ա��
				break;
			case 2:
				worker = new Manager(id, name, did);//����
				break;
			case 3:
				worker = new Boss(id, name, did);//�ϰ�
				break;
			default:
				cout << "Ա��������������" << endl;
				break;
			}
			newSpace[m_EmpNum + i] = worker;//��¼������ ���浽������

			
		}
		//�ͷ�ԭ�пռ�  
		delete[] m_EmpArray;

		//�����¿ռ��ָ��
        m_EmpArray = newSpace;
		//����ְ������
		m_EmpNum = newSize;
		//����ְ��ָ������
		
		//����ְ����Ϊ�ձ�־
		m_FileIsEEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		//�ɹ���Ӻ� ���浽�ļ���
		save();

	}
	else
	{
		cout << "��������" << endl;
	}
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	//����������
	ofstream ofs;
	//���ļ� д
	ofs.open(FILENAME, ios::out);
	//д����
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_Name << " "
			<< m_EmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int did;
	
	int num = 0;

	while (ifs>>id && ifs >>name && ifs>>did) //һ�е�����
	{
		num++;//ͳ����������
	}

	return num;
}
//��ȡ�ļ���ְ������
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int index = 0;//��¼����
	
	int id;
	string name;
	int did;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker * worker = NULL;//��һ��ָ��ָ��ְ������
		switch (did)
		{
		case 1:
			worker = new Employee(id, name, did);
			break;
		case 2:
			worker = new Manager(id, name, did);
			break;
		case 3:
			worker = new Boss(id, name, did);
			break;
		default:
			cout << "ְ����������" << endl;
			break;
		}
		m_EmpArray[index] = worker;//ά��������
		index++;//����+1
	}
	//�ر��ļ�
	ifs.close();
}

//չʾְ����Ϣ
void WorkerManager::show_Emp()
{
	if (m_FileIsEEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//����ְ������ж�ְ���Ƿ���ڣ����ڷ���ְ���������е�λ�� �����ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Id == id)
		{
			index = i;
			
			break;
		}
	}
	return index;//������
}


//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (m_FileIsEEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ� " << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret == -1)
		{
			cout << "û�иñ�ŵ�ְ��" << endl;
		}
		else//�ҵ� ִ��ɾ������ ɾ��retλ���ϵ�ְ��
		{
			
			for (int i = ret; i < m_EmpNum - 1; i++)//�����ڶ�
			{
				//����ǰ��
				m_EmpArray[i] = m_EmpArray[i + 1];
				
			}
			m_EmpNum--;//���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			save();
			cout << "����ɹ�" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if ( m_FileIsEEmpty )//�ж��ļ����
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ţ� " << endl;
		int id;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			//�ҵ� ��delete
			delete m_EmpArray[ret];
			int id;
			string name;
			int did;

			//���´��� ְ��
			while (true)//�ж��Ƿ�����ظ����
			{
				cout << "��������ְ����ţ� " << endl;
				cin >> id;
				int ret = IsExist(id);
				if (ret == -1)//û�ҵ� ��û���ظ����
				{
					break;
				}
				else
				{
					cout << "���ظ���ţ����������룡" << endl;
				}
			}
			
			//��ȡ����
			cout << "�������µ�ְ�������� " << endl;
			cin >> name;
			//��ȡ��λ����
			cout << "�������µ�ְ����λ�� " << endl;
			cout << "1 --- ��ְͨ�� " << endl;
			cout << "2 --- ���� " << endl;
			cout << "3 --- �ϰ� " << endl;
			cin >> did;
			//��ʼ������ָ��
			Worker * worker = NULL;
			//ȷ�������������
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);//Ա��
				break;
			case 2:
				worker = new Manager(id, name, did);//����
				break;
			case 3:
				worker = new Boss(id, name, did);//�ϰ�
				break;
			default:
				cout << "Ա��������������" << endl;
				break;
			}
			//��¼������
			m_EmpArray[ret] = worker;
			//��ʾ�޸ĳɹ�
			cout << "�޸ĳɹ�" << endl;
			//�����ļ�
			save();
		}
		else
		{
			cout << "δ�ҵ��ñ�ŵ�ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}


//����ְ��
void WorkerManager::Find_Emp()
{
	if (m_FileIsEEmpty)//�ж��ļ����
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else//�ļ���Ϊ�� 
	{
		cout << "��������ҷ�ʽ 1---���  2---����" << endl;
		int select;
		cin >> select;
		if (select == 1)//��Ų�
		{
			cout << "������Ҫ���ҵ�ְ����ţ� " << endl;
			int id;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£� " << endl;
				m_EmpArray[ret]->showInfo();
			}
			else//δ�ҵ�
			{
				cout << "δ�ҵ��ñ�ŵ�ְ��" << endl;
			}
		}
		else if (select == 2)//������
		{
			cout << "������Ҫ���ҵ�ְ�������� " << endl;
			string name;
			cin >> name;
			bool flag = false;//�ж��Ƿ��ҵ�Ҫ���ҵ�ְ��
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					//�ҵ�
					cout << "���ҳɹ���ְ�����Ϊ"
						<< m_EmpArray[i]->m_Id << "��ְ����Ϣ���£� " << endl;
					m_EmpArray[i]->showInfo();
					flag = true;//�ҵ� flag��Ϊtrue
				}
			}
			if ( !flag )
			{
				cout << "δ�ҵ���������ְ��" << endl;
			}
			
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//���������
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else//�ļ���Ϊ�� ִ���������
	{
		cout << "����������ʽ 1---���� 2---����" << endl;
		int select = 0;
		cin >> select;
		//ѡ������
		for (int i = 0; i < m_EmpNum; i++)//��˳��ȷ�����ֵ����Сֵ
		{
			int minormax = i;
			for (int j = i + 1; j < m_EmpNum; j++)//ȷ�����ֵ����Сֵ��λ��
			{
				if (select == 1)
				{
					//����
					if (m_EmpArray[minormax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minormax = j;//�����±�
					}
				}
				else
				{
					//����
					if (m_EmpArray[minormax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}

			}
			//ȷ������ �ж��Ƿ���Ҫ����
			//�ж�һ��ʼ�϶� ��Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ ������� ��������
			if (minormax != i)//���i�����������ֵ����Сֵ��λ�� ����
			{
				Worker * temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minormax];
				m_EmpArray[minormax] = temp;
			}
		}
		//�����ļ�
		save();
		//��ʾ�������
		cout << "������ɣ������Ľ��Ϊ�� " << endl;
		show_Emp();//�а��� �����������
	}
	
}


//����ļ�
void WorkerManager::Clean_file()
{
	if (m_FileIsEEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//���������Ԫ�ؿ����ڶ���
	//���鿪���ڶ���
		cout << "�Ƿ�ȷ������ļ� 1---ȷ��   2---ȡ��" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//���
			//����ļ�
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);//ɾ���ļ������´���
			ofs.close();
			//��չ���ϵͳ

			if (m_EmpArray != NULL)
			{
				//���Ԫ��
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (m_EmpArray[i] != NULL)
					{
						delete m_EmpArray[i];//���ڲ�ά���� �����ϵ�ÿ��ְ�������ÿ�
						m_EmpArray[i] = NULL;
					}
				}
				//ɾ�������е�����ָ�� ��ʼ�� 
				m_EmpNum = 0;
				m_FileIsEEmpty = true;
				delete[] m_EmpArray;
				m_EmpArray = NULL;

			}
			cout << "����ļ���ɣ�" << endl;
		}
		else
		{
			//�����			
		}
	}
	
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)//�����ر�
	{
		//��Ԫ���ͷ�
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i] != NULL)
			{
				delete m_EmpArray[i];
			}
		}
		delete[] m_EmpArray;//�ͷ�����
		m_EmpArray = NULL;
	}
}