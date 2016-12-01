/*
	Algorithm Term Project
	20113274 김한결
	20113281 박순광
	20113300 윤명식
	20113309 이   식
*/

/*
Cafe Menu
1. Espresso
2. Americano
3. CafeLatte
4. CafeMocha
5. VanillaLatte
6. MochaLatte
7. Macchiato
8. Frappucino
9. Smoothie
10. HerbalTea
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include "Baristar.h"

using namespace std;

/*
	* Variable *
	int n => 입력받을 주문의 수
	int m => 입력받을 바리스타의 수
	int wholeTime => 분 단위, 일의 시간흐름을 위한 변수, 각 바리스타가 주문 Queue에서 각자 일을 배분받아서 모두 수행을 완료하는 시간
	queue<order> orderList => order 구조체로 이루어진 queue, 입력받은 주문들을 저장한다.
	vector<baristar> baristarList => baristar 구조체로 이루어진 vector, 입력받은 바리스타의 수 만큼의 크기로 구성한다.

	* Method *
	void orderinit()
	=> 주문을 orderList에 저장
	input.txt에서 주문들을 입력 받은 후 orderList에 한 잔 기준으로 저장

	첫 줄에는
	n : 주문 총 량, m : 바리스타의 수 가 입력되며
	그 다음 줄부터 n-1개의 줄에는
	k : 주문된 커피 종류 수, orderTime : 주문 시간과 이후 k개의
	coffeeType : 커피 종류, coffeeCnt : 커피 수가 입력된다.

	bool checkExit();
	=>  주문이 모두 수행되었는지 체크
	각 바리스타들을 순회하며
	orderList가 비어있지 않거나 
	바리스타의 executeList가 비어있지 않거나 
	바리스타의 curOrderTime이 0이 아니면 일이 끝나지 않았으므로 true 반환

	void executeOrder()
	=> 각 바리스타가 분배받은 일을 1분 만큼 수행한다.
	만일 바리스타가 executeList의 front에 있는 일을 수행하고 나서 커피의 makingTime이 0이 되면 커피가 만들어진 것이므로 pop한다.
	
	distributeOrder()
	=> 일을 수행한 후 일을 제일 적게 한, 그리고 적게 할 바리스타를 찾아서 orderList에 있는 주문을 배분한다.
	일을 제일 적게 한 바리스타는 baristarList를 sorting 하면 맨 처음으로 오게 되어있다.

*/
int n, m; 
int wholeTime = 0;
queue<order> orderList;
vector<baristar> baristarList;

void orderInit();
bool checkExit();
void executeOrder();
void distributeOrder();

int main(){

	orderInit();

	while (checkExit()) {
		executeOrder();
		distributeOrder();
		wholeTime++;
	}
	sort(baristarList.begin(), baristarList.end());
	//for (int i = 0; i < m; i++) {
	//	cout << i + 1 << " 번 째 바리스타\n";
	//	cout << "총 일 한 시간 : " << baristarList[i].completeOrderTime;
	//	cout << "\n만든 커피 개수 : " << baristarList[i].orderCnt;
	//	cout << "\n";
	//	int bSize = baristarList[i].outputList.size();
	//	for (int j = 0; j < bSize; j++) {
	//		cout << baristarList[i].outputList[j].orderTime << "\n";
	//		cout << baristarList[i].outputList[j].coffeeType << "\n";
	//		cout << baristarList[i].outputList[j].makingTime << "\n";
	//		cout << "\n";
	//	}
	//	cout << "\n";
	//};
	return 0;
}

void orderInit() {
	ifstream inFile;
	inFile.open("input.txt");
	if (inFile.fail())
		exit(1);

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
		if (!orderList.empty() || 
			!baristarList[i].executeList.empty() || 
			baristarList[i].curOrderTime != 0)
			return true;
	}
	return false;
}

void executeOrder() {
	//바리스타 일 진행시키기
	for (int i = 0; i < m; i++) {
		if (baristarList[i].curOrderTime != 0) {
			if (baristarList[i].executeList.front().makingTime != 0) {
				baristarList[i].executeList.front().makingTime -= 1;
				baristarList[i].completeOrderTime += 1;
				baristarList[i].curOrderTime -= 1;
			}
			if (baristarList[i].executeList.front().makingTime == 0) {
				baristarList[i].executeList.pop();
			}
		}
	}
}

void distributeOrder() {
	//일 분배
	while (!orderList.empty() && wholeTime == orderList.front().orderTime) {
		auto tmp = orderList.front();
		//일 제일 적게한 바리스타 찾기
		sort(baristarList.begin(), baristarList.end());
		baristarList[0].takeOrder(tmp);
		orderList.pop();
	}
}