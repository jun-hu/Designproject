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
		cout << "부리또 주문 관리 프로그램" << endl;
		cout << "--------------------------주문 목록-----------------------------" << endl;
	//	tm->printTransaction();
		cout << "----------------------------------------------------------------" << endl;
		cout << "1. 주문 추가" << endl;
		cout << "2. 주문 취소" << endl;
		cout << "3. 주문 처리" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << ": "; cin >> select;

		if (select == 1) //주문을 추가할 때마다 transaction객체를 만들고 그것을 transactionmanager에
						//넘겨주고 add시켜준다.
		{
			Transaction* _transaction = new Transaction(bf->order());
			tm->addTransaction(_transaction);
		}
		else if (select == 2)
		{
			int remove=0;
			tm->printTransaction();
			cout << "삭제할 메뉴를 선택하세요 : "; cin >> remove;
			tm->deleteTransaction(remove);
		}
		else if (select == 3)
		{
			tm->printTransaction();
			tm->processFrontTransaction();
		}
		else cout << "잘못된 명령입니다." << endl << endl;
	}
	
	
}