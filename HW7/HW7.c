#define _CRT_SECURE_NO_WARNINGS             //2015019943 수학과 임은우
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* makeVector(int a) {                    //동적할당하여 배열을 만드는 함수를 만들었습니다
	int* vector = (int*)calloc(a, sizeof(int)); //main함수에서 길이를 받아서 for문을 사용하여 
	*vector = rand() % 10 + 1;                  //0에서 10까지의 난수를 0에서 누적하는 방법으로 만들었습니다
	for (int i = 1; i < a; i++) {
		*(vector + i) = *(vector + i - 1) + rand() % 10 + 1;
	}
	return vector;
}

int printVector(int* A, int a) {          //배열을 출력하는 함수를 선언하였습니다
	printf("[");
	for (int i = 0; i < a; i++) {
		printf("%3d", *(A + i));
	}
	printf("]\n");
}

int main() {
	int a, b;                         //배열의 크기를 입력받을 a,b를 선업합니다
	int count1 = 0, count2 = 0;       //C배열을 만들기 위해 count1,count2을 선언하였습니다
	int* A, * B;                      //A,B배열을 만들기 위해 A,B 포인터를 선언합니다
	srand(time(NULL));

	printf("배열 A의 크기는 ? ");
	scanf("%d", &a);
	printf("배열 B의 크기는 ? ");
	scanf("%d", &b);

	A = makeVector(a);
	B = makeVector(b);

	int* C = (int*)calloc(a + b, sizeof(int));
	for (int i = 0; i < a + b; i++) {
		if (*(A + count1) <= *(B + count2)) {  //A,B배열의 count1,count2번째 원소중 더 작은 수를 C배열의i번째 원소로 지정합니다
			*(C + i) = *(A + count1);
			count1++;
		}
		else {
			*(C + i) = *(B + count2);
			count2++;
		}
		if (count1 == a) {                     //만약 count1이a에 도달하면 C의 i+1번째 원소부터는 B의 count2+1번째 원소로 모두
			for (int j = i + 1; j < a + b; j++) { //채우고, for문을 벗어나도록 설정하였습니다
				*(C + j) = *(B + count2);
				count2++;
			}
			break;
		}
		if (count2 == b) {
			for (int j = i + 1; j < a + b; j++) {
				*(C + j) = *(A + count1);
				count1++;
			}
			break;
		}
	}

	printf("\nA ");
	printVector(A, a);
	printf("B ");
	printVector(B, b);
	for (int i = 0; i < 4 + 3 * b; i++) {   //-의 개수는 B배열의 길이에 맞게 출력되도록 설정하였습니다
		printf("-");
	}
	printf("\n병합된 배열 (크기 : %d)\nC ", a + b);
	printVector(C, a + b);

	free(A);   //calloc함수를 사용하였으니 free함수를 사용하였습니다
	free(B);
	free(C);
	return 0;
}