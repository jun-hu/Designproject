#pragma once
#include "Burito.h"
class BaseBurito :
	public Burito
{
public:
	BaseBurito() {}
	~BaseBurito() {}

	int getCost();	//생성된 부리또의 가격를 확인.
	string getDescription(); // 생성된 부리또의 재료 및 할인 정보를 확인.
							// 예시: "부리또: 3000/n+ 음료수: 1000/n콤보할인: 300"
};

int BaseBurito::getCost()
{
	return 3000;
}

string BaseBurito::getDescription()
{
	return "부리또: 3000";
}
