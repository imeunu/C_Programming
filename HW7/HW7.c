#define _CRT_SECURE_NO_WARNINGS             //2015019943 ���а� ������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* makeVector(int a) {                    //�����Ҵ��Ͽ� �迭�� ����� �Լ��� ��������ϴ�
	int* vector = (int*)calloc(a, sizeof(int)); //main�Լ����� ���̸� �޾Ƽ� for���� ����Ͽ� 
	*vector = rand() % 10 + 1;                  //0���� 10������ ������ 0���� �����ϴ� ������� ��������ϴ�
	for (int i = 1; i < a; i++) {
		*(vector + i) = *(vector + i - 1) + rand() % 10 + 1;
	}
	return vector;
}

int printVector(int* A, int a) {          //�迭�� ����ϴ� �Լ��� �����Ͽ����ϴ�
	printf("[");
	for (int i = 0; i < a; i++) {
		printf("%3d", *(A + i));
	}
	printf("]\n");
}

int main() {
	int a, b;                         //�迭�� ũ�⸦ �Է¹��� a,b�� �����մϴ�
	int count1 = 0, count2 = 0;       //C�迭�� ����� ���� count1,count2�� �����Ͽ����ϴ�
	int* A, * B;                      //A,B�迭�� ����� ���� A,B �����͸� �����մϴ�
	srand(time(NULL));

	printf("�迭 A�� ũ��� ? ");
	scanf("%d", &a);
	printf("�迭 B�� ũ��� ? ");
	scanf("%d", &b);

	A = makeVector(a);
	B = makeVector(b);

	int* C = (int*)calloc(a + b, sizeof(int));
	for (int i = 0; i < a + b; i++) {
		if (*(A + count1) <= *(B + count2)) {  //A,B�迭�� count1,count2��° ������ �� ���� ���� C�迭��i��° ���ҷ� �����մϴ�
			*(C + i) = *(A + count1);
			count1++;
		}
		else {
			*(C + i) = *(B + count2);
			count2++;
		}
		if (count1 == a) {                     //���� count1��a�� �����ϸ� C�� i+1��° ���Һ��ʹ� B�� count2+1��° ���ҷ� ���
			for (int j = i + 1; j < a + b; j++) { //ä���, for���� ������� �����Ͽ����ϴ�
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
	for (int i = 0; i < 4 + 3 * b; i++) {   //-�� ������ B�迭�� ���̿� �°� ��µǵ��� �����Ͽ����ϴ�
		printf("-");
	}
	printf("\n���յ� �迭 (ũ�� : %d)\nC ", a + b);
	printVector(C, a + b);

	free(A);   //calloc�Լ��� ����Ͽ����� free�Լ��� ����Ͽ����ϴ�
	free(B);
	free(C);
	return 0;
}