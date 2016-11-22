#pragma once
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
Struct order 
=> 입력받은 주문

orderTime : 주문 시간
coffeCnt : 주문 받은 커피 타입에 해당하는 커피 개수
coffeType : 주문받은 커피 타입
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
=> 일을 분배받을 바리스타 클래스

Queue에서 주문이 pop되어 분배를 시작하면
각 바리스타가 일을 했던 시간을 기준으로
제일 일을 덜 한 바리스타가 주문을 먼저 받게 된다.
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

