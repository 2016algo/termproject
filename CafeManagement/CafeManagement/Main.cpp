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

	int n, m; //�� �ֹ� ��, �ٸ���Ÿ ��
	inFile >> n >> m;

	int k;

	// ó�� �ֹ��� Ŀ�ǵ��� ť�� �ִ� ���� 
	while (n--) {
		inFile >> k; //�ֹ� Ŀ�� ����
		order tmp;
		inFile >> tmp.orderTime; // �ֹ� �ð�
		for (int i = 0; i < k; i++) {
			inFile >> tmp.coffeeType >> tmp.coffeeCnt; //Ŀ�� Ÿ�԰� ���� �޾ƿ�
			if (strcmp(tmp.coffeeType, "�Ƹ޸�ī��") == 0)
				tmp.makeingTime = 3;
			else if (strcmp(tmp.coffeeType, "������") == 0)
				tmp.makeingTime = 12;
			else if (strcmp(tmp.coffeeType, "ī���") == 0)
				tmp.makeingTime = 5;
			else if (strcmp(tmp.coffeeType, "ī���ī") == 0)
				tmp.makeingTime = 4;
			else if (strcmp(tmp.coffeeType, "����������") == 0)
				tmp.makeingTime = 3;
			else if (strcmp(tmp.coffeeType, "��ī��") == 0)
				tmp.makeingTime = 6;
			else if (strcmp(tmp.coffeeType, "������ġ��") == 0)
				tmp.makeingTime = 9;
			else if (strcmp(tmp.coffeeType, "�ٴҶ��") == 0)
				tmp.makeingTime = 5;
			else if (strcmp(tmp.coffeeType, "ī��Ḷ���ƶ�") == 0)
				tmp.makeingTime = 8;
			else if (strcmp(tmp.coffeeType, "��ī��") == 0)
				tmp.makeingTime = 5;

			orderList.push(tmp);
			/*
			for (int j = 1; j <= tmp.coffeeCnt; j++) //Ŀ�� ���� ��ŭ queue�� 1���� ����� push
			{
				orderList.push({ tmp.orderTime,tmp.makeingTime,1,tmp.coffeeType });
			}
			*/
		}
	}

	inFile.close();

	//  ó�� �ֹ��� Ŀ�ǵ��� ť�� �ִ� ���� 


	// �ٸ���Ÿ�� Ŀ�Ǹ� ��� ����� �ִ� ����
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
	// �ٸ���Ÿ�� Ŀ�Ǹ� ��� ����� �ִ� ���� 
}


// �ٸ���Ÿ�� �켱������ �������ִ� �Լ� 
bool operator <(const Baristar a, const Baristar b)
{
	if (a.workTime == b.workTime)
		return a.totalWorkTime < b.totalWorkTime;
	else
		return a.workTime < b.workTime;
}
