#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {                 //2015019943 수학과 임은우
	int a, b, c;             //입력받을 메뉴번호, 연산을 할 두 수에 대한 변수를 선언합니다.
	for (;;) {               //for문을 이용해 무한루프를 설정합니다.
		printf("원하는 메뉴를 선택하세요.\n");
		printf("1. 더하기\n2. 빼기\n3. 곱하기\n4. 나누기\n0. 종료\n");
		scanf("%d", &a);
		if (a == 0) break;           //메뉴를 선택하라는 출력문과 입력받을 문자를 입력받고, 만약 입력받은 수가 0이라면 무한루프를 깨도록 설정합니다.

		switch (a)                    //switch문을 이용해 입력받은 a에 따라 어떤 연산을 할 것인지 설정 합니다.
		{
		case 1:
			printf("\n더하기를 선택하셨습니다.\n두 수를 입력하세요 \n");
			scanf("%d %d", &b, &c);
			printf("\n결과는\n%d + %d = %d\n입니다.\n", b, c, b + c);
			break;
		case 2:
			printf("\n빼기를 선택하셨습니다.\n두 수를 입력하세요 \n");
			scanf("%d %d", &b, &c);
			printf("\n결과는\n%d - %d = %d\n입니다.\n", b, c, b - c);
			break;
		case 3:
			printf("\n곱하기를 선택하셨습니다.\n두 수를 입력하세요 \n");
			scanf("%d %d", &b, &c);
			printf("\n결과는\n%d * %d = %d\n입니다.\n", b, c, b * c);
			break;
		case 4:
			printf("\n나누기를 선택하셨습니다.\n두 수를 입력하세요 \n");
			scanf("%d %d", &b, &c);
			if (c == 0) {
				printf("\n0으로 나눌 수 없습니다.\n\n");
			}
			else {
				printf("\n결과는\n%d / %d = %lf\n입니다.\n", b, c, (double)b / c);
			}
			break;
		default:         //만약 잘못된 메뉴변호가 입력되면 메뉴를 다시 출력하도록 switch문을 break하도록 설정합니다.
			break;
		}
		printf("\n");
	}
	return 0;
}