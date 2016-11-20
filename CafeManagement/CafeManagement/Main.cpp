#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include "Baristar.h"

using namespace std;

int wholeTime = 0;
queue<order> orderList;
vector<baristar> baristarList;

void orderInit();
bool checkExit();

int main(){
	orderInit();
	//while (!orderList.empty()) {
	//	auto tmp = orderList.front();
	//	cout << "주문 한 시간 : " << tmp.orderTime << " , 주문한 커피 종류 : " << tmp.coffeeType << "\n";
	//	orderList.pop();
	//}
	while (checkExit()) {
		wholeTime++;
		while (wholeTime == orderList.front().orderTime) {
			auto tmp = orderList.front();
			baristarList[0].executeList.push(tmp);
			orderList.pop();
		}
	}
}

/*
void orderInit()
input.txt에서 주문들을 입력 받은 후 orderList에 한 잔 기준으로 저장

첫 줄에는 
n : 주문 총 량, m : 바리스타의 수 가 입력되며 
그 다음 줄부터 n-1개의 줄에는
k : 주문된 커피 종류 수, orderTime : 주문 시간과 이후 k개의
coffeeType : 커피 종류, coffeeCnt : 커피 수가 입력된다.
*/

void orderInit() {
	ifstream inFile;
	inFile.open("input.txt");
	if (inFile.fail())
		exit(1);

	int n, m; //총 주문 량, 바리스타 수
	inFile >> n >> m;
	baristarList.resize(m); //바리스타 init
	int k;
	while (n--) {
		inFile >> k; //주문 커피 종류
		order tmp;
		inFile >> tmp.orderTime; // 주문 시간
		for (int i = 0; i < k; i++) {
			inFile >> tmp.coffeeType >> tmp.coffeeCnt; //커피 타입과 수량 받아옴
			for (int j = 1; j <= tmp.coffeeCnt; j++) //커피 수량 만큼 queue에 1개씩 나누어서 push
				orderList.push({ tmp.orderTime, 1, tmp.coffeeType });
		}
	}
	inFile.close();
}

bool checkExit() {
	int Size = baristarList.size();
	for (int i = 0; i < Size; i++) {
		if (!baristarList[i].executeList.empty())
			return false;
	}
	return true;
}

