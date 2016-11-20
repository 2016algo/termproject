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
	int n, m; //총 주문 량, 바리스타 수
	inFile >> n >> m;

	int k;
	while (n--) {
		inFile >> k; //주문 커피 개수
		order tmp;
		inFile >> tmp.orderTime; // 주문 시간
		for (int i = 0; i < k; i++) {
			inFile >> tmp.coffeeType >> tmp.coffeeCnt; //커피 타입과 수량 받아옴
			for (int j = 1; j <= tmp.coffeeCnt; j++) //커피 수량 만큼 queue에 1개씩 나누어서 push
				orderList.push({ tmp.orderTime, 1, tmp.coffeeType});
		}
	}

	inFile.close();
}