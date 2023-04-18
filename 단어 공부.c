#include <stdio.h>
#include <string.h>

int arr[26];

int main(void) {
	char str[1000001] = {0};
	int idx = 0, max = 0;

	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') arr[str[i] - 'A'] += 1;
		else if (str[i] >= 'a' && str[i] <= 'z') arr[str[i] - 'a'] += 1;
	}
	for (int i = 0; i < 26; i++)
		if (arr[i] > max) {
			max = arr[i];
			idx = i;
		}

	for (int i = 0; i < 26; i++) {
		if (arr[i] != 0) {
			if (max == arr[i] && idx != i) {
				printf("?\n");
				return 0;
			}
		}
	}
	printf("%c\n", idx + 'A');

	return 0;
}