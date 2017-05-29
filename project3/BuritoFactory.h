#pragma once
#include "BaseBurito.h"
#include "Drink.h"
#include "Jumbo.h"
#include "Sausage.h"
#include "Fries.h"
#include "ComboDiscount.h"
#include "SetDiscount.h"
#include <iostream>
using namespace std;

class BuritoFactory
{
public:
	BuritoFactory() {}
	~BuritoFactory() {}

	Burito* makeOrderedMenu(int type);
	Burito* order();
};


Burito* BuritoFactory::makeOrderedMenu(int type)
{
	//사용자가 원하는 메뉴를 만들기 위해서 데코레이터 패턴을 사용함.
	//베이스 부리또에 대한 ordered 객체에 계속 씌운다.
	//데코레이트는 점보, 소세지, 음료, 감자, 콤보할인, 세트할인이 있다.

	Burito* ordered = new BaseBurito();  //기본 브리또 객체를 생성.

	switch (type) {
	case 1: // 단품
		return ordered;
		break;
	case 2: // 콤보
		ordered = new Drink(ordered);
		ordered = new ComboDiscount(ordered); // 콤보 할인
		return ordered;
		break;
	case 3: // 세트
		ordered = new Drink(ordered);
		ordered = new Fries(ordered);
		return ordered;
		break;
	default:
		cout << "잘못된 명령입니다." << endl;
		break;
	}
}

Burito* BuritoFactory::order()
{
	int select1 = 0;
	int select2 = 0;
	cout << "주문 메뉴" << endl;

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "메뉴 선택" << endl;
	cout << "1. 단품 (부리또, 3000원)" << endl;
	cout << "2. 콤보 ( 부리또 + 음료, 3700원)" << endl;
	cout << "3. 세트 ( 부리또 + 음료 + 감자튀김, 4500원)" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << ": "; cin >> select1;
	Burito* ordered = new BaseBurito();
	ordered=makeOrderedMenu(select1);

	while (select2 != 5)
	{
		cout << "추가 메뉴 선택" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "1. 점보 (1000원)" << endl;
		cout << "2. 소세지(1000원)" << endl;
		cout << "3. 감자튀김 (2000원)" << endl;
		cout << "4. 음료수 (1000원)" << endl;
		cout << "5. 그만 추가" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << ": "; cin >> select2;

		if (select2 == 1)
		{
			ordered = new Jumbo(ordered);
		}
		else if (select2 == 2)
		{
			ordered = new Sausage(ordered);
		}
		else if (select2 == 3)
		{
			ordered = new Fries(ordered);
		}
		else if (select2 == 4)
		{
			ordered = new Drink(ordered);
		}
		else if (select2 == 5)
		{
			break;
		}
		else
		{
			cout << "잘못된 명령입니다." << endl<<endl;
		}
	}

	return ordered;

}
