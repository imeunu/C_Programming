#define _CRT_SECURE_NO_WARNINGS          //2015019943 ���а� ������
#include <stdio.h>
#include <string.h>

void cipher(char* text, int num);        //��ȣȭ, ��ȣȭ �Լ��� �����մϴ�
void decipher(char* text, int num);

int main() {
    char text[80];                           //�̵��� ���ڸ� �����ϰ�, ������ ���� ���ڿ��� �����ͷ� �����Ͽ����ϴ�
    int num;
    printf("���ڿ��� �Է��Ͻÿ� : ");
    gets(text);                         //gets_s�Լ��� ������ �Է¹޽��ϴ�
    printf("\n�̵��� ���� �Է��Ͻÿ� : ");
    scanf("%d", &num);
    cipher(text, num);
    printf("��ȣȭ�� ���� : %s\n", text);
    decipher(text, num);
    printf("��ȣȭ�� ���� : %s", text);
    return 0;
}

void cipher(char* text, int num) {                 //��ȣȭ, ��ȣȭ �Լ��� ���� �Ű������� ������ �̵��� ���ڸ� �Է¹޽��ϴ�. �̶� ���ڿ��� �����ͷ� �����մϴ�
    int len = strlen(text);                        //���ڿ��� ���̸� len���� �����ϰ� for������ ���ڿ��� ���̸�ŭ �ݺ��ϵ��� �����մϴ�
    for (int i = 0; i < len; i++) {
        if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
            *(text + i) = ((*(text + i) + num - 13) % 26) + 65;
        }                                                         //���ĺ��� �� 26���̰�, 65�� 26���� ���� �������� 13���� �̿��Ͽ� ������ �ƽ�Ű�ڵ尡 A�� Z���̿�
        else if (*(text + i) >= 'a' && *(text + i) <= 'z') {      //�ִ� ��� (�Է¹�������+�����Ǿƽ�Ű�ڵ�-13)�� 26���� ���� ������ + 65�� �ϸ� ��ȣȭ�ϰ��� �ϴ�
                                                                  //�ƽ�Ű�ڵ��� ���� ���ɴϴ�. �ҹ����� ���� 97�� 26���� ���� �������� 19���� �̿��Ͽ����ϴ�
            *(text + i) = ((*(text + i) + num - 19) % 26) + 97;   //�������� ����Ͽ� z���Ŀ� a�� ���ƿ����� �����Ͽ���, ���ĺ��� �ƴѰ��(����, \n ��)�� �ڵ尪�� �״�� �ε��� �����߽��ϴ�.
        }
    }
}

void decipher(char* text, int num) {              //��ȣȭ�� ��ȣȭ�� �ݴ�� �������־����ϴ�.
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
            *(text + i) = ((*(text + i) - num - 13) % 26) + 65;
        }
        else if (*(text + i) >= 'a' && *(text + i) <= 'z') {

            *(text + i) = ((*(text + i) - num - 19) % 26) + 97;
        }
    }
}