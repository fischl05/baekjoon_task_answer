#include <stdio.h>

int gcm(int a, int b) {
	if (a % b == 0) return b;
	return gcm(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcm(a, b);
}

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int min = 0, max = 0;
		int a, b;
		scanf("%d %d", &a, &b);
		min = a > b ? b : a;
		max = a > b ? a : b;
		
		printf("%d\n", lcm(max, min));
	}

	return 0;
}