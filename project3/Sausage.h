#pragma once
#include "Decorator.h"
class Sausage :
	public Decorator
{
public:
	Sausage() {}
	Sausage(Burito* b) { burito = b; }
	~Sausage() {}

	int getCost();
	string getDescription();

private:
	Burito* burito;
};


int Sausage::getCost()
{
	return 1000 + burito->getCost();
}

string Sausage::getDescription()
{
	return burito->getDescription() + "/n+ ¼Ò¼¼Áö: 1000";
}
