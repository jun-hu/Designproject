#pragma once
#include "BuritoFactory.h"
#include "TransactionManger.h"
#include <iostream>
using namespace std;

class App
{
public:
	App() {}
	~App() {}

	void run();

private:
	void readTransaction();
	void writeTransaction();

private:
	BuritoFactory* bf;
	TransactionManger* tm;
};

void App::run() 
{
	while (1)
	{
		int select;
		cout << "�θ��� �ֹ� ���� ���α׷�" << endl;
		cout << "--------------------------�ֹ� ���-----------------------------" << endl;
	//	tm->printTransaction();
		cout << "----------------------------------------------------------------" << endl;
		cout << "1. �ֹ� �߰�" << endl;
		cout << "2. �ֹ� ���" << endl;
		cout << "3. �ֹ� ó��" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << ": "; cin >> select;

		if (select == 1) //�ֹ��� �߰��� ������ transaction��ü�� ����� �װ��� transactionmanager��
						//�Ѱ��ְ� add�����ش�.
		{
			Transaction* _transaction = new Transaction(bf->order());
			tm->addTransaction(_transaction);
		}
		else if (select == 2)
		{
			int remove=0;
			tm->printTransaction();
			cout << "������ �޴��� �����ϼ��� : "; cin >> remove;
			tm->deleteTransaction(remove);
		}
		else if (select == 3)
		{
			tm->printTransaction();
			tm->processFrontTransaction();
		}
		else cout << "�߸��� ����Դϴ�." << endl << endl;
	}
	
	
}