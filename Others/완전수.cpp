#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, sum;
	do {
		printf("���� �Է��Ͻÿ� : ");
		scanf("%d", &n);

		printf("%d�� ����� ", n);
		sum = 0;
		for (i = 1; i <= n; i++) {
			if (n % i == 0) {
				printf("%d ", i);
				sum += i;
			}
		}
		printf("�Դϴ�\n����� ���� %d�Դϴ�\n\n", sum);
		if (n == sum - n ) {
			printf("%d�� ������ �Դϴ�\n\n",n);
		}
	} while (n > 0);
	return 0;
}   