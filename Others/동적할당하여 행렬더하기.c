#define _CRT_SECURE_NO_WARNINGS             //2015019943 수학과 임은우
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toUpper(char* input) {
	char* str = malloc(strlen(input));
	for (int i = 0; i < strlen(input); i++) {
		if (*input >= 'A' && *input <= 'z') {
			*input += 65 - 97;
		}
	}
}

int main() {
	char input[80];
	char* output;
	gets(input);
	output = toUpper(input);
	printf("%s", output);

	free(output);
	return 0;
}