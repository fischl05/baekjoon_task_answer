#include <stdio.h>
#include <string.h>

int main(void) {
	char str[8] = { 0 };
	int len, max = 0, arr[9] = { 0 };

	scanf("%s", str);

	len = strlen(str);

	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] != '9' && str[i] != '6') arr[str[i] - '0'] += 1;
		else {
			cnt++;
			if (cnt >= 2) {
				arr[6]++;
				cnt = 0;
			}
		}
	}
	if (cnt > 0) arr[6]++;

	for (int i = 0; i < 9; i++)
		if (arr[i] > max) max = arr[i];

	printf("%d", max);

	return 0;
}