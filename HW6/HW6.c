#define _CRT_SECURE_NO_WARNINGS             //2015019943 ���а� ������
#include <stdio.h>
#include <string.h>

char myid[7] = "imeunu";                    //���������� ���̵�� ��й�ȣ�� �����մϴ�
char mypw[5] = "1234";


int login(char* id, char* pw) {            //��ȯ���� �������� login�Լ��� ���� ���������� �õ�Ƚ���� �����մϴ�
    static int try = 3;
    if (strcmp(myid, id) != 0 || strcmp(mypw, pw) != 0) {      //����� ���̵�,��й�ȣ�� �Է¹����Ͱ� strcmp�Լ��� ���Ͽ� �������� �������� �����մϴ�
        try--;
        if (try == 0) {
            printf("\n�α��ο� �����Ͽ����ϴ�. ���α׷��� �����մϴ�."); //�α��ο� �����ϰų� 3ȸ �����ϸ� 0�� ��ȯ�ϵ��� �����մϴ�
            return 0;
        }
        printf("\n�α��ο� �����߽��ϴ�.\n");
        printf("�α��� �õ� Ƚ�� %dȸ ���ҽ��ϴ�.\n\n", try);
    }
    else {
        printf("\n�α��� ����!");
        return 0;
    }
}

int main() {
    char id[100], pw[100];                    //�Է¹��� ���̵�� ��й�ȣ�� �����մϴ�
    int a;
    while (1) {
        printf("�α����ϼ���\n");             //���̵�� ��й�ȣ�� �Է¹޴� ���ѷ����� �����ϰ�, ��ȯ�޴� ���� 0�� ���, break�ϵ��� �����մϴ�
        printf("���̵� : ");
        scanf("%s", &id);
        printf("��ȣ : ");
        scanf("%s", &pw);
        a = login(id, pw);
        if (a == 0) break;
    }
    return 0;
}