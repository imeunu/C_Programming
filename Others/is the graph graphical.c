#define _CRT_SECURE_NO_WARNINGS             //2015019943 수학과 임은우
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n,m;
	int* A = NULL, * B = NULL;


	while (1) {
	    printf("degree : ");
	    scanf("%d", &n);

	    A = (int*)realloc(A, n * sizeof(int));
	    B = (int*)realloc(B, (n - 1) * sizeof(int));
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}

		for (int i = 0; i < A[0]; i++) {
			*(B + i) = *(A + i + 1) - 1;
		}
		for (int i = A[0]; i < n - 1; i++) {
			*(B + i) = *(A + i + 1);
		}
		for (int i = 0; i < n - 1; i++) {
			printf("%3d", B[i]);
		}
		printf("\ncontinue? (yes : 0, no : 1)");
		scanf("%d", &m);
		if (m == 1)
			break;
	}

	free(A);
	free(B);
	return 0;
}