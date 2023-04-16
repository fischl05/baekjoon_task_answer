#define _CRT_SECURE_NO_WARING
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[51];
	int minus = 0, sum = 0, temp = 0, num = 0;

	memset(string, 0, 51);

	scanf("%s", string);
	
	int len = strlen(string);

	for (int i = 0; i < len + 1; i++) {
		temp = 0;
		if (string[i] >= '0' && string[i] <= '9') {
			temp = string[i] - '0';
			num = num * 10 + temp;
		}

		else if (string[i] == '-' && minus == 0) {
			minus = 1;
			sum += num;
			num = 0;
		}

		else if (minus == 0) {
			sum += num;
			num = 0;
		}
		else {
			sum -= num;
			num = 0;
		}
	}
	printf("%d", sum);

	return 0;
}