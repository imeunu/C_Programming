#define _CRT_SECURE_NO_WARNINGS             //2015019943 ���а� ������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	char name[20];
	int kor, eng, mat;
}SCORE;


void scoreprint(SCORE me) {
	printf("========================\m");
	printf("%s %d %d %d %.1lf\n", me.name, me.kor, me.eng, me.mat, (me.kor + me.eng + me.mat) / 3.0);
	printf("========================\m");
}

void scoreprintaray(SCORE *a, int n) {
	printf("========================\m");
	for (int i = 0; i < 5; i++) {
		printf("%s %d %d %d %.1lf\n", (a + i)->name, (a + i)->.kor, (a + i)->eng, (a + i)->mat, ((a + i)->kor + (a + i)->eng + (a + i)->mat) / 3.0);
	}
	printf("========================\m");
	printf("�� %d��\n", n);
}

SCORE scoreinput() {
	SCORE me;
	printf("�̸� : ");
	scanf("%s", me.name);
	printf("���� (���� ���� ����) : ");
	scanf("%d %d %d", &me.kor, &me.eng, &me.mat);
	printf("### �ԷµǾ����ϴ�\n");
	return me;
}
int main() {
	SCORE* a = NULL;
	int n = 0, menu;

	while (1) {
		printf("[��������]1.�Է� 2.��� 0.����\n");
		scanf("%d", &menu);
		if (menu == 0)
			break;
		if (menu == 1) {
			a = (SCORE*)realloc(a, (n + 1) * sizeof(SCORE));
			a[n] = scoreinput(); 
			n++;
			}
		else if (menu == 2) {
			scoreprintarray(a, n); 
		}
	}
    free(a);
	return 0;
}