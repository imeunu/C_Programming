#define _CRT_SECURE_NO_WARNINGS             //2015019943 수학과 임은우
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
	printf("총 %d명\n", n);
}

SCORE scoreinput() {
	SCORE me;
	printf("이름 : ");
	scanf("%s", me.name);
	printf("성적 (국어 영어 수학) : ");
	scanf("%d %d %d", &me.kor, &me.eng, &me.mat);
	printf("### 입력되었습니다\n");
	return me;
}
int main() {
	SCORE* a = NULL;
	int n = 0, menu;

	while (1) {
		printf("[성적관리]1.입력 2.출력 0.종료\n");
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