#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void cipher(char* text, int num);        //암호화, 복호화 함수를 선언합니다
void decipher(char* text, int num);

int main() {
    char text[80];                           //이동할 숫자를 선언하고, 원문에 대한 문자열을 포인터로 선언하였습니다
    int num;
    printf("문자열을 입력하시오 : ");
    gets(text);                         //gets_s함수로 원문을 입력받습니다
    printf("\n이동할 수를 입력하시오 : ");
    scanf("%d", &num);
    cipher(text, num);
    printf("암호화한 문장 : %s\n", text);
    decipher(text, num);
    printf("복호화한 문장 : %s", text);
    return 0;
}

void cipher(char* text, int num) {                 //암호화, 복호화 함수에 대한 매개변수로 원문과 이동할 숫자를 입력받습니다. 이때 문자열은 포인터로 설정합니다
    int len = strlen(text);                        //문자열의 길이를 len으로 설정하고 for문으로 문자열의 길이만큼 반복하도록 설정합니다
    for (int i = 0; i < len; i++) {
        if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
            *(text + i) = ((*(text + i) + num - 13) % 26) + 65;
        }                                                         //알파벳이 총 26자이고, 65를 26으로 나눈 나머지가 13임을 이용하여 문자의 아스키코드가 A와 Z사이에
        else if (*(text + i) >= 'a' && *(text + i) <= 'z') {      //있는 경우 (입력받은숫자+문자의아스키코드-13)을 26으로 나눈 나머지 + 65를 하면 암호화하고자 하는
                                                                  //아스키코드의 값이 나옵니다. 소문자인 경우는 97을 26으로 나눈 나머지가 19임을 이용하였습니다
            *(text + i) = ((*(text + i) + num - 19) % 26) + 97;   //나머지를 사용하여 z이후에 a로 돌아오도록 설정하였고, 알파벳이 아닌경우(공백, \n 등)은 코드값을 그대로 두도록 설정했습니다.
        }
    }
}

void decipher(char* text, int num) {              //복호화는 암호화와 반대로 설정해주었습니다.
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
