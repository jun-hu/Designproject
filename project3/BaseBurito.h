#pragma once
#include "Burito.h"
class BaseBurito :
	public Burito
{
public:
	BaseBurito() {}
	~BaseBurito() {}

	int getCost();	//������ �θ����� ���ݸ� Ȯ��.
	string getDescription(); // ������ �θ����� ��� �� ���� ������ Ȯ��.
							// ����: "�θ���: 3000/n+ �����: 1000/n�޺�����: 300"
};

int BaseBurito::getCost()
{
	return 3000;
}

string BaseBurito::getDescription()
{
	return "�θ���: 3000";
}
