#define _CRT_SECURE_NO_WARNINGS   
#include<stdio.h>
#include <string.h>
char scadule[15][5][20] = { "\0\0", "\0\0" ,"\0\0" ,"\0\0" ,"\0\0" };
struct info {

    char** day;
    int* stime, * etime;
    char subject[20], Pname[20];
    int class, grade, freq;
};

void show(char start_d[], char end_d[], int start, int end) { //�⺻������ �Լ�
    int s, e;
    char day[5][3] = { "��","ȭ","��","��","��" };

    for (int i = 0; i < 5; i++) {

        if (strcmp(start_d, day[i]) == 0)
            s = i;
        if (strcmp(end_d, day[i]) == 0)
            e = i;
    }
    printf("----------------------------------------\n");
    for (int i = s; i <= e; i++) {
        printf(" \t%s", day[i]);
    }
    printf("\n");
    printf("----------------------------------------\n");
    for (int i = start; i <= end; i++) {
        printf("%d\n", i);
        printf("----------------------------------------\n");
    }
}

void show2(char start_d[], char end_d[], int start, int end, struct info p) { //�����Է�

    char day[5][3] = { "��","ȭ","��","��","��" };
    int s, e;
    for (int i = 0; i < 5; i++) {
        if (strcmp(start_d, day[i]) == 0)
            s = i;
        if (strcmp(end_d, day[i]) == 0)
            e = i;
    }
    printf("----------------------------------------\n");
    for (int i = s; i <= e; i++) {
        printf("\t %s", day[i]);
    }
    printf("\n");
    printf("----------------------------------------\n");

    int f = 0;
    for (int i = start; i <= end; i++) {
        for (int j = 0; j < p.freq; j++) {
            int ttime = p.stime[j] + p.etime[j] - 1;
            if (p.stime[j] <= i && i <= ttime) {
                for (int k = 0; k < 5; k++) {
                    if (strcmp(p.day[j], day[k]) == 0)
                        strcpy(scadule[f][k], p.subject);
                }
            }
        }
        printf("%d", i);
        for (int j = s; j <= e; j++) {
            printf("\t%c%c%c%c", scadule[f][j][0], scadule[f][j][1], scadule[f][j][2], scadule[f][j][3]);
        }

        printf("\n");
        printf("----------------------------------------\n");

        f++;
    }

}

void drop(char start_d[], char end_d[], int start, int end, struct info p) //�������
{
    char day[5][3] = { "��","ȭ","��","��","��" };
    int s, e;
    for (int i = 0; i < 5; i++) {
        if (strcmp(start_d, day[i]) == 0)
            s = i;
        if (strcmp(end_d, day[i]) == 0)
            e = i;
    }
    printf("----------------------------------------\n");
    for (int i = s; i <= e; i++) {
        printf("\t %s", day[i]);
    }
    printf("\n");
    printf("----------------------------------------\n");

    int f = 0;

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < p.freq; j++) {
            int ttime = p.stime[j] + p.etime[j] - 1;
            if (p.stime[j] <= i && i <= ttime) {
                for (int k = 0; k < 5; k++) {
                    if (strcmp(p.day[j], day[k]) == 0)
                        strcpy(scadule[f][k], "    ");
                }
            }
        }

        printf("%d", i);
        for (int j = s; j <= e; j++) {
            printf("\t%c%c%c%c", scadule[f][j][0], scadule[f][j][1], scadule[f][j][2], scadule[f][j][3]);
        }

        printf("\n");
        printf("----------------------------------------\n");

        f++;
    }
}


int main() {

    int st, et;
    char sd[3], ed[3];
    printf("input your Startday, Endday : ");
    scanf("%s", sd);
    scanf("%s", ed);
    printf("input your Starttime, Endtime : ");
    scanf("%d %d", &st, &et);
    show(sd, ed, st, et);
    struct info inp[8];
    int i = 0, n;
    char c[2];
    while (1)
    {
        printf("[�ð�ǥ] 1. �����Է�  2. �������  3. �ð�ǥ��Ȳ  0. ����\n");
        scanf("%d", &n);
        if (n == 1) {
            gets(c);
            printf("����� : ");
            gets(inp[i].subject);
            printf("������ : ");
            gets(inp[i].Pname);
            printf("���ǽ� : ");
            scanf("%d", &inp[i].class);
            printf("���� : ");
            scanf("%d", &inp[i].class);
            printf("�ִ簭��Ƚ�� : ");
            scanf("%d", &inp[i].freq);
            inp[i].day = (char*)malloc(sizeof(char) * inp[i].freq);
            for (int j = 0; j < inp[i].freq; j++)
                inp[i].day[j] = (char*)malloc(sizeof(char) * 3);
            inp[i].stime = (int*)malloc(sizeof(char) * inp[i].freq);
            inp[i].etime = (int*)malloc(sizeof(char) * inp[i].freq);

            for (int k = 0; k < inp[i].freq; k++) {
                gets(c);
                printf("<����%d>\n", k + 1);
                printf("���ǿ��� : ");
                gets(inp[i].day[k]);
                printf("���۽ð� : ");
                scanf_s("%d", &inp[i].stime[k]);
                printf("���ǽð� : ");
                scanf_s("%d", &inp[i].etime[k]);
            }

            show2(sd, ed, st, et, inp[i]);
            i++;
        }
        if (n == 2) {
            char sn[20];
            gets(c);
            printf("�����: ");
            gets(sn);
            for (int j = 0; j < i; j++) {

                if (strcmp(inp[j].subject, sn) == 0) {

                    drop(sd, ed, st, et, inp[j]);
                    for (int k = j; k < i - 1; k++)
                        inp[k] = inp[k + 1];
                    break;
                }
            }
            i--;
        }
    }
}