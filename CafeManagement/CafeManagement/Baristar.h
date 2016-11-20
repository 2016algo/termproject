#pragma once
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
Struct order => 입력받는 주문 구조체
파일 입력 시 
1) 주문 시간 
2) 주문 받는 커피의 타입 개수 
3) 각 타입에 해당하는 커피 개수
를 저장해둔다.

주문 시간은 int형 변수로 저장하고 
커피 타입 개수와 각 타입에 해당하는 커피 개수는 
pair을 사용한 vector를 사용하여 저장한다.

orderTime : 주문 시간
coffeCnt : 주문 받은 커피 타입에 해당하는 커피 개수
coffeType : 주문받은 커피 타입

*/
typedef struct Order {
	int orderTime = 0;
	int makeingTime = 0;
	int coffeeCnt = 0;
	char coffeeType[10];
}order;


/*
Class baristar => 일을 분배받을 바리스타 클래스

Queue에서 주문이 pop되어 분배를 시작하면
각 바리스타가 일을 했던 시간을 기준으로
제일 일을 덜 한 바리스타가 주문을 먼저 받게 된다.

totalOrderTime: 바리스타가 순수하게 커피를 탄 시간
ability : 바리스타의 숙련도   int 형 자료형으로 생각중
tempWorktime : 커피타는 시간   int 형 자료형으로 생각중 
isWork : 현재 바리스타가 일을 하고 있는지 판별 bool 자료형으로 
*/
typedef struct Baristar {                  //바리스타를 typedef로 한의미를 모르겟음  
	int workTime=0;
	int totalWorkTime=0;


	//int toMakeCoffee(int ability)  바리스타가 커피를 만드는데 걸리는시간을 계산 해주는함수
}baristar;


