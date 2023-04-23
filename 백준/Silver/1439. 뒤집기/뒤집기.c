#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000001] = { 0 };
	int len = 0, check[2] = { 0 };

	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len; i++) {
		int cnt = 0;
		if (str[i] == '0') {
			while (str[i + cnt] == '0') cnt++;
			check[0] += 1;
		}
		else {
			while (str[i + cnt] == '1') cnt++;
			check[1] += 1;
		}
		i += cnt - 1;
		cnt = 0;
	}
	printf("%d", check[0] < check[1] ? check[0] : check[1]);

	return 0;
}