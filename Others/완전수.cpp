#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, sum;
	do {
		printf("수를 입력하시오 : ");
		scanf("%d", &n);

		printf("%d의 약수는 ", n);
		sum = 0;
		for (i = 1; i <= n; i++) {
			if (n % i == 0) {
				printf("%d ", i);
				sum += i;
			}
		}
		printf("입니다\n약수의 합은 %d입니다\n\n", sum);
		if (n == sum - n ) {
			printf("%d는 완전수 입니다\n\n",n);
		}
	} while (n > 0);
	return 0;
}   