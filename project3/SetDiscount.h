#pragma once
#include "Decorator.h"
class SetDiscount :
	public Decorator
{
public:
	SetDiscount() {}
	SetDiscount(Burito* b) { burito = b; }
	~SetDiscount(){}

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

int SetDiscount::getCost()
{
	return -500 + burito->getCost();
}

string SetDiscount::getDescription()
{
	return burito->getDescription() + "/n+ ��Ʈ����: 500";
}
