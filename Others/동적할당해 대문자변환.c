#define _CRT_SECURE_NO_WARNINGS             //2015019943 ���а� ������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toUpper(char* input) {
	char* str = malloc(1 + strlen(input));
	for (int i = 0; i <= strlen(input); i++) {
		if (*(input+i) >= 'a' && *(input+i) <= 'z') {
			*(str + i) = *(input + i) + 65 - 97;
		}
		else {
			*(str + i) = *(input + i);
		}
	}
	return str;
}

int main() {
	char input[80];
	char* output;
	gets(input);
	output = toUpper(input);
	printf("���� : %s\n", input);
	printf("�빮�� : %s", output);

	free(output);
	return 0;
}