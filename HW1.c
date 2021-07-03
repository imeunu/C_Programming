#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char cipher[211] = "ozwfqgmjwsllzwwfvgxlzwjgsvsfvqgmdgklsddkwfkwgxugfljgdsfvqgmjlzgmyzlkzsnwlscwflzwajlgddozwfqgmjeafvtjwscklzwkhajalgxqgmjkgmdqgmjxsalzosdckgftjgcwfydskksfvlzwzsfygnwjvgwkflhskkfglzafykwnwjtmadllgdsklqgmjwafjmafk";
	char buffer[211];
	int k;
	printf("key : ");
	scanf("%d", &k);
	printf("\nkey : %d\nplain text\n\n", k);
	atoi(cipher);
	for (int i = 0; i < 210; i++) {
		cipher[i] -= 97;
		cipher[i] += k;
		cipher[i] = cipher[i] % 26;
		cipher[i] += 97;
	}
	printf("%s", cipher);
}