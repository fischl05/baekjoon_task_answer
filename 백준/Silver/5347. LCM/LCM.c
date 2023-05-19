#include <stdio.h>

int gcm(int a, int b) {
	if (a % b == 0) return b;
	else return gcm(b, a % b);
}

long long int lcm(long long int a, long long int b) {
	return a * b / gcm(a, b);
}

int main(void) {
	int a, b, n;
	long long int max, min;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);

		max = a > b ? a : b;
		min = a > b ? b : a;

		printf("%lld\n", lcm(max, min));
	}

	return 0;
}