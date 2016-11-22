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
		cout << tmpcnt++ << " �� ° �ֹ�\n";
		cout << "�ֹ� �� �ð� : " << tmp.orderTime << " \n�ֹ��� Ŀ�� ���� : " << tmp.coffeeType << "\n�ش� Ŀ�� ����� �ð�" << tmp.makingTime <<"\n";
		q.pop();
	}

	while (checkExit()) {
		//�ٸ���Ÿ �� �����Ű��

		//printf("���?\n");
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

		//�� �й�
		while (!orderList.empty() && wholeTime == orderList.front().orderTime) {
			auto tmp = orderList.front();

			//�� ���� ������ �ٸ���Ÿ ã��
			sort(baristarList.begin(), baristarList.end());

			baristarList[0].takeOrder(tmp);
			orderList.pop();
		}

		wholeTime++;
	}

	//�� ���� ������ �ٸ���Ÿ ã��
	sort(baristarList.begin(), baristarList.end());
	for (int i = 0; i < m; i++) {
		cout << i + 1 << " �� ° �ٸ���Ÿ\n";
		cout << "�� �� �� �ð� : " << baristarList[i].completeOrderTime;
		cout << "\n���� Ŀ�� ���� : " << baristarList[i].orderCnt;
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

	int n; //�� �ֹ� ��, �ٸ���Ÿ ��
	inFile >> n >> m;
	baristarList.resize(m); //�ٸ���Ÿ init
	
	int k;
	while (n--) {
		inFile >> k; //�ֹ� Ŀ�� ����
		int orderTime, coffeeCnt;
		string coffeeType;
		inFile >> orderTime; // �ֹ� �ð�
		for (int i = 0; i < k; i++) {
			inFile >> coffeeType >> coffeeCnt; //Ŀ�� Ÿ�԰� ���� �޾ƿ�
			for (int j = 1; j <= coffeeCnt; j++) { //Ŀ�� ���� ��ŭ queue�� 1���� ����� push
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

