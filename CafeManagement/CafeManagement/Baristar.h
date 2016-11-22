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
typedef class Order {
public:
	int orderTime;
	int makingTime;
	int coffeeCnt;
	string coffeeType;

	Order() {
		orderTime = makingTime = coffeeCnt = 0;
		coffeeType = "";
	}

	Order(int orderTime, int coffeeCnt, string coffeeType) {
		this->orderTime = orderTime;
		this->coffeeCnt = coffeeCnt;
		this->coffeeType = coffeeType;
	}

	void setMakingTime() {
		if (coffeeType == "Espresso") {
			makingTime = 1;
		}
		else if (coffeeType == "Americano") {
			makingTime = 2;
		}
		else if (coffeeType == "CafeLatte") {
			makingTime = 4;
		}
		else if (coffeeType == "CafeMocha") {
			makingTime = 5;
		}
		else if (coffeeType == "VanillaLatte") {
			makingTime = 4;
		}
		else if (coffeeType == "MochaLatte") {
			makingTime = 5;
		}
		else if (coffeeType == "Macchiato") {
			makingTime = 5;
		}
		else if (coffeeType == "Frappucino") {
			makingTime = 10;
		}
		else if (coffeeType == "Smoothie") {
			makingTime = 8;
		}
		else if (coffeeType == "HerbalTea") {
			makingTime = 3;
		}
	}
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
	int curOrderTime;
	int orderCnt;
	queue<order> executeList;
	vector<order> outputList;

	//constructor
	Baristar() {
		completeOrderTime = orderCnt = curOrderTime= 0;
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

