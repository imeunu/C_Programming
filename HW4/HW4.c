#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inputArray(int* p);     //inputArray,reverseArray 함수입니다
void reverseArray(int* p);

int main() {
    int array[5];            //크기가 5인 배열을 선언하고, 포인터로 그 배열을 지정해줍니다
    int* p = array;
    inputArray(array);                 //inputarray, reversearray 함수를 호출합니다
    reverseArray(array);
    printf("- 배열의 내용을 뒤집는중 -\n");
    printf("최종 배열의 내용 : ");
    for (int i = 0; i < 5; i++) {       //포인터연산과 for문으로 뒤집은 배열을 출력합니다
        printf("%d ", *(p + i));
    }
    return 0;
}

void inputArray(int* p) {              //다섯개의 정수를 입력받는 inputarray함수를 for문과 scanf함수로 설정합니다
    printf("다섯개의 정수를 입력하세요 : ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &*(p + i));
    }
}

void reverseArray(int* p) {       //첫번째와 다섯번째 배열, 두번째와 네번째 배열의 자리를 바꿔주도록 reversearray함수를 설정합니다
    int a, b;
    a = *p;
    b = *(p + 1);
    *p = *(p + 4);
    *(p + 1) = *(p + 3);
    *(p + 3) = b;
    *(p + 4) = a;
}
