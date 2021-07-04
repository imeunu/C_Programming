#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {                 //2015019943 수학과 임은우
	double score[5];         //5명의 감독관의 점수와 최대값, 최소값, 난이도, 최종점수를 선언합니다
	double max, min, diff, final;
	int cont;                //메뉴에서 입력받을 정수를 선언합니다
	while (1) {
		printf("난이도를 입력하세요 : ");   //무한루프를 설정 후난이도, 그리고 반복문으로 감독관의 점수를 입력받습니다
		scanf("%lf", &diff);
		min = 10, max = 0;
		for (int i = 0; i < 5; i++) {
			printf("%d번째 채점관 점수 : ", i + 1);
			scanf("%lf", &score[i]);
			if (score[i] >= max) {          //초기 최대값을 0, 최소값을 10으로 입력받은 후, 감독관의 점수를 입력받을때마다 최대,최소값을 비교하여 갱신해줍니다
				max = score[i];
			}
			if (score[i] <= min) {
				min = score[i];
			}
		}
		printf("결과\n==========================\n");

		for (int i = 0; i < 5; i++) {      //입력받은 점수들을 나열하고, 각각이 최대,최소값을때 (m),(M)을 출력하도록 설정합니다
			printf("%.1lf", score[i]);
			if (max == score[i]) {
				printf("(M)");
			}
			if (min == score[i]) {
				printf("(m)");
			}
			printf(" ");
		}
		printf("\n==========================\n");   //최종점수는 각 감독관의 점수의 합에서 최대와 최소값을 뺀 값에 난이도를 곱한것으로 설정합니다
		final = diff * (score[0] + score[1] + score[2] + score[3] + score[4] - min - max);
		printf("\nScore : %.1lf\n\n", final);
		printf("계속하시겠습니까?(1:계속/2:중지)\n"); //만약 2.종료 를 선택하면 무한루프를 break하도록 설정합니다
		scanf("%d", &cont);
		if (cont == 2) break;
	}
	return 0;
}