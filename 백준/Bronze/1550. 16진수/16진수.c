#include <stdio.h>
#include <math.h>
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
	char str[7] = { 0 };
	int len = 0, out = 0;

	scanf("%s", str);
	reverse(str);

	len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == 'A') out += 10 * pow(16, i);
		else if (str[i] == 'B')	out += 11 * pow(16, i);
		else if (str[i] == 'C') out += 12 * pow(16, i);
		else if (str[i] == 'D')	out += 13 * pow(16, i);
		else if (str[i] == 'E') out += 14 * pow(16, i);
		else if (str[i] == 'F') out += 15 * pow(16, i);
		else out += (str[i] - '0') * pow(16, i);
	}
	printf("%d\n", out);

	return 0;
}