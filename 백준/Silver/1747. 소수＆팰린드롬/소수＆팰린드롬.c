#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[2250000] = { 0 };

int pin_test(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) return 0;
	}
	return 1;
}

int main(void) {
	int n;
	char str[8] = { 0 };

	scanf("%d", &n);

	for (int i = 2; i < 2250000; i++)
		arr[i] = i;

	for (int i = 2; i < 2250000; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j < 2250000; j += i)
			arr[j] = 0;
	}

	for (int i = 0; i < 2250000; i++) {
		if (arr[i] < n) continue;
		memset(str, 0, 8);
		sprintf(str, "%d", arr[i]);
		if (pin_test(str)) {
			printf("%d", arr[i]);
			return 0;
		}
	}

	return 0;
}