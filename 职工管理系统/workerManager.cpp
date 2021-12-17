#include "workerManager.h"


WorkerManager::WorkerManager()
{
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		//初始化人数
		m_EmpNum = 0;

		//初始化数组指针
		m_EmpArray = NULL;
		//初始化文件是否为空
		m_FileIsEEmpty = true;
		ifs.close();
		return;
	}
	//2、文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空！" << endl;
		//初始化属性
		//初始化记录人数
		//初始化人数
		m_EmpNum = 0;

		//初始化数组指针
		m_EmpArray = NULL;
		//初始化文件是否为空
		m_FileIsEEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在且保存职工数据
	int num = get_EmpNum();
	//cout << "职工人数为： " << num << endl;
	//初始化人数
	m_EmpNum = num;
	//初始化数组指针
	//开辟空间
	m_EmpArray = new Worker *[m_EmpNum];
	//初始化文件是否为空
	m_FileIsEEmpty = false;
	//文件中数据存放数组中
	init_Emp();
	//测试代码
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "第" << i + 1 << "个职工编号为" << m_EmpArray[i]->m_Id
			<< "\t第" << i + 1 << "个职工姓名为" << m_EmpArray[i]->m_Name
			<< "\t第" << i + 1 << "个职工岗位为" << m_EmpArray[i]->m_DeptId << endl;
	}*/
	return;

}



//展示菜单
void WorkerManager::Show_Menu() //注意作用域
{
	cout << "*******************************************" << endl;
	cout << "*********  欢迎使用职工管理系统!  *********" << endl;
	cout << "*************  0.退出管理程序  ************" << endl;
	cout << "*************  1.增加职工信息  ************" << endl;
	cout << "*************  2.显示职工信息  ************" << endl;
	cout << "*************  3.删除离职职工  ************" << endl;
	cout << "*************  4.修改职工信息  ************" << endl;
	cout << "*************  5.查找职工信息  ************" << endl;
	cout << "*************  6.按照编号排序  ************" << endl;
	cout << "*************  7.清空所有文档  ************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}
//退出功能
void WorkerManager::exitSystem()
{
	cout << "欢迎下次继续使用" << endl;
	system("pause");
	exit(0);//退出程序
}
//增加职工
void WorkerManager::ADD_Emp()
{
	//提示输入几个新员工信息
	cout << "请输入添加职工数量： " << endl;
	int addNum = 0; //保护用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//初始化指针数组
		//计算添加新空间大小
		int newSize = m_EmpNum + addNum;//新空间人数
		//开辟新空间
		Worker ** newSpace = new Worker *[newSize];
		//将原来空间下的数据拷贝到新空间
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			//获取编号
			while (true)//判断是否输出重复编号
			{
				cout << "请输入第" << i + 1 << "个新职工编号： " << endl;
				cin >> id;
				int ret = IsExist(id);
				if (ret == -1)//没找到 即没有重复编号
				{
					break;
				}
				else
				{
					cout << "有重复编号，请重新输入！" << endl;
				}
			}
			
			//获取姓名
			cout << "请输入第" << i + 1 << "个新职工姓名： " << endl;
			string name;
			cin >> name;
			//获取岗位类型
			cout << "请输入第" << i + 1 << "个新职工岗位： " << endl;
			cout << "1 --- 普通职工 " << endl;
			cout << "2 --- 经理 " << endl;
			cout << "3 --- 老板 " << endl;
			int did;
			cin >> did;
			//初始化父类指针
			Worker * worker = NULL;
			//确定子类对象类型
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);//员工
				break;
			case 2:
				worker = new Manager(id, name, did);//经理
				break;
			case 3:
				worker = new Boss(id, name, did);//老板
				break;
			default:
				cout << "员工类型输入有误" << endl;
				break;
			}
			newSpace[m_EmpNum + i] = worker;//记录新数据 保存到数组中

			
		}
		//释放原有空间  
		delete[] m_EmpArray;

		//更改新空间的指向
        m_EmpArray = newSpace;
		//更新职工人数
		m_EmpNum = newSize;
		//更新职工指针数组
		
		//更新职工不为空标志
		m_FileIsEEmpty = false;
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;
		//成功添加后 保存到文件中
		save();

	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键后清屏回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	//创建流对象
	ofstream ofs;
	//打开文件 写
	ofs.open(FILENAME, ios::out);
	//写操作
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_Name << " "
			<< m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	int id;
	string name;
	int did;
	
	int num = 0;

	while (ifs>>id && ifs >>name && ifs>>did) //一行的数据
	{
		num++;//统计人数变量
	}

	return num;
}
//读取文件中职工数据
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int index = 0;//记录人数
	
	int id;
	string name;
	int did;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker * worker = NULL;//建一个指针指向职工对象
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
			cout << "职工类型有误" << endl;
			break;
		}
		m_EmpArray[index] = worker;//维护的数组
		index++;//人数+1
	}
	//关闭文件
	ifs.close();
}

