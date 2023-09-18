#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<ctime>
#include<map>

#define CHEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;

		//��Ա������������
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;

		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "�߻����ţ�" << endl;

	multimap <int, Worker>::iterator pos = m.find(CHEHUA);
	int count = m.count(CHEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ����:" << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�������ţ�" << endl;

	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ����:" << pos->second.m_Salary << endl;
	}

	cout << "�з�����:" << endl;

	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ����:" << pos->second.m_Salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker>vWorker;
	creatWorker(vWorker);

	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "������" << it->m_Name << " ���ʣ�" << it->m_Salary << endl;
	//}
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

	showWorkerByGroup(mWorker);

	system("pause");
	return 0;
}