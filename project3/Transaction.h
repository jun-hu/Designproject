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
	int orderID; // �ֹ� ���̵�� ���α׷� ���۽� 1�� �ʱ�ȭ �Ǿ� ���������� �Ҵ�
	vector<int> ingredientsInfo; // �ֹ��� ������ ��ǰ ���̵� ���� ǥ���� ����Ʈ
								 // ù��°�� ��ǰ,�޺�,��Ʈ ����id, �������� �߰����id�� ��
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
			if (ingredientsInfo[i] == 2)  //�޺�
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
			if (ingredientsInfo[i] == 1) //����
			{
				orderedMenu = new Jumbo(orderedMenu);
			}
			else if (ingredientsInfo[i] == 2) //�Ҽ���
			{
				orderedMenu = new Sausage(orderedMenu);
			}
			else if (ingredientsInfo[i] == 3) //�����
			{
				orderedMenu = new Drink(orderedMenu);
			}
			else if (ingredientsInfo[i] == 4) //����Ƣ��
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