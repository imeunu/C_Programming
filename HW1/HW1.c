#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int age, d, price=0 ;               //나이는 age, 거리는 d, 추가요금은 p
	printf("나이를 입력하시오: ");
	scanf("%d", &age);                   //나이 입력 받기
	printf("이용한 거리 (km)를 입력하시오: ");          
	scanf("%d", &d);                    //거리입력받기
	
	if (d > 10 && d <= 50) {                 //거리가 10초과 50이하일때 추가요금 계산
		d = d - 10;
		if (d % 5 == 0) price = (d / 5) * 100;
		else price = ((d / 5) + 1) * 100;
	}
	else if (d > 50) {                       //거리가 50초과일때 추가요금 계산
		d = d - 50;
		if (d % 8 == 0) price = (d / 8) * 100 + 800;
		else price = ((d / 8) + 1) * 100 + 800;
	}


	if (age >= 19 && age<65) {              //일반 운임 기본요금에 초과요금 더함
		price = 1250 + price;
		printf("승객구분 : 일반\n");
		printf("교통카드 사용시 운임 : %d원",price);

	}
	else if (age <= 12 && age >= 7) {           // 어린이 운임 기본요금에 350빼고 50%할인
		price = (900 + price) * 0.5;
		printf("승객구분 : 어린이\n");
		printf("교통카드 사용시 운임 : %d원",price);
	}
	else if (age <= 18 && age >= 13) {             // 청소년 운임 기본요금에 350빼고 20%할인
		price = (900 + price) * 0.8;
		printf("승객구분 : 청소년\n");
		printf("교통카드 사용시 운임 : %d원",price);
	}
	else if (age >= 65) {                            //경로 운임 0원
		price = 0;
		printf("승객구분 : 경로\n");
		printf("교통카드 사용시 운임 : %d원",price);
	}
	else if (age < 7) {                                //유아 운임 0원
		price = 0;
		printf("승객구분 : 유아\n");
		printf("교통카드 사용시 운임 : %d원",price);
	}
	return 0;
}
