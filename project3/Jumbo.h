#pragma once
#include "Decorator.h"
class Jumbo :
	public Decorator
{
public:
	Jumbo() {}
	Jumbo(Burito* b) { burito = b; }
	~Jumbo() {}

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

int Jumbo::getCost()
{
	return 1000 + burito->getCost();
}

string Jumbo::getDescription()
{
	return burito->getDescription() + "/n+ Á¡º¸: 1000";
}
