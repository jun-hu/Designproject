#pragma once
#include "Decorator.h"
class ComboDiscount :
	public Decorator
{
public:
	ComboDiscount() {}
	ComboDiscount(Burito* b) { burito = b; }
	~ComboDiscount(){}

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

int ComboDiscount::getCost()
{
	return -300 + burito->getCost();
}

string ComboDiscount::getDescription()
{
	return burito->getDescription() + "/n+ ÄŞº¸ÇÒÀÎ: 300";
}
