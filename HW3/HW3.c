#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {                 //2015019943 ���а� ������
	double score[5];         //5���� �������� ������ �ִ밪, �ּҰ�, ���̵�, ���������� �����մϴ�
	double max, min, diff, final;
	int cont;                //�޴����� �Է¹��� ������ �����մϴ�
	while (1) {
		printf("���̵��� �Է��ϼ��� : ");   //���ѷ����� ���� �ĳ��̵�, �׸��� �ݺ������� �������� ������ �Է¹޽��ϴ�
		scanf("%lf", &diff);
		min = 10, max = 0;
		for (int i = 0; i < 5; i++) {
			printf("%d��° ä���� ���� : ", i + 1);
			scanf("%lf", &score[i]);
			if (score[i] >= max) {          //�ʱ� �ִ밪�� 0, �ּҰ��� 10���� �Է¹��� ��, �������� ������ �Է¹��������� �ִ�,�ּҰ��� ���Ͽ� �������ݴϴ�
				max = score[i];
			}
			if (score[i] <= min) {
				min = score[i];
			}
		}
		printf("���\n==========================\n");

		for (int i = 0; i < 5; i++) {      //�Է¹��� �������� �����ϰ�, ������ �ִ�,�ּҰ����� (m),(M)�� ����ϵ��� �����մϴ�
			printf("%.1lf", score[i]);
			if (max == score[i]) {
				printf("(M)");
			}
			if (min == score[i]) {
				printf("(m)");
			}
			printf(" ");
		}
		printf("\n==========================\n");   //���������� �� �������� ������ �տ��� �ִ�� �ּҰ��� �� ���� ���̵��� ���Ѱ����� �����մϴ�
		final = diff * (score[0] + score[1] + score[2] + score[3] + score[4] - min - max);
		printf("\nScore : %.1lf\n\n", final);
		printf("����Ͻðڽ��ϱ�?(1:���/2:����)\n"); //���� 2.���� �� �����ϸ� ���ѷ����� break�ϵ��� �����մϴ�
		scanf("%d", &cont);
		if (cont == 2) break;
	}
	return 0;
}