#pragma once
#include "Transaction.h"
class TransactionManger
{
public:
	TransactionManger() {}
	~TransactionManger() {}

	void addTransaction(Transaction* newTransaction);
	//���� ���ο� �θ��Ǹ� �ֹ��� ��� ���ο� �ֹ��� �߰���.
	void processFrontTransaction(); 
	//�ֹ� ����� ���� ó���� �ֹ��� ������ ��� ��, �ֹ� ��Ͽ��� ����
	//�ֹ�����: orderID, �޴��� description
	void printTransaction(); // �ֹ� ��Ͽ� ����� ��� �ֹ� ������ ���
							 // ingredientsInfo�� ����Ͽ� �Ʒ��� ���� �������� ���
							 // -> orderID. ��ǰ+�Ҽ���+����
	void deleteTransaction(int index); //�ֹ� ����� index��° �ֹ��� ����
	void Clear() { orderTransactions.clear(); }
	

private:
	vector<Transaction> orderTransactions; //�ֹ��������� ����
};

void TransactionManger::addTransaction(Transaction* newTransaction)
{
	orderTransactions.push_back(*newTransaction);
}
void TransactionManger::processFrontTransaction()
{
	orderTransactions.front().printBurito();
	orderTransactions.erase(orderTransactions.begin());
}
void TransactionManger::printTransaction()
{
	if (orderTransactions.empty())
	{
		return;
	}
	int i = 1;
	vector<Transaction>::iterator it = orderTransactions.begin();
	for (;it != orderTransactions.end(); it++)
	{
		cout << i << ". ";
		it->printBurito();
		i++;
	}
}
void TransactionManger::deleteTransaction(int index)
{
	int i = index--;
	orderTransactions.erase(orderTransactions.begin() + i);
}