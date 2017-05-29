#pragma once
#include <vector>
#include "Burito.h"
#include "Jumbo.h"
#include "Sausage.h"
#include "Drink.h"
#include "Fries.h"
using namespace std;

class Transaction
{
public:
	Transaction() {}
	Transaction(Burito* b) { orderedMenu = b; }
	~Transaction() {}
	Burito* makeBurito();
	void printBurito();

private:
	int orderID; // 주문 아이디는 프로그램 시작시 1로 초기화 되어 순차적으로 할당
	vector<int> ingredientsInfo; // 주문한 내역을 물품 아이디를 통해 표현한 리스트
								 // 첫번째는 단품,콤보,세트 구별id, 나머지는 추가재료id가 들어감
	Burito* orderedMenu;
};

Burito* Transaction::makeBurito()
{
	orderedMenu = new BaseBurito;
	vector<int>::size_type i = 0;
	for (; i < ingredientsInfo.size(); i++)
	{
		if (i == 0)
		{
			if (ingredientsInfo[i] == 2)  //콤보
			{
				orderedMenu = new ComboDiscount(orderedMenu);
			}
			else if (ingredientsInfo[i] == 3)
			{
				orderedMenu = new SetDiscount(orderedMenu);
			}
			
		}
		else
		{
			if (ingredientsInfo[i] == 1) //점보
			{
				orderedMenu = new Jumbo(orderedMenu);
			}
			else if (ingredientsInfo[i] == 2) //소세지
			{
				orderedMenu = new Sausage(orderedMenu);
			}
			else if (ingredientsInfo[i] == 3) //음료수
			{
				orderedMenu = new Drink(orderedMenu);
			}
			else if (ingredientsInfo[i] == 4) //감자튀김
			{
				orderedMenu = new Fries(orderedMenu);
			}
		}
	}
	return orderedMenu;
}

void Transaction::printBurito()
{
	cout << orderID << ". " << orderedMenu->getDescription()<<endl;
}