#pragma once
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
Struct order 
=> �Է¹��� �ֹ�

orderTime : �ֹ� �ð�
coffeCnt : �ֹ� ���� Ŀ�� Ÿ�Կ� �ش��ϴ� Ŀ�� ����
coffeType : �ֹ����� Ŀ�� Ÿ��
*/
typedef struct Order {
	int orderTime;
	int coffeeCnt;
	string coffeeType;
}order;


/*
Class baristar 
=> ���� �й���� �ٸ���Ÿ Ŭ����

Queue���� �ֹ��� pop�Ǿ� �й踦 �����ϸ�
�� �ٸ���Ÿ�� ���� �ߴ� �ð��� ��������
���� ���� �� �� �ٸ���Ÿ�� �ֹ��� ���� �ް� �ȴ�.
*/
typedef class Baristar {
public:
	int completeOrderTime;
	int orderCnt;
	queue<order> executeList;
	vector<order> outputList;

	//constructor
	Baristar() {
		completeOrderTime = orderCnt = 0;
	}

	//operator overloading
	bool operator<(const Baristar &u) const {
		if (orderCnt == u.orderCnt)
			return completeOrderTime < u.completeOrderTime;
		return orderCnt < u.orderCnt;
	}

	//method
	void takeOrder(order o) {
		executeList.push(o);
		outputList.push_back(o);
		orderCnt++;
	}

	void checkOrder(int wholeTime) {
		int executeTime = wholeTime - executeList.front().orderTime;

	}
}baristar;


