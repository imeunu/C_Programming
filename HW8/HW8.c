#define _CRT_SECURE_NO_WARNINGS               //2015019943 ���а� ������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)                              //����ü�� �޸𸮸� ȿ�������� ����ϱ� ���Ͽ� pragma pack(1)�� �����Ͽ����ϴ�

typedef struct {                            //����ü�� �����, ������, ���ǽ�, ����, �ִ簭��Ƚ��, ���۽ð�, ����, ���ǽð��� LECTURE�� �����Ͽ����ϴ�
    char name[5];
    char teacher[10];
    int room, point, num, * time, * day, * start;
}LECTURE;

int date[2] = { 0,0 }, hour1, hour2, n = 0;    //���������� ���ۿ���, ����������, ���۽ð�, �������ð�, ������ ������ �����Ͽ����ϴ�

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
        printf("�ð�ǥ�� ���� ���ϰ� ������ ������ �Է��ϼ��� : ");              //���ۿ��ϰ� ������������ returnweek�Լ��� ���������� �����޵��� �Ͽ����ϴ�
        scanf("%s", start);
        scanf("%s", end);
        date[0] = returnweek(start);
        date[1] = returnweek(end);
        printf("���۽ð��� ���� �ð��� 24�� ������ �Է����ּ��� : ");           //�ð�ǥ�� �����ֱ� ���Ͽ� �Է¹��� ���ϵ�� �ð���(����)�� ��� 0���� ����ǵ��� �����Ҵ��Ͽ����ϴ�
        scanf("%d %d", &hour1, &hour2);
        if (date[1] - date[0] < 0 || date[1] - date[0]>6) {                 //���ۿ��Ϻ��� ������������ �ռ����, �����޼����� ��쵵�� �Ͽ����ϴ�
            printf("������ �ùٸ��� �Է��� �ּ���\n");                         //��� ����� �Է¹��� ��쿡�� ���� �����ϵ��� �Ͽ����ϴ�
        }
        else if (hour2 < hour1) {
            printf("�ð��� �ùٸ��� �Է��� �ּ���\n");
        }
        else break;
    }
    int* table = (int*)calloc((date[1] - date[0] + 1) * (hour2 - hour1 + 1), sizeof(int));
    while (1) {
        tableprint(table, course);                    //���ѷ����� �����ϰ�, �Ź� �ð�ǥ�� ���� ����ϰ� �޴��� �Է¹޵��� �Ͽ����ϴ�
        printf("\n[�ð�ǥ] 1.�����Է� 2.������� 3.�ð�ǥ��Ȳ 0.����");
        scanf("%d", &menu);
        if (menu == 0)                                //����, n+1��ŭ ���Ҵ����ְ�, ������ ���� n���� ���Ҵ��ϰ�, �ȳ��� �����ϴ� ������ �Ͽ����ϴ�
            break;
        if (menu == 1) {                              //�޴���0�̸� ����, 1�̸� inputlecture�Լ��� �����ŵ�ϴ�
            temp = inputlecture(table);               //�ӽ÷� temp�� input�� ������ �������ݴϴ�
            if (temp.point == -1) {                   //������ -1�̶��, �߰��� ��ҵǾ��ٰ� �޼����� ���ϴ�
                printf("���� �Է��� ��ҵǾ����ϴ�\n");
            }
            else {
                course = (LECTURE*)realloc(course, (n + 1) * sizeof(LECTURE));
                course[n] = temp;
                printf("�߰��Ǿ����ϴ�\n");              //������ -1�� �ƴ϶��, ������ �߻����� ���� ���̹Ƿ� �޼����� ���ϴ�(input�Լ����� �ڼ���)
                n++;                                   //temp�� ����� ������ course�� n��° �迭�� �������ݴϴ�
            }
        }
        else if (menu == 2) {
            menu = deletelecture(course, table);        //deletelecture�� ��ȯ���� -1�̸� ���������� �Ȱ��̹Ƿ� �޼����� ���ϴ�
            if (menu == -1) {
                printf("�����Ǿ����ϴ�.\n");             //menu�� ������ ���� ��� �Է¹��� ���̹Ƿ� ���⿡���� ��Ȱ�� �Ͽ����ϴ�
            }
            else if (menu == 1) {
                printf("������ ��ҵǾ����ϴ�.\n");        //��ȯ���� 1�̸� ���������� ���� ���� ���̹Ƿ� �޼����� ���ϴ�
            }
        }
        else if (menu == 3) {
            tablestatus(table, course);
        }
        else
            printf("�ٽ� �Է����ּ���\n");
    }
    for (int i = 0; i < n; i++) {                       //�����Ҵ��� �Ͽ����Ƿ� ��� free�Լ��� ����Ͽ��ݴϴ�
        free(course[i].day);
        free(course[i].start);
        free(course[i].time);
    }
    free(course);
    free(table);
    return 0;
}

