#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {                 //2015019943 ���а� ������
	int a, b, c;             //�Է¹��� �޴���ȣ, ������ �� �� ���� ���� ������ �����մϴ�.
	for (;;) {               //for���� �̿��� ���ѷ����� �����մϴ�.
		printf("���ϴ� �޴��� �����ϼ���.\n");
		printf("1. ���ϱ�\n2. ����\n3. ���ϱ�\n4. ������\n0. ����\n");
		scanf("%d", &a);
		if (a == 0) break;           //�޴��� �����϶�� ��¹��� �Է¹��� ���ڸ� �Է¹ް�, ���� �Է¹��� ���� 0�̶�� ���ѷ����� ������ �����մϴ�.

		switch (a)                    //switch���� �̿��� �Է¹��� a�� ���� � ������ �� ������ ���� �մϴ�.
		{
		case 1:
			printf("\n���ϱ⸦ �����ϼ̽��ϴ�.\n�� ���� �Է��ϼ��� \n");
			scanf("%d %d", &b, &c);
			printf("\n�����\n%d + %d = %d\n�Դϴ�.\n", b, c, b + c);
			break;
		case 2:
			printf("\n���⸦ �����ϼ̽��ϴ�.\n�� ���� �Է��ϼ��� \n");
			scanf("%d %d", &b, &c);
			printf("\n�����\n%d - %d = %d\n�Դϴ�.\n", b, c, b - c);
			break;
		case 3:
			printf("\n���ϱ⸦ �����ϼ̽��ϴ�.\n�� ���� �Է��ϼ��� \n");
			scanf("%d %d", &b, &c);
			printf("\n�����\n%d * %d = %d\n�Դϴ�.\n", b, c, b * c);
			break;
		case 4:
			printf("\n�����⸦ �����ϼ̽��ϴ�.\n�� ���� �Է��ϼ��� \n");
			scanf("%d %d", &b, &c);
			if (c == 0) {
				printf("\n0���� ���� �� �����ϴ�.\n\n");
			}
			else {
				printf("\n�����\n%d / %d = %lf\n�Դϴ�.\n", b, c, (double)b / c);
			}
			break;
		default:         //���� �߸��� �޴���ȣ�� �ԷµǸ� �޴��� �ٽ� ����ϵ��� switch���� break�ϵ��� �����մϴ�.
			break;
		}
		printf("\n");
	}
	return 0;
}