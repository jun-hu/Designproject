#pragma once
#include "Decorator.h"
class Drink :
	public Decorator
{
public:
	Drink() {}
	Drink(Burito* b) { burito = b; }
	~Drink() {}

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

int Drink::getCost()
{
	return 1000 + burito->getCost();
}

string Drink::getDescription()
{
	return burito->getDescription() + "/n+ À½·á¼ö: 1000";
}
