#include <stdio.h>
#include <math.h>

char str[10];

int len_num(int n) {
	int cnt = 0;
	while (n > 0) {
		n /= 10;
		cnt++;
	}
	return cnt;
}

int main(void) {
	int a, b, c;
	int multi, arr[10] = {0};

	scanf("%d %d %d", &a, &b, &c);

	multi = a * b * c;
	int len = len_num(multi);

	for (int i = 0; i < len; i++) {
		str[i] = (multi % (int)pow(10, i + 1)) / (int)pow(10, i);
		arr[str[i]] += 1;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);

	return 0;
}