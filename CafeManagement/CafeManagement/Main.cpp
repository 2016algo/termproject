/*
	Algorithm Term Project
	20113274 ���Ѱ�
	20113281 �ڼ���
	20113300 �����
	20113309 ��   ��
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
	int n => �Է¹��� �ֹ��� ��
	int m => �Է¹��� �ٸ���Ÿ�� ��
	int wholeTime => �� ����, ���� �ð��帧�� ���� ����, �� �ٸ���Ÿ�� �ֹ� Queue���� ���� ���� ��й޾Ƽ� ��� ������ �Ϸ��ϴ� �ð�
	queue<order> orderList => order ����ü�� �̷���� queue, �Է¹��� �ֹ����� �����Ѵ�.
	vector<baristar> baristarList => baristar ����ü�� �̷���� vector, �Է¹��� �ٸ���Ÿ�� �� ��ŭ�� ũ��� �����Ѵ�.

	* Method *
	void orderinit()
	=> �ֹ��� orderList�� ����
	input.txt���� �ֹ����� �Է� ���� �� orderList�� �� �� �������� ����

	ù �ٿ���
	n : �ֹ� �� ��, m : �ٸ���Ÿ�� �� �� �ԷµǸ�
	�� ���� �ٺ��� n-1���� �ٿ���
	k : �ֹ��� Ŀ�� ���� ��, orderTime : �ֹ� �ð��� ���� k����
	coffeeType : Ŀ�� ����, coffeeCnt : Ŀ�� ���� �Էµȴ�.

	bool checkExit();
	=>  �ֹ��� ��� ����Ǿ����� üũ
	�� �ٸ���Ÿ���� ��ȸ�ϸ�
	orderList�� ������� �ʰų� 
	�ٸ���Ÿ�� executeList�� ������� �ʰų� 
	�ٸ���Ÿ�� curOrderTime�� 0�� �ƴϸ� ���� ������ �ʾ����Ƿ� true ��ȯ

	void executeOrder()
	=> �� �ٸ���Ÿ�� �й���� ���� 1�� ��ŭ �����Ѵ�.
	���� �ٸ���Ÿ�� executeList�� front�� �ִ� ���� �����ϰ� ���� Ŀ���� makingTime�� 0�� �Ǹ� Ŀ�ǰ� ������� ���̹Ƿ� pop�Ѵ�.
	
	distributeOrder()
	=> ���� ������ �� ���� ���� ���� ��, �׸��� ���� �� �ٸ���Ÿ�� ã�Ƽ� orderList�� �ִ� �ֹ��� ����Ѵ�.
	���� ���� ���� �� �ٸ���Ÿ�� baristarList�� sorting �ϸ� �� ó������ ���� �Ǿ��ִ�.

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
	//	cout << i + 1 << " �� ° �ٸ���Ÿ\n";
	//	cout << "�� �� �� �ð� : " << baristarList[i].completeOrderTime;
	//	cout << "\n���� Ŀ�� ���� : " << baristarList[i].orderCnt;
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
		if (!orderList.empty() || 
			!baristarList[i].executeList.empty() || 
			baristarList[i].curOrderTime != 0)
			return true;
	}
	return false;
}

void executeOrder() {
	//�ٸ���Ÿ �� �����Ű��
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
	//�� �й�
	while (!orderList.empty() && wholeTime == orderList.front().orderTime) {
		auto tmp = orderList.front();
		//�� ���� ������ �ٸ���Ÿ ã��
		sort(baristarList.begin(), baristarList.end());
		baristarList[0].takeOrder(tmp);
		orderList.pop();
	}
}