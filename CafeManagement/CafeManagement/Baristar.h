#pragma once
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
Class order 
=> �Է¹��� �ֹ�

Queue�� �ֹ��� ���� �� ����Ѵ�.

	* Variable *
	orderTime => �ֹ��� ���� �ð�
	makingTime => �ֹ� ���� Ŀ�Ǹ� ����µ� ��� �ð�
	coffeCnt => �ֹ� ���� Ŀ�� Ÿ�Կ� �ش��ϴ� Ŀ�� ����
	coffeType => �ֹ� ���� Ŀ�� Ÿ��

	* Constructor *
	Order() => Basic Consturctor
	Order(int orderTime, int coffeCnt, string coffeType) => �ֹ� �ð�, Ŀ�� ��, Ŀ�� Ÿ���� ����

	* Method *
	void setMakingTime() => Ŀ�� Ÿ�Կ� ���� �ҿ� �ð� ����
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
		if (coffeeType == "Espresso")
			makingTime = 1;
		else if (coffeeType == "Americano")
			makingTime = 2;
		else if (coffeeType == "CafeLatte")
			makingTime = 4;
		else if (coffeeType == "CafeMocha") 
			makingTime = 5;
		else if (coffeeType == "VanillaLatte") 
			makingTime = 4;
		else if (coffeeType == "MochaLatte")
			makingTime = 5;
		else if (coffeeType == "Macchiato")
			makingTime = 5;
		else if (coffeeType == "Frappucino")
			makingTime = 10;
		else if (coffeeType == "Smoothie")
			makingTime = 8;
		else if (coffeeType == "HerbalTea")
			makingTime = 3;
	}

}order;


/*
Class baristar 
=> ���� �й���� �ٸ���Ÿ Ŭ����

Queue���� �ֹ��� pop�Ǿ� �й踦 �����ϸ�
�� �ٸ���Ÿ�� ���� �ߴ� �ð�, ���� ���� �ؾ��ϴ� �ð�, �ֹ� ���� Ƚ���� ��������
���� ���� �� �� �ٸ���Ÿ�� �ֹ��� ���� �ް� �ȴ�.

	* Variable *
	int completeOrderTime => �ٸ���Ÿ�� ���� �����ߴ� �ð�
	int curOrderTime => �ٸ���Ÿ�� ��й��� ���� �ؾ��ϴ� �ð�
	int orderCnt => �ٸ���Ÿ�� ���� Ŀ�� ��
	queue<order> executeList => �ٸ���Ÿ�� ��� ���� ���� �����ϴ� queue
	vector<order> outputList => �ٸ���Ÿ�� ���� �ߴ� ���� ����ϱ� ���� vector

	* Constructor *
	Baristar() => Basic Constructor

	* Operator overloading *
	bool operator<(const Baristar &u) const => ���� ���� �� �� �ٸ���Ÿ�� ã�� ���� operator overloading
	
	* Method *
	void takeOrder(order o) => ��й��� order�� executeList�� outputList�� push�ϰ� curOrderTime�� orderCnt�� ������Ų��.
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
		if (completeOrderTime == u.completeOrderTime) {
			if (curOrderTime == u.curOrderTime)
				return orderCnt < u.orderCnt;
			return curOrderTime < u.curOrderTime;
		}
			
		return completeOrderTime < u.completeOrderTime;
	}

	//method
	void takeOrder(order o) {
		executeList.push(o);
		outputList.push_back(o);
		curOrderTime += o.makingTime;
		orderCnt++;
	}
}baristar;

