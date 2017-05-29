#pragma once
#include "Decorator.h"
class Fries :
	public Decorator
{
public:
	Fries() {}
	Fries(Burito* b) { burito = b; }
	~Fries() {}

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

int Fries::getCost()
{
	return 2000 + burito->getCost();
}

string Fries::getDescription()
{
	return burito->getDescription() + "/n+ °¨ÀÚÆ¢±è: 2000";
}
