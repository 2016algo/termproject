#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include "Baristar.h"

using namespace std;

int m;
int wholeTime = 0;
queue<order> orderList;
vector<baristar> baristarList;

void orderInit();
bool checkExit();

int main(){
	orderInit();


	int tmpcnt = 1;
	queue<order> q = orderList;
	while (!q.empty()) {
		auto tmp = q.front();
		cout << tmpcnt++ << " 번 째 주문\n";
		cout << "주문 한 시간 : " << tmp.orderTime << " \n주문한 커피 종류 : " << tmp.coffeeType << "\n해당 커피 만드는 시간" << tmp.makingTime <<"\n";
		q.pop();
	}

	while (checkExit()) {
		//바리스타 일 진행시키기

		//printf("어디서?\n");
		for (int i = 0; i < m; i++) {
			if (baristarList[i].curOrderTime != 0) {
				if (baristarList[i].executeList.front().makingTime != 0) {
					baristarList[i].executeList.front().makingTime-=1;
					baristarList[i].completeOrderTime+=1;
					baristarList[i].curOrderTime-=1;
				}
				if (baristarList[i].executeList.front().makingTime == 0) {
					baristarList[i].executeList.pop();
				}
			}
		}

		//일 분배
		while (!orderList.empty() && wholeTime == orderList.front().orderTime) {
			auto tmp = orderList.front();

			//일 제일 적게한 바리스타 찾기
			sort(baristarList.begin(), baristarList.end());

			baristarList[0].takeOrder(tmp);
			orderList.pop();
		}

		wholeTime++;
	}

	//일 제일 적게한 바리스타 찾기
	sort(baristarList.begin(), baristarList.end());
	for (int i = 0; i < m; i++) {
		cout << i + 1 << " 번 째 바리스타\n";
		cout << "총 일 한 시간 : " << baristarList[i].completeOrderTime;
		cout << "\n만든 커피 개수 : " << baristarList[i].orderCnt;
		cout << "\n";
		int bSize = baristarList[i].outputList.size();
		for (int j = 0; j < bSize; j++) {
			cout << baristarList[i].outputList[j].orderTime << "\n";
			cout << baristarList[i].outputList[j].coffeeType << "\n";
			cout << baristarList[i].outputList[j].makingTime << "\n";
			cout << "\n";
		}
		cout << "\n";
	}
	printf("%d\n");
	return 0;
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

	int n; //총 주문 량, 바리스타 수
	inFile >> n >> m;
	baristarList.resize(m); //바리스타 init
	
	int k;
	while (n--) {
		inFile >> k; //주문 커피 종류
		int orderTime, coffeeCnt;
		string coffeeType;
		inFile >> orderTime; // 주문 시간
		for (int i = 0; i < k; i++) {
			inFile >> coffeeType >> coffeeCnt; //커피 타입과 수량 받아옴
			for (int j = 1; j <= coffeeCnt; j++) { //커피 수량 만큼 queue에 1개씩 나누어서 push
				order cur(orderTime, 1, coffeeType);
				cur.setMakingTime();
				orderList.push(cur);
			}
		}
	}
	inFile.close();
}

bool checkExit() {
	int Size = baristarList.size();
	for (int i = 0; i < Size; i++) {
		if (!orderList.empty() || !baristarList[i].executeList.empty() || baristarList[i].curOrderTime != 0)
			return true;
	}
	return false;
}

