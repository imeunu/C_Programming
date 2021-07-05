#define _CRT_SECURE_NO_WARNINGS               //2015019943 수학과 임은우
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)                              //구조체의 메모리를 효율적으로 사용하기 위하여 pragma pack(1)을 선언하였습니다

typedef struct {                            //구조체로 과목명, 교수명, 강의실, 학점, 주당강의횟수, 시작시간, 요일, 강의시간을 LECTURE로 선언하였습니다
    char name[5];
    char teacher[10];
    int room, point, num, * time, * day, * start;
}LECTURE;

int date[2] = { 0,0 }, hour1, hour2, n = 0;    //전역변수로 시작요일, 마지막요일, 시작시간, 마지막시간, 과목의 갯수를 선언하였습니다

int returnweek(char* a);
int deletelecture(LECTURE* course, int* table);
void tableprint(int* table, LECTURE* course);
void tablestatus(int* table, LECTURE* course);
LECTURE inputlecture(int* table);

int main() {
    int menu;
    char start[5], end[5];
    LECTURE temp;
    LECTURE* course = NULL;
    while (1) {
        printf("시간표의 시작 요일과 마지막 요일을 입력하세요 : ");              //시작요일과 마지막요일을 returnweek함수로 정수형으로 돌려받도록 하였습니다
        scanf("%s", start);
        scanf("%s", end);
        date[0] = returnweek(start);
        date[1] = returnweek(end);
        printf("시작시간과 종료 시각을 24시 단위로 입력해주세요 : ");           //시간표를 보여주기 위하여 입력받은 요일들과 시간들(원소)를 모두 0으로 저장되도록 동적할당하였습니다
        scanf("%d %d", &hour1, &hour2);
        if (date[1] - date[0] < 0 || date[1] - date[0]>6) {                 //시작요일보다 마지막요일이 앞설경우, 오류메세지를 띄우도록 하였습니다
            printf("요일을 올바르게 입력해 주세요\n");                         //모두 제대로 입력받은 경우에만 진행 가능하도록 하였습니다
        }
        else if (hour2 < hour1) {
            printf("시간을 올바르게 입력해 주세요\n");
        }
        else break;
    }
    int* table = (int*)calloc((date[1] - date[0] + 1) * (hour2 - hour1 + 1), sizeof(int));
    while (1) {
        tableprint(table, course);                    //무한루프를 설정하고, 매번 시간표를 먼저 출력하고 메뉴를 입력받도록 하였습니다
        printf("\n[시간표] 1.과목입력 2.과목삭제 3.시간표현황 0.종료");
        scanf("%d", &menu);
        if (menu == 0)                                //먼저, n+1만큼 재할당해주고, 오류가 나면 n으로 재할당하고, 안나면 진행하는 식으로 하였습니다
            break;
        if (menu == 1) {                              //메뉴가0이면 종료, 1이면 inputlecture함수를 실행시킵니다
            temp = inputlecture(table);               //임시로 temp에 input의 정보를 저장해줍니다
            if (temp.point == -1) {                   //학점이 -1이라면, 추가가 취소되었다고 메세지를 띄웁니다
                printf("과목 입력이 취소되었습니다\n");
            }
            else {
                course = (LECTURE*)realloc(course, (n + 1) * sizeof(LECTURE));
                course[n] = temp;
                printf("추가되었습니다\n");              //학점이 -1이 아니라면, 오류가 발생하지 않은 것이므로 메세지를 띄웁니다(input함수에서 자세히)
                n++;                                   //temp에 저장된 정보를 course의 n번째 배열에 저장해줍니다
            }
        }
        else if (menu == 2) {
            menu = deletelecture(course, table);        //deletelecture의 반환값이 -1이면 삭제승인이 된것이므로 메세지를 띄웁니다
            if (menu == -1) {
                printf("삭제되었습니다.\n");             //menu는 루프를 돌며 계속 입력받을 값이므로 여기에서만 재활용 하였습니다
            }
            else if (menu == 1) {
                printf("삭제가 취소되었습니다.\n");        //반환값이 1이면 삭제승인이 되지 않은 것이므로 메세지를 띄웁니다
            }
        }
        else if (menu == 3) {
            tablestatus(table, course);
        }
        else
            printf("다시 입력해주세요\n");
    }
    for (int i = 0; i < n; i++) {                       //동적할당을 하였으므로 모두 free함수를 사용하여줍니다
        free(course[i].day);
        free(course[i].start);
        free(course[i].time);
    }
    free(course);
    free(table);
    return 0;
}