//展示职工信息
void WorkerManager::show_Emp()
{
	if (m_FileIsEEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//按照职工编号判断职工是否存在，存在返回职工在数组中的位置 不存在返回-1
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
	return index;//不存在
}


//删除职工
void WorkerManager::Del_Emp()
{
	if (m_FileIsEEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号： " << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret == -1)
		{
			cout << "没有该编号的职工" << endl;
		}
		else//找到 执行删除功能 删除ret位置上的职工
		{
			
			for (int i = ret; i < m_EmpNum - 1; i++)//倒数第二
			{
				//数据前移
				m_EmpArray[i] = m_EmpArray[i + 1];
				
			}
			m_EmpNum--;//更新数组中记录人员个数
			//数据同步更新到文件中
			save();
			cout << "清除成功" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if ( m_FileIsEEmpty )//判断文件情况
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号： " << endl;
		int id;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			//找到 先delete
			delete m_EmpArray[ret];
			int id;
			string name;
			int did;

			//重新创建 职工
			while (true)//判断是否输出重复编号
			{
				cout << "请输入新职工编号： " << endl;
				cin >> id;
				int ret = IsExist(id);
				if (ret == -1)//没找到 即没有重复编号
				{
					break;
				}
				else
				{
					cout << "有重复编号，请重新输入！" << endl;
				}
			}
			
			//获取姓名
			cout << "请输入新的职工姓名： " << endl;
			cin >> name;
			//获取岗位类型
			cout << "请输入新的职工岗位： " << endl;
			cout << "1 --- 普通职工 " << endl;
			cout << "2 --- 经理 " << endl;
			cout << "3 --- 老板 " << endl;
			cin >> did;
			//初始化父类指针
			Worker * worker = NULL;
			//确定子类对象类型
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);//员工
				break;
			case 2:
				worker = new Manager(id, name, did);//经理
				break;
			case 3:
				worker = new Boss(id, name, did);//老板
				break;
			default:
				cout << "员工类型输入有误" << endl;
				break;
			}
			//记录新数据
			m_EmpArray[ret] = worker;
			//提示修改成功
			cout << "修改成功" << endl;
			//更新文件
			save();
		}
		else
		{
			cout << "未找到该编号的职工" << endl;
		}
	}
	system("pause");
	system("cls");
}


//查找职工
void WorkerManager::Find_Emp()
{
	if (m_FileIsEEmpty)//判断文件情况
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else//文件不为空 
	{
		cout << "请输入查找方式 1---编号  2---姓名" << endl;
		int select;
		cin >> select;
		if (select == 1)//编号查
		{
			cout << "请输入要查找的职工编号： " << endl;
			int id;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下： " << endl;
				m_EmpArray[ret]->showInfo();
			}
			else//未找到
			{
				cout << "未找到该编号的职工" << endl;
			}
		}
		else if (select == 2)//姓名查
		{
			cout << "请输入要查找的职工姓名： " << endl;
			string name;
			cin >> name;
			bool flag = false;//判断是否找到要查找的职工
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					//找到
					cout << "查找成功！职工编号为"
						<< m_EmpArray[i]->m_Id << "的职工信息如下： " << endl;
					m_EmpArray[i]->showInfo();
					flag = true;//找到 flag置为true
				}
			}
			if ( !flag )
			{
				cout << "未找到该姓名的职工" << endl;
			}
			
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//按编号排序
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else//文件不为空 执行排序操作
	{
		cout << "请输入排序方式 1---升序 2---降序" << endl;
		int select = 0;
		cin >> select;
		//选择排序
		for (int i = 0; i < m_EmpNum; i++)//按顺序确定最大值或最小值
		{
			int minormax = i;
			for (int j = i + 1; j < m_EmpNum; j++)//确定最大值或最小值的位置
			{
				if (select == 1)
				{
					//升序
					if (m_EmpArray[minormax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minormax = j;//更新下标
					}
				}
				else
				{
					//降序
					if (m_EmpArray[minormax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}

			}
			//确定完了 判断是否需要互换
			//判断一开始认定 最小值或最大值 是不是 计算的最小值或最大值 如果不是 交换数据
			if (minormax != i)//如果i不是所找最大值或最小值的位置 互换
			{
				Worker * temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minormax];
				m_EmpArray[minormax] = temp;
			}
		}
		//更新文件
		save();
		//提示排序完成
		cout << "排序完成！排序后的结果为： " << endl;
		show_Emp();//中包含 按任意键清屏
	}
	
}


//清空文件
void WorkerManager::Clean_file()
{
	if (m_FileIsEEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//数组里面的元素开辟在堆区
	//数组开辟在堆区
		cout << "是否确定清空文件 1---确定   2---取消" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//清空
			//清空文件
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);//删除文件后重新创建
			ofs.close();
			//清空管理系统

			if (m_EmpArray != NULL)
			{
				//清空元素
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (m_EmpArray[i] != NULL)
					{
						delete m_EmpArray[i];//把内部维护的 堆区上的每个职工对象置空
						m_EmpArray[i] = NULL;
					}
				}
				//删除堆区中的数组指针 初始化 
				m_EmpNum = 0;
				m_FileIsEEmpty = true;
				delete[] m_EmpArray;
				m_EmpArray = NULL;

			}
			cout << "清空文件完成！" << endl;
		}
		else
		{
			//不清空			
		}
	}
	
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)//或程序关闭
	{
		//将元素释放
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i] != NULL)
			{
				delete m_EmpArray[i];
			}
		}
		delete[] m_EmpArray;//释放数组
		m_EmpArray = NULL;
	}
}