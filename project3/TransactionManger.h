#pragma once
#include "Transaction.h"
class TransactionManger
{
public:
	TransactionManger() {}
	~TransactionManger() {}

	void addTransaction(Transaction* newTransaction);
	//고객이 새로운 부리또를 주문한 경우 새로운 주문을 추가함.
	void processFrontTransaction(); 
	//주문 목록의 가장 처음의 주문의 정보를 출력 후, 주문 목록에서 삭제
	//주문정보: orderID, 메뉴의 description
	void printTransaction(); // 주문 목록에 저장된 모든 주문 정보를 출력
							 // ingredientsInfo를 사용하여 아래와 같은 형식으로 출력
							 // -> orderID. 단품+소세지+점보
	void deleteTransaction(int index); //주문 목록의 index번째 주문을 삭제
	void Clear() { orderTransactions.clear(); }
	

private:
	vector<Transaction> orderTransactions; //주문내역들을 저장
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