int returnweek(char* day) {              //입력받은 값을 월화수목금토일과 비교하여 시작요일, 마지막요일을 정수로 변환해줍니다
    int date;
    if (strcmp(day, "월") == 0)
        date = 0;
    else if (strcmp(day, "화") == 0)
        date = 1;
    else if (strcmp(day, "수") == 0)
        date = 2;
    else if (strcmp(day, "목") == 0)
        date = 3;
    else if (strcmp(day, "금") == 0)
        date = 4;
    else if (strcmp(day, "토") == 0)
        date = 5;
    else if (strcmp(day, "일") == 0)
        date = 6;
    return date;
}

void tableprint(int* table, LECTURE* course) {
    char week[15] = "월화수목금토일";
    for (int a = 0; a < 8 * (date[1] - date[0] + 1) + 4; a++) {  //요일의 길이에 맞춰 ----를 출력하도록 설정하였습니다
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 2 * (date[1] - date[0] + 1); i += 2) {   //week[15]를 설정하고, 지정한 요일의 이름을 찾아서 출력하도록 하였습니다
        printf("\t%c%c", week[2 * date[0] + i], week[2 * date[0] + i + 1]);
    }
    for (int i = 0; i < hour2 - hour1 + 1; i++) {
        printf("\n");
        for (int a = 0; a < 8 * (date[1] - date[0] + 1) + 4; a++) {
            printf("-");
        }
        printf("\n");
        printf("%02d", hour1 + i);                               //9시면 09시라고 출력되도록 설정하였습니다
        for (int j = 0; j < (date[1] - date[0]) + 1; j++) {
            printf("\t");
            for (int k = 0; k < n; k++) {
                if (*(table + (hour2 - hour1 + 1) * j + i) == k + 1) { //원소가 0 이 아니면 0부터 n까지 돌며 해당 원소에 해당하는 과목명을 출력합니다
                    printf("%s", course[k].name);
                }
            }
        }
    }
    printf("\n");
    for (int a = 0; a < 8 * (date[1] - date[0] + 1) + 4; a++) {
        printf("-");
    }
    printf("\n");
}

LECTURE inputlecture(int* table) {
    LECTURE a;                     //지역변수 name[20]으로 과목명을 입력받고, 첫 두문자가 영어인지 한글인지 인식하고 첫 두글자를 반환해줍니다
    char name[20];                 //입력받을 LECTURE a를 지역변수로 선언하고, 정보를 입력받습니다
    printf("과목명 : ");
    scanf("%s", name);
    if (name[0] > 0) {
        if (name[1] > 0) {
            name[2] = NULL;
        }
        else name[3] = NULL;
    }
    else if (name[0] < 0) {
        if (name[2] > 0) {
            name[2] = NULL;
        }
        else name[4] = NULL;
    }
    strcpy(a.name, name);
    printf("교수명 : ");
    scanf("%s", a.teacher);
    printf("강의실 : ");
    scanf("%d", &a.room);
    printf("학점 : ");
    scanf("%d", &a.point);
    printf("주당강의횟수 : ");
    scanf("%d", &a.num);
    a.time = (int*)calloc(a.num, sizeof(int));   //구조체의 각 멤버를 입력받고, 주당강의 횟수만큼 강의요일, 강의시간, 시작시간을 동적할당하여 입력받습니다
    a.day = (int*)calloc(a.num, sizeof(int));
    a.start = (int*)calloc(a.num, sizeof(int));
    for (int i = 0; i < a.num; i++) {
        printf("\n<강의%d>", i + 1);
        printf("강의요일 : ");                //메모리를 아끼기 위하여 지역변수 name[20]을 재사용하였습니다
        scanf("%s", name);
        *(a.day + i) = returnweek(name) - date[0];         //강의요일은 시간표에서 정확한 위치에 찍히게 하기 위하여 시작요일을 빼주었습니다.
        if (*(a.day + i) > date[1] - date[0] || *(a.day + i) < 0) {       //만약 강의요일이 유효한 범위에 있지 않은 경우, 오류메세지를 출력하고 함수를 종료시킵니다
            printf("오류### 해당 요일에 입력할 수 없습니다.\n"); //오류가 생긴 경우, 학점에 -1을 대입하고 a를 반환합니다
            a.point = -1;
            free(a.time);
            free(a.day);
            free(a.start);
            return a;
        }
        printf("시작시간 : ");
        scanf("%d", a.start + i);
        printf("강의시간 : ");
        scanf("%d", a.time + i);
        for (int j = 0; j < *(a.time + i); j++) {
            if (*(a.start + i) + j > hour2 || *(a.start + i) + j < hour1) {  //만약 입력받은 시작시간부터 강의시간까지의 시간이 시작시간에서 마지막 시간을 벗어나는 경우 오류를 출력합니다
                printf("###오류 해당 시간에 입력할 수 없습니다.\n");
                a.point = -1;
                free(a.time);
                free(a.day);
                free(a.start);
                return a;
            }
            if (*(table + (hour2 - hour1 + 1) * (*(a.day + i)) + (*(a.start + i)) - hour1 + j) != 0) {
                printf("오류### 해당 시간에 이미 수업이 존재합니다.\n");
                a.point = -1;                                //만약 시간표에 0이 아닌 정수가 있다면 수업이 존재하는 것이므로 오류를 출력합니다
                free(a.time);
                free(a.day);
                free(a.start);
                return a;
            }
        }
        for (int j = 0; j < *(a.time + i); j++) {
            *(table + (hour2 - hour1 + 1) * (a.day[i]) + (a.start[i]) - hour1 + j) = n + 1;
        }
    }
    return a; //오류가 나지 않은 경우엔 해당 수업에 해당하는 시간표에 있는 원소들에 n+1을 대입해주고, 과목수를 1 증가시키고 a을 반환합니다
}