int returnweek(char* day) {              //�Է¹��� ���� ��ȭ��������ϰ� ���Ͽ� ���ۿ���, ������������ ������ ��ȯ���ݴϴ�
    int date;
    if (strcmp(day, "��") == 0)
        date = 0;
    else if (strcmp(day, "ȭ") == 0)
        date = 1;
    else if (strcmp(day, "��") == 0)
        date = 2;
    else if (strcmp(day, "��") == 0)
        date = 3;
    else if (strcmp(day, "��") == 0)
        date = 4;
    else if (strcmp(day, "��") == 0)
        date = 5;
    else if (strcmp(day, "��") == 0)
        date = 6;
    return date;
}

void tableprint(int* table, LECTURE* course) {
    char week[15] = "��ȭ���������";
    for (int a = 0; a < 8 * (date[1] - date[0] + 1) + 4; a++) {  //������ ���̿� ���� ----�� ����ϵ��� �����Ͽ����ϴ�
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 2 * (date[1] - date[0] + 1); i += 2) {   //week[15]�� �����ϰ�, ������ ������ �̸��� ã�Ƽ� ����ϵ��� �Ͽ����ϴ�
        printf("\t%c%c", week[2 * date[0] + i], week[2 * date[0] + i + 1]);
    }
    for (int i = 0; i < hour2 - hour1 + 1; i++) {
        printf("\n");
        for (int a = 0; a < 8 * (date[1] - date[0] + 1) + 4; a++) {
            printf("-");
        }
        printf("\n");
        printf("%02d", hour1 + i);                               //9�ø� 09�ö�� ��µǵ��� �����Ͽ����ϴ�
        for (int j = 0; j < (date[1] - date[0]) + 1; j++) {
            printf("\t");
            for (int k = 0; k < n; k++) {
                if (*(table + (hour2 - hour1 + 1) * j + i) == k + 1) { //���Ұ� 0 �� �ƴϸ� 0���� n���� ���� �ش� ���ҿ� �ش��ϴ� ������� ����մϴ�
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
    LECTURE a;                     //�������� name[20]���� ������� �Է¹ް�, ù �ι��ڰ� �������� �ѱ����� �ν��ϰ� ù �α��ڸ� ��ȯ���ݴϴ�
    char name[20];                 //�Է¹��� LECTURE a�� ���������� �����ϰ�, ������ �Է¹޽��ϴ�
    printf("����� : ");
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
    printf("������ : ");
    scanf("%s", a.teacher);
    printf("���ǽ� : ");
    scanf("%d", &a.room);
    printf("���� : ");
    scanf("%d", &a.point);
    printf("�ִ簭��Ƚ�� : ");
    scanf("%d", &a.num);
    a.time = (int*)calloc(a.num, sizeof(int));   //����ü�� �� ����� �Է¹ް�, �ִ簭�� Ƚ����ŭ ���ǿ���, ���ǽð�, ���۽ð��� �����Ҵ��Ͽ� �Է¹޽��ϴ�
    a.day = (int*)calloc(a.num, sizeof(int));
    a.start = (int*)calloc(a.num, sizeof(int));
    for (int i = 0; i < a.num; i++) {
        printf("\n<����%d>", i + 1);
        printf("���ǿ��� : ");                //�޸𸮸� �Ƴ��� ���Ͽ� �������� name[20]�� �����Ͽ����ϴ�
        scanf("%s", name);
        *(a.day + i) = returnweek(name) - date[0];         //���ǿ����� �ð�ǥ���� ��Ȯ�� ��ġ�� ������ �ϱ� ���Ͽ� ���ۿ����� ���־����ϴ�.
        if (*(a.day + i) > date[1] - date[0] || *(a.day + i) < 0) {       //���� ���ǿ����� ��ȿ�� ������ ���� ���� ���, �����޼����� ����ϰ� �Լ��� �����ŵ�ϴ�
            printf("����### �ش� ���Ͽ� �Է��� �� �����ϴ�.\n"); //������ ���� ���, ������ -1�� �����ϰ� a�� ��ȯ�մϴ�
            a.point = -1;
            free(a.time);
            free(a.day);
            free(a.start);
            return a;
        }
        printf("���۽ð� : ");
        scanf("%d", a.start + i);
        printf("���ǽð� : ");
        scanf("%d", a.time + i);
        for (int j = 0; j < *(a.time + i); j++) {
            if (*(a.start + i) + j > hour2 || *(a.start + i) + j < hour1) {  //���� �Է¹��� ���۽ð����� ���ǽð������� �ð��� ���۽ð����� ������ �ð��� ����� ��� ������ ����մϴ�
                printf("###���� �ش� �ð��� �Է��� �� �����ϴ�.\n");
                a.point = -1;
                free(a.time);
                free(a.day);
                free(a.start);
                return a;
            }
            if (*(table + (hour2 - hour1 + 1) * (*(a.day + i)) + (*(a.start + i)) - hour1 + j) != 0) {
                printf("����### �ش� �ð��� �̹� ������ �����մϴ�.\n");
                a.point = -1;                                //���� �ð�ǥ�� 0�� �ƴ� ������ �ִٸ� ������ �����ϴ� ���̹Ƿ� ������ ����մϴ�
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
    return a; //������ ���� ���� ��쿣 �ش� ������ �ش��ϴ� �ð�ǥ�� �ִ� ���ҵ鿡 n+1�� �������ְ�, ������� 1 ������Ű�� a�� ��ȯ�մϴ�
}

int deletelecture(LECTURE* course, int* table) {
    char name[5];
    int menu, sum = 0;
    char week[15] = "��ȭ���������";
    printf("������ ������� �� �α��ڸ� �Է����ּ��� : ");        //��������name�� �̿��� ������� �յα��ڸ� �Է¹ް� for���� ���� ��ġ�ϴ� ������� ã���ϴ�
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(name, course[i].name) == 0) {
            printf("���� ������ �����Ͻðڽ��ϱ�?\n");           //����ڿ��� Ȯ���� �޴� �޼����� ����ϰ� ������ ������ ����մϴ�
            printf("������ : %s\n", course[i].teacher);
            printf("���ǽ� : %d\n", course[i].room);
            printf("���� : %d\n", course[i].point);
            for (int k = 0; k < course[i].num; k++) {          //��������sum�� �����ϰ� ������ ������ �� ���ǽð��� ������ŵ�ϴ�
                sum += course[i].time[k];
            }
            printf("�� ���ǽð� : %d (", sum);
            for (int k = 0; k < course[i].num; k++) {         //tableprint�Լ��� ���������� week[15]�� �����Ͽ� ������ ���ǿ��ϰ� ���ǽð��� ����մϴ�
                printf("%c%c%d", week[2 * course[i].day[k] + 2 * date[0]], week[2 * course[i].day[k] + 2 * date[0] + 1], course[i].start[k]);
            }
            printf(")\n(���� : 1 / ��� : 2)");
            scanf("%d", &menu);
            if (menu == 1) {
                for (int j = i; j < n - 1; j++) {            //���࿡ 1�� �Է¹����� for������ ������ ������ �ڸ��� �״��� ������ ������ �Է��ϰ�
                    course[j] = course[j + 1];               //�״��� ������ ������ �ٴ��� ������ ������ �Է¹޾Ƽ� ������ �����ϴ� ������� �Ͽ����ϴ�
                }
                for (int j = 0; j < hour2 - hour1 + 1; j++) {
                    for (int k = 0; k < date[1] - date[0] + 1; k++) {           //�����߿� �����Ϸ��� ���ǿ� �ش��ϴ� ���ڸ� 0���� �ٲٰ�
                        if (*(table + (hour2 - hour1 + 1) * k + j) == i + 1) {  //�� ���ڵ麸�� ū ���Ұ� �����ϸ� 1�� �����Ͽ��ݴϴ�
                            *(table + (hour2 - hour1 + 1) * k + j) = 0;
                        }
                        else if (*(table + (hour2 - hour1 + 1) * k + j) > i + 1) {
                            *(table + (hour2 - hour1 + 1) * k + j) -= 1;
                        }
                    }
                }
                course = (LECTURE*)realloc(course, (n - 1) * sizeof(LECTURE));  //n-1���� ���Ҹ� �����ϵ��� ���Ҵ����ݴϴ�
                n--;
                return -1;      //����ڰ� ������ ������ ���, -1�� ��ȯ�մϴ�
            }
            else return 1;       //����ڰ� ������ �������� ���� ���, 1�� ��ȯ�մϴ�
        }
    }
}

void tablestatus(int* table, LECTURE* course) {              //�ð�ǥ��Ȳ�� ǥ���ϴµ� ������� 0�̸� �ð�ǥ�� ����ٰ� ����մϴ�
    int sum = 0, sumtime = 0;
    if (n == 0) {
        printf("�ð�ǥ�� ����ֽ��ϴ�.\n");
    }
    else {
        for (int i = 0; i < n; i++) {
            sum += course[i].point;
            for (int j = 0; j < course[i].num; j++) {      //��������sum�� ���񸶴� ������ �����ϰ�, sumtime���� ���ǽð��� �����Ͽ� ����մϴ�
                sumtime += course[i].time[j];               //�����ð��� �ð�ǥ�� ������ �������� �������ǽð��� �� ���� ����մϴ�
            }
        }
        printf("�� ���� : %d����\n", n);
        printf("�� ���� : %d����\n", sum);
        printf("�� ���ǽð� : %d�ð� / �����ð� : %d�ð�\n", sumtime, (date[1] - date[0] + 1) * (hour2 - hour1 + 1) - sumtime);
    }
}