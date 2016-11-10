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
	int n, m; //�� �ֹ� ��, �ٸ���Ÿ ��
	inFile >> n >> m;

	int k;
	while (n--) {
		inFile >> k; //�ֹ� Ŀ�� ����
		order tmp;
		inFile >> tmp.orderTime; // �ֹ� �ð�
		for (int i = 0; i < k; i++) {
			inFile >> tmp.coffeeType >> tmp.coffeeCnt; //Ŀ�� Ÿ�԰� ���� �޾ƿ�
			for (int j = 1; j <= tmp.coffeeCnt; j++) //Ŀ�� ���� ��ŭ queue�� 1���� ����� push
				orderList.push({ tmp.orderTime, 1, tmp.coffeeType});
		}
	}

	inFile.close();
}