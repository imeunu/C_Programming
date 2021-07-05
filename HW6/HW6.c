#define _CRT_SECURE_NO_WARNINGS             //2015019943 수학과 임은우
#include <stdio.h>
#include <string.h>

char myid[7] = "imeunu";                    //전역변수에 아이디와 비밀번호를 저장합니다
char mypw[5] = "1234";


int login(char* id, char* pw) {            //반환형이 정수형인 login함수에 정적 지역변수를 시도횟수로 저장합니다
    static int try = 3;
    if (strcmp(myid, id) != 0 || strcmp(mypw, pw) != 0) {      //저장된 아이디,비밀번호를 입력받은것과 strcmp함수로 비교하여 성공인지 실패인지 결정합니다
        try--;
        if (try == 0) {
            printf("\n로그인에 실패하였습니다. 프로그램을 종료합니다."); //로그인에 성공하거나 3회 실패하면 0을 반환하도록 설정합니다
            return 0;
        }
        printf("\n로그인에 실패했습니다.\n");
        printf("로그인 시도 횟수 %d회 남았습니다.\n\n", try);
    }
    else {
        printf("\n로그인 성공!");
        return 0;
    }
}

int main() {
    char id[100], pw[100];                    //입력받을 아이디와 비밀번호를 선언합니다
    int a;
    while (1) {
        printf("로그인하세요\n");             //아이디와 비밀번호를 입력받는 무한루프를 설정하고, 반환받는 값이 0일 경우, break하도록 설정합니다
        printf("아이디 : ");
        scanf("%s", &id);
        printf("암호 : ");
        scanf("%s", &pw);
        a = login(id, pw);
        if (a == 0) break;
    }
    return 0;
}