#include <stdio.h>

int gcm(int a, int b) {
	if (a % b == 0) return b;
	return gcm(b, a % b);
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		int max, min;
		scanf("%d %d", &a, &b);

		max = a > b ? a : b;
		min = a > b ? b : a;

		int num = gcm(max, min);
		printf("%d %d\n", a * b / num, num);
	}

	return 0;
}