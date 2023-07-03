#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main(void) {
	char str1[5] = { 0 }, str2[5] = { 0 };
	int num1 = 0, num2 = 0;

	scanf("%s %s", str1, str2);

	reverse(str1);
	reverse(str2);
	
	num1 = atoi(str1);
	num2 = atoi(str2);

	num1 += num2;

	sprintf(str1, "%d", num1);
	reverse(str1);

	printf("%d", atoi(str1));

	return 0;
}