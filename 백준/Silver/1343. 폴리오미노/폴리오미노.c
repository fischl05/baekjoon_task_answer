#include <stdio.h>
#include <string.h>

int main(void) {
	char str[51] = { 0 };
	int len = 0;

	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len; i++) {
		int cnt = 0, num = 0;
		while (str[i + cnt] == 'X')
			cnt++;
		num = cnt;
		i += cnt;

		if (cnt % 2 != 0) {
			printf("-1");
			return 0;
		}

		while (cnt > 0) {
			if (cnt > 2 || num % 4 == 0) str[i - cnt] = 'A';
			else str[i - cnt] = 'B';
			cnt--;
		}
	}
	printf("%s", str);

	return 0;
}