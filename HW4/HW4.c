#define _CRT_SECURE_NO_WARNINGS          //2015019943 ���а� ������
#include <stdio.h>

void inputArray(int* p);     //inputArray,reverseArray �Լ��Դϴ�
void reverseArray(int* p);

int main() {
    int array[5];            //ũ�Ⱑ 5�� �迭�� �����ϰ�, �����ͷ� �� �迭�� �������ݴϴ�
    int* p = array;
    inputArray(array);                 //inputarray, reversearray �Լ��� ȣ���մϴ�
    reverseArray(array);
    printf("- �迭�� ������ �������� -\n");
    printf("���� �迭�� ���� : ");
    for (int i = 0; i < 5; i++) {       //�����Ϳ���� for������ ������ �迭�� ����մϴ�
        printf("%d ", *(p + i));
    }
    return 0;
}

void inputArray(int* p) {              //�ټ����� ������ �Է¹޴� inputarray�Լ��� for���� scanf�Լ��� �����մϴ�
    printf("�ټ����� ������ �Է��ϼ��� : ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &*(p + i));
    }
}

void reverseArray(int* p) {       //ù��°�� �ټ���° �迭, �ι�°�� �׹�° �迭�� �ڸ��� �ٲ��ֵ��� reversearray�Լ��� �����մϴ�
    int a, b;
    a = *p;
    b = *(p + 1);
    *p = *(p + 4);
    *(p + 1) = *(p + 3);
    *(p + 3) = b;
    *(p + 4) = a;
}