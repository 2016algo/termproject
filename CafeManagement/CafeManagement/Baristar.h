#pragma once
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
Class order 
=> 입력받은 주문

Queue에 주문을 넣을 때 사용한다.

	* Variable *
	orderTime => 주문을 받은 시간
	makingTime => 주문 받은 커피를 만드는데 드는 시간
	coffeCnt => 주문 받은 커피 타입에 해당하는 커피 개수
	coffeType => 주문 받은 커피 타입

	* Constructor *
	Order() => Basic Consturctor
	Order(int orderTime, int coffeCnt, string coffeType) => 주문 시간, 커피 수, 커피 타입을 설정

	* Method *
	void setMakingTime() => 커피 타입에 따른 소요 시간 설정
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
=> 일을 분배받을 바리스타 클래스

Queue에서 주문이 pop되어 분배를 시작하면
각 바리스타가 일을 했던 시간, 현재 일을 해야하는 시간, 주문 받은 횟수를 기준으로
제일 일을 덜 한 바리스타가 주문을 먼저 받게 된다.

	* Variable *
	int completeOrderTime => 바리스타가 일을 수행했던 시간
	int curOrderTime => 바리스타가 배분받은 일을 해야하는 시간
	int orderCnt => 바리스타가 만들 커피 수
	queue<order> executeList => 바리스타가 배분 받은 일을 저장하는 queue
	vector<order> outputList => 바리스타가 일을 했던 것을 기록하기 위한 vector

	* Constructor *
	Baristar() => Basic Constructor

	* Operator overloading *
	bool operator<(const Baristar &u) const => 일을 제일 덜 한 바리스타를 찾기 위한 operator overloading
	
	* Method *
	void takeOrder(order o) => 배분받은 order를 executeList와 outputList에 push하고 curOrderTime과 orderCnt를 증가시킨다.
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

