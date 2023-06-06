#include <stdio.h>

int main(void) {
	int a, b, n;
	int out = 0;

	scanf("%d %d %d", &a, &b, &n);

	if (a % b == 0) {
		printf("0\n");
		return 0;
	}
	
	if (a > b) a %= b;

	for (int i = 0; i < n; i++) {
		a *= 10;
		out = a / b;
		a %= b;
	}
	printf("%d\n", out);

	return 0;
}