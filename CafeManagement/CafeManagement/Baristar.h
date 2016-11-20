#pragma once
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
Struct order => �Է¹޴� �ֹ� ����ü
���� �Է� �� 
1) �ֹ� �ð� 
2) �ֹ� �޴� Ŀ���� Ÿ�� ���� 
3) �� Ÿ�Կ� �ش��ϴ� Ŀ�� ����
�� �����صд�.

�ֹ� �ð��� int�� ������ �����ϰ� 
Ŀ�� Ÿ�� ������ �� Ÿ�Կ� �ش��ϴ� Ŀ�� ������ 
pair�� ����� vector�� ����Ͽ� �����Ѵ�.

orderTime : �ֹ� �ð�
coffeCnt : �ֹ� ���� Ŀ�� Ÿ�Կ� �ش��ϴ� Ŀ�� ����
coffeType : �ֹ����� Ŀ�� Ÿ��

*/
typedef struct Order {
	int orderTime = 0;
	int makeingTime = 0;
	int coffeeCnt = 0;
	char coffeeType[10];
}order;


/*
Class baristar => ���� �й���� �ٸ���Ÿ Ŭ����

Queue���� �ֹ��� pop�Ǿ� �й踦 �����ϸ�
�� �ٸ���Ÿ�� ���� �ߴ� �ð��� ��������
���� ���� �� �� �ٸ���Ÿ�� �ֹ��� ���� �ް� �ȴ�.

totalOrderTime: �ٸ���Ÿ�� �����ϰ� Ŀ�Ǹ� ź �ð�
ability : �ٸ���Ÿ�� ���õ�   int �� �ڷ������� ������
tempWorktime : Ŀ��Ÿ�� �ð�   int �� �ڷ������� ������ 
isWork : ���� �ٸ���Ÿ�� ���� �ϰ� �ִ��� �Ǻ� bool �ڷ������� 
*/
typedef struct Baristar {                  //�ٸ���Ÿ�� typedef�� ���ǹ̸� �𸣰���  
	int workTime=0;
	int totalWorkTime=0;


	//int toMakeCoffee(int ability)  �ٸ���Ÿ�� Ŀ�Ǹ� ����µ� �ɸ��½ð��� ��� ���ִ��Լ�
}baristar;