int deletelecture(LECTURE* course, int* table) {
    char name[5];
    int menu, sum = 0;
    char week[15] = "월화수목금토일";
    printf("삭제할 과목명의 앞 두글자를 입력해주세요 : ");        //지역변수name을 이용해 과목명의 앞두글자를 입력받고 for문을 돌며 일치하는 과목명을 찾습니다
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(name, course[i].name) == 0) {
            printf("다음 과목을 삭제하시겠습니까?\n");           //사용자에게 확인을 받는 메세지를 출력하고 강의의 정보를 출력합니다
            printf("교수명 : %s\n", course[i].teacher);
            printf("강의실 : %d\n", course[i].room);
            printf("학점 : %d\n", course[i].point);
            for (int k = 0; k < course[i].num; k++) {          //지역변수sum을 선언하고 삭제할 과목의 총 강의시간을 누적시킵니다
                sum += course[i].time[k];
            }
            printf("총 강의시간 : %d (", sum);
            for (int k = 0; k < course[i].num; k++) {         //tableprint함수와 마찬가지로 week[15]를 선언하여 삭제할 강의요일과 강의시간을 출력합니다
                printf("%c%c%d", week[2 * course[i].day[k] + 2 * date[0]], week[2 * course[i].day[k] + 2 * date[0] + 1], course[i].start[k]);
            }
            printf(")\n(삭제 : 1 / 취소 : 2)");
            scanf("%d", &menu);
            if (menu == 1) {
                for (int j = i; j < n - 1; j++) {            //만약에 1을 입력받으면 for문으로 삭제할 과목의 자리에 그다음 과목의 정보를 입력하고
                    course[j] = course[j + 1];               //그다음 과목의 정보에 다다음 과목의 정보를 입력받아서 과목을 삭제하는 방식으로 하였습니다
                }
                for (int j = 0; j < hour2 - hour1 + 1; j++) {
                    for (int k = 0; k < date[1] - date[0] + 1; k++) {           //원소중에 삭제하려는 강의에 해당하는 숫자를 0으로 바꾸고
                        if (*(table + (hour2 - hour1 + 1) * k + j) == i + 1) {  //그 숫자들보다 큰 원소가 존재하면 1을 차감하여줍니다
                            *(table + (hour2 - hour1 + 1) * k + j) = 0;
                        }
                        else if (*(table + (hour2 - hour1 + 1) * k + j) > i + 1) {
                            *(table + (hour2 - hour1 + 1) * k + j) -= 1;
                        }
                    }
                }
                course = (LECTURE*)realloc(course, (n - 1) * sizeof(LECTURE));  //n-1개의 원소만 저장하도록 재할당해줍니다
                n--;
                return -1;      //사용자가 삭제를 승인한 경우, -1을 반환합니다
            }
            else return 1;       //사용자가 삭제를 승인하지 않은 경우, 1을 반환합니다
        }
    }
}

void tablestatus(int* table, LECTURE* course) {              //시간표현황을 표현하는데 과목수가 0이면 시간표가 비었다고 출력합니다
    int sum = 0, sumtime = 0;
    if (n == 0) {
        printf("시간표가 비어있습니다.\n");
    }
    else {
        for (int i = 0; i < n; i++) {
            sum += course[i].point;
            for (int j = 0; j < course[i].num; j++) {      //지역변수sum에 과목마다 학점을 누적하고, sumtime에는 강의시간을 누적하여 출력합니다
                sumtime += course[i].time[j];               //공강시간은 시간표의 원소의 개수에서 누적강의시간을 뺀 값을 출력합니다
            }
        }
        printf("총 과목 : %d과목\n", n);
        printf("총 학점 : %d학점\n", sum);
        printf("총 강의시간 : %d시간 / 공강시간 : %d시간\n", sumtime, (date[1] - date[0] + 1) * (hour2 - hour1 + 1) - sumtime);
    }
}