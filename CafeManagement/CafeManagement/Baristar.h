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
	int coffeeCnt = 0;
	string coffeeType = NULL;
}order;


/*
Class baristar => ���� �й���� �ٸ���Ÿ Ŭ����

Queue���� �ֹ��� pop�Ǿ� �й踦 �����ϸ�
�� �ٸ���Ÿ�� ���� �ߴ� �ð��� ��������
���� ���� �� �� �ٸ���Ÿ�� �ֹ��� ���� �ް� �ȴ�.


*/
typedef class Baristar {
	int completeOrderTime;
	queue<order> executeList;
	vector<order> outputList;

}baristar;


