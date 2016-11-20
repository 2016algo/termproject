#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include "Baristar.h"

using namespace std;

void main(void)
{
	ifstream inFile;
	inFile.open("input.txt");
	if (inFile.fail())
		exit(1);

	queue<order> orderList;
	Baristar baristerList[100];

	int n, m; //총 주문 량, 바리스타 수
	inFile >> n >> m;

	int k;

	// 처음 주문한 커피들을 큐에 넣는 과정 
	while (n--) {
		inFile >> k; //주문 커피 개수
		order tmp;
		inFile >> tmp.orderTime; // 주문 시간
		for (int i = 0; i < k; i++) {
			inFile >> tmp.coffeeType >> tmp.coffeeCnt; //커피 타입과 수량 받아옴
			if (strcmp(tmp.coffeeType, "아메리카노") == 0)
				tmp.makeingTime = 3;
			else if (strcmp(tmp.coffeeType, "스무디") == 0)
				tmp.makeingTime = 12;
			else if (strcmp(tmp.coffeeType, "카페라떼") == 0)
				tmp.makeingTime = 5;
			else if (strcmp(tmp.coffeeType, "카페모카") == 0)
				tmp.makeingTime = 4;
			else if (strcmp(tmp.coffeeType, "에스프레소") == 0)
				tmp.makeingTime = 3;
			else if (strcmp(tmp.coffeeType, "모카라떼") == 0)
				tmp.makeingTime = 6;
			else if (strcmp(tmp.coffeeType, "프라프치노") == 0)
				tmp.makeingTime = 9;
			else if (strcmp(tmp.coffeeType, "바닐라라떼") == 0)
				tmp.makeingTime = 5;
			else if (strcmp(tmp.coffeeType, "카라멜마끼아또") == 0)
				tmp.makeingTime = 8;
			else if (strcmp(tmp.coffeeType, "박카스") == 0)
				tmp.makeingTime = 5;

			orderList.push(tmp);
			/*
			for (int j = 1; j <= tmp.coffeeCnt; j++) //커피 수량 만큼 queue에 1개씩 나누어서 push
			{
				orderList.push({ tmp.orderTime,tmp.makeingTime,1,tmp.coffeeType });
			}
			*/
		}
	}

	inFile.close();

	//  처음 주문한 커피들을 큐에 넣는 과정 


	// 바리스타가 커피를 계속 만들고 있는 과정
	int time = 0;

	order tmpOrder;
	tmpOrder = orderList.front();
	orderList.pop();

	while (1)
	{
		if (orderList.empty() == true)
		{
			for (int i = 0; i < m; i++)
			{
				if (baristerList[i].workTime != 0) {
					baristerList[i].totalWorkTime += baristerList[i].workTime;
					baristerList[i].workTime = 0;
				}
			}
			break;
		}

		sort(baristerList, baristerList + m);

		if (tmpOrder.orderTime == time)
		{
			baristerList[0].workTime += tmpOrder.makeingTime;

			tmpOrder = orderList.front();
			orderList.pop();
			continue;
		}

		for (int i = 0; i < m; i++)
		{
			if(baristerList[i].workTime!=0){
				baristerList[i].totalWorkTime++;
				baristerList[i].workTime--;
			}
		}
		time++;
	}
	// 바리스타가 커피를 계속 만들고 있는 과정 
}


// 바리스타의 우선순위를 결정해주는 함수 
bool operator <(const Baristar a, const Baristar b)
{
	if (a.workTime == b.workTime)
		return a.totalWorkTime < b.totalWorkTime;
	else
		return a.workTime < b.workTime;
}
