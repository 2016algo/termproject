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
	//	cout << "�ֹ� �� �ð� : " << tmp.orderTime << " , �ֹ��� Ŀ�� ���� : " << tmp.coffeeType << "\n";
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
input.txt���� �ֹ����� �Է� ���� �� orderList�� �� �� �������� ����

ù �ٿ��� 
n : �ֹ� �� ��, m : �ٸ���Ÿ�� �� �� �ԷµǸ� 
�� ���� �ٺ��� n-1���� �ٿ���
k : �ֹ��� Ŀ�� ���� ��, orderTime : �ֹ� �ð��� ���� k����
coffeeType : Ŀ�� ����, coffeeCnt : Ŀ�� ���� �Էµȴ�.
*/

void orderInit() {
	ifstream inFile;
	inFile.open("input.txt");
	if (inFile.fail())
		exit(1);

	int n, m; //�� �ֹ� ��, �ٸ���Ÿ ��
	inFile >> n >> m;
	baristarList.resize(m); //�ٸ���Ÿ init
	int k;
	while (n--) {
		inFile >> k; //�ֹ� Ŀ�� ����
		order tmp;
		inFile >> tmp.orderTime; // �ֹ� �ð�
		for (int i = 0; i < k; i++) {
			inFile >> tmp.coffeeType >> tmp.coffeeCnt; //Ŀ�� Ÿ�԰� ���� �޾ƿ�
			for (int j = 1; j <= tmp.coffeeCnt; j++) //Ŀ�� ���� ��ŭ queue�� 1���� ����� push
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

