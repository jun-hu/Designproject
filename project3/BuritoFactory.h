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
	//����ڰ� ���ϴ� �޴��� ����� ���ؼ� ���ڷ����� ������ �����.
	//���̽� �θ��ǿ� ���� ordered ��ü�� ��� �����.
	//���ڷ���Ʈ�� ����, �Ҽ���, ����, ����, �޺�����, ��Ʈ������ �ִ�.

	Burito* ordered = new BaseBurito();  //�⺻ �긮�� ��ü�� ����.

	switch (type) {
	case 1: // ��ǰ
		return ordered;
		break;
	case 2: // �޺�
		ordered = new Drink(ordered);
		ordered = new ComboDiscount(ordered); // �޺� ����
		return ordered;
		break;
	case 3: // ��Ʈ
		ordered = new Drink(ordered);
		ordered = new Fries(ordered);
		return ordered;
		break;
	default:
		cout << "�߸��� ����Դϴ�." << endl;
		break;
	}
}

Burito* BuritoFactory::order()
{
	int select1 = 0;
	int select2 = 0;
	cout << "�ֹ� �޴�" << endl;

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "�޴� ����" << endl;
	cout << "1. ��ǰ (�θ���, 3000��)" << endl;
	cout << "2. �޺� ( �θ��� + ����, 3700��)" << endl;
	cout << "3. ��Ʈ ( �θ��� + ���� + ����Ƣ��, 4500��)" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << ": "; cin >> select1;
	Burito* ordered = new BaseBurito();
	ordered=makeOrderedMenu(select1);

	while (select2 != 5)
	{
		cout << "�߰� �޴� ����" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "1. ���� (1000��)" << endl;
		cout << "2. �Ҽ���(1000��)" << endl;
		cout << "3. ����Ƣ�� (2000��)" << endl;
		cout << "4. ����� (1000��)" << endl;
		cout << "5. �׸� �߰�" << endl;
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
			cout << "�߸��� ����Դϴ�." << endl<<endl;
		}
	}

	return ordered;

}